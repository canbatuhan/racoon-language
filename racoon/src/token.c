#include <stdio.h>
#include "include/token.h"

token init_token(char* type, char* value) {
    token new_token;
    new_token.type = type;
    new_token.value = value;
    return new_token;
}