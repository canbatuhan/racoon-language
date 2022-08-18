#include <stdio.h>

#ifndef TOKEN_H
#define TOKEN_H

#define TOKEN_TYPE_PLUS     "+"
#define TOKEN_TYPE_MINUS    "-"
#define TOKEN_TYPE_MUL      "*"
#define TOKEN_TYPE_DIV      "/"
#define TOKEN_TYPE_LPAREN   "("
#define TOKEN_TYPE_RPAREN   ")"
#define TOKEN_TYPE_INT      "int"
#define TOKEN_TYPE_FLOAT    "float"

#define SPACES              " "
#define DIGITS              ".0123456789"

typedef struct token {
    char* type;
    char* value;
} token;

token init_token(char*, char*);
void repr_token(token);

#endif