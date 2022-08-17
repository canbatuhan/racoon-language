#include <stdio.h>
#include "include/token.h"

token init_token(char* type, char* value) {
    token new_token;
    new_token.type = type;
    new_token.value_as_string = value;
    return new_token;
}

void repr_token(token token) {
    if (token.value_as_string != NULL) {
        printf("%s:%s ", token.type, token.value_as_string);
    } else {
        printf("%s ", token.type);
    }
}