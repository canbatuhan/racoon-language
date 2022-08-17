#include <stdio.h>

#ifndef ERROR_H
#define ERROR_H

#define INVALID_CHAR_ERR "InvalidCharacterError"
#define INVALID_CHAR_ERR_DETAIL "There is an invalid character in the expression."

typedef struct error {
    char* name;
    char* details;
} error;

error init_error(char*, char*);
void repr_error(error);

#endif
