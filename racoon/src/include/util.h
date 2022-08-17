#include <stdio.h>

int string_length(const char* string) {
    int length;
    for (length=0; string[length]!='\0'; ++length) {}
    return length;
}