#include <stdio.h>
#include "token.h"

#ifndef LEXER_H
#define LEXER_H

typedef struct lexer {
    char* text;
    int position;
    char current_char;
} lexer;

lexer init_lexer(char*);
void advance_lexer(lexer*);
token* generate_tokens(lexer*);
token token_with_value(lexer*);

#endif