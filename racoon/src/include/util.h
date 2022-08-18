#include <stdio.h>
#include <stdbool.h>

#define NULL_CHAR -1
#define NEW_LINE '\n'

int string_length(const char* string) {
    int length;
    for (length=0; string[length]!='\0'; ++length) {}
    return length;
}

bool char_in_string(char target, char* string) {
    for (int idx=0; string[idx]!='\0'; idx++) {
        if (target == string[idx]) {
            return true;
        }
    }
    return false;
}

bool traverse_condition(char current_char) {
    return current_char != NULL_CHAR && current_char != NEW_LINE;
}
