#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "include/lexer.h"
#include "include/util.h"

#define NULL_CHAR -1
#define MAX_SIZE 256

lexer init_lexer(char* text) {
    lexer new_lexer;
    new_lexer.text = text;
    new_lexer.position = -1;
    new_lexer.current_char = NULL_CHAR;
    advance_lexer(&new_lexer);
    return new_lexer;
}

void advance_lexer(lexer* lexer_ptr) {
    lexer_ptr->position++;
    if (lexer_ptr->position < string_length(lexer_ptr->text)) {
        lexer_ptr->current_char = lexer_ptr->text[lexer_ptr->position];
    } else {
        lexer_ptr->current_char = NULL_CHAR;
    }
}

token* generate_tokens(lexer* lexer_ptr) {
    int arr_size = 0;
    token* token_arr = (token*) malloc(sizeof(token)*arr_size);

    while (lexer_ptr->current_char != NULL_CHAR) {
        if (strchr(SPACES, lexer_ptr->current_char) != NULL) {
            advance_lexer(lexer_ptr);
            continue;
        } else if (strchr(DIGITS, lexer_ptr->current_char) != NULL) {
            arr_size++;
            token_arr = realloc(token_arr, sizeof(token)*arr_size);
            token_arr[arr_size-1] = token_with_value(lexer_ptr);
            if (token_arr[arr_size-1].type == NULL) {
                return NULL;
            }
        } else if (lexer_ptr->current_char == '+') {
            arr_size++;
            token_arr = realloc(token_arr, sizeof(token)*arr_size);
            token_arr[arr_size-1] = init_token(TOKEN_TYPE_PLUS, NULL);
        } else if (lexer_ptr->current_char == '-') {
            arr_size++;
            token_arr = realloc(token_arr, sizeof(token)*arr_size);
            token_arr[arr_size-1] = init_token(TOKEN_TYPE_MINUS, NULL);
        } else if (lexer_ptr->current_char == '*') {
            arr_size++;
            token_arr = realloc(token_arr, sizeof(token)*arr_size);
            token_arr[arr_size-1] = init_token(TOKEN_TYPE_MUL, NULL);
        } else if (lexer_ptr->current_char == '/') {
            arr_size++;
            token_arr = realloc(token_arr, sizeof(token)*arr_size);
            token_arr[arr_size-1] = init_token(TOKEN_TYPE_DIV, NULL);
        } else {
            return NULL;
        }

        advance_lexer(lexer_ptr);
    }

    return token_arr;
}

token token_with_value(lexer* lexer_ptr) {
    char* value_as_string = (char* ) malloc(sizeof(char)*MAX_SIZE);
    int dot_count = 0;

    while (lexer_ptr->current_char != NULL_CHAR && strchr(DIGITS, lexer_ptr->current_char) != NULL) {
        if (lexer_ptr->current_char == '.') {
            if (dot_count == 1) {
                return init_token(NULL, NULL);
            } else {
                dot_count++;
                strcat(value_as_string, ".");
            }
        } else {
            strcat(value_as_string, &(lexer_ptr->current_char)); 
        }

        advance_lexer(lexer_ptr);
    }

    if (dot_count == 0) {
        return init_token(TOKEN_TYPE_INT, value_as_string);
    } else {
        return init_token(TOKEN_TYPE_FLOAT, value_as_string);
    }
}