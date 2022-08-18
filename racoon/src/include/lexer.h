#include <stdio.h>
#include "token.h"

#ifndef LEXER_H
#define LEXER_H

/**
 * @brief Lexer reads texts and extract tokens from it
 * @param text : char* - input text (code)
 * @param position : int - position in text
 * @param current_char : char - char to be examined
 */
typedef struct lexer {
    char* text; int position;
    char current_char;
} lexer;

lexer init_lexer(char*);
void move_to_next_char(lexer*);
token* extract_tokens(lexer*);
token token_with_value(lexer*);

#endif