#include <stdio.h>
#include <string.h>
#include "include/lexer.h"

#define NULL_CHAR -1

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
    if (lexer_ptr->position < strlen(lexer_ptr->text)) {
        lexer_ptr->current_char = lexer_ptr->text[lexer_ptr->position];
    } else {
        lexer_ptr->current_char = NULL_CHAR;
    }
}

token* generate_tokens(lexer* lexer_ptr) {
    int arr_size = 0;
    token* token_arr = (token*) malloc(sizeof(token)*arr_size);

    while (lexer_ptr->current_char != NULL_CHAR) {
        if (strchr(SPACES, lexer_ptr->current_char)) {
            advance_lexer(lexer_ptr);
            continue;
        } else if (strchr(DIGITS, lexer_ptr->current_char)) {
            arr_size++;
            token_arr = realloc(token_arr, sizeof(token)*arr_size);
            token_arr[arr_size-1] = token_with_value(lexer_ptr);
        } else if (lexer_ptr->current_char = '+') {
            arr_size++;
            token_arr = realloc(token_arr, sizeof(token)*arr_size);
            token_arr[arr_size-1] = init_token(TOKEN_TYPE_PLUS, NULL);
        } else if (lexer_ptr->current_char = '-') {
            arr_size++;
            token_arr = realloc(token_arr, sizeof(token)*arr_size);
            token_arr[arr_size-1] = init_token(TOKEN_TYPE_MINUS, NULL);
        } else if (lexer_ptr->current_char = '*') {
            arr_size++;
            token_arr = realloc(token_arr, sizeof(token)*arr_size);
            token_arr[arr_size-1] = init_token(TOKEN_TYPE_MUL, NULL);
        } else if (lexer_ptr->current_char = '/') {
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