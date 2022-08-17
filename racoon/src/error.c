#include <stdio.h>
#include "include/error.h"

error init_error(char* name, char* details) {
    error new_error;
    new_error.name = name;
    new_error.details = details;
    return new_error;
}

void repr_error(error error) {
    printf("%s: %s", error.name, error.details);
}