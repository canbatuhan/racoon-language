#include <stdlib.h>
#include <string.h>
#include "include/lexer.h"
#include "include/util.h"

#define MAX_SIZE 256

lexer init_lexer(char* text) {
    lexer new_lexer;
    new_lexer.text = text;
    new_lexer.position = 0;
    new_lexer.current_char = new_lexer.text[new_lexer.position];
    return new_lexer;
}

void move_to_next_char(lexer* lexer_ptr) {
    lexer_ptr->position++;
    if (lexer_ptr->position < string_length(lexer_ptr->text)) {
        lexer_ptr->current_char = lexer_ptr->text[lexer_ptr->position];
    } else {
        lexer_ptr->current_char = NULL_CHAR;
    }
}

token* extract_tokens(lexer* lexer_ptr) {
    token* tokens = (token*) malloc(sizeof(token)*0);
    int size = 0;

    while (traverse_condition(lexer_ptr->current_char)) {
        if (char_in_string(lexer_ptr->current_char, SPACES)) {
            move_to_next_char(lexer_ptr);
            continue;
        } else if (char_in_string(lexer_ptr->current_char, DIGITS)) {
            tokens = realloc(tokens, sizeof(token)*++size);
            tokens[size-1] = token_with_value(lexer_ptr);
            if (tokens[size-1].type == NULL) {
                return NULL;
            } else {
                continue;
            }
        } else if (lexer_ptr->current_char == '+') {
            tokens = realloc(tokens, sizeof(token)*++size);
            tokens[size-1] = init_token(TOKEN_TYPE_PLUS, NULL);
        } else if (lexer_ptr->current_char == '-') {
            tokens = realloc(tokens, sizeof(token)*++size);
            tokens[size-1] = init_token(TOKEN_TYPE_MINUS, NULL);
        } else if (lexer_ptr->current_char == '*') {
            tokens = realloc(tokens, sizeof(token)*++size);
            tokens[size-1] = init_token(TOKEN_TYPE_MUL, NULL);
        } else if (lexer_ptr->current_char == '/') {
            tokens = realloc(tokens, sizeof(token)*++size);
            tokens[size-1] = init_token(TOKEN_TYPE_DIV, NULL);
        } else if (lexer_ptr->current_char == '(') {
            tokens = realloc(tokens, sizeof(token)*++size);
            tokens[size-1] = init_token(TOKEN_TYPE_LPAREN, NULL);
        } else if (lexer_ptr->current_char == ')') {
            tokens = realloc(tokens, sizeof(token)*++size);
            tokens[size-1] = init_token(TOKEN_TYPE_RPAREN, NULL);
        } else {
            return NULL;
        }

        move_to_next_char(lexer_ptr);
    }

    for (int idx=0; idx<size; idx++) {
        printf("%s:%s ", tokens[idx].type, tokens[idx].value);
    } printf("\n");

    return tokens;
}

token token_with_value(lexer* lexer_ptr) {
    char* value = (char* ) malloc(sizeof(char)*0);
    int size = 0;
    int dot_count = 0;

    while (traverse_condition(lexer_ptr->current_char) && char_in_string(lexer_ptr->current_char, DIGITS)) {
        if (lexer_ptr->current_char == '.') {
            if (dot_count == 1) {
                return init_token(NULL, NULL);
            } else {
                value = realloc(value, sizeof(token)*++size);
                value[size-1] = '.';
                dot_count++;
            }
        } else {
            value = realloc(value, sizeof(token)*++size);
            value[size-1] = lexer_ptr->current_char; 
        }

        move_to_next_char(lexer_ptr);
    }

    value = realloc(value, sizeof(token)*++size);
    value[size-1] = '\0'; 

    if (dot_count == 0) {
        return init_token(TOKEN_TYPE_INT, value);
    } else {
        return init_token(TOKEN_TYPE_FLOAT, value);
    }
}
