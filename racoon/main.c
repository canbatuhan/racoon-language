#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <stdbool.h>

#include "src/include/lexer.h"

#define MAX_SIZE 256
#define NULL_CHAR -1
#define NEW_LINE '\n'

int main() {
    token* tokens = NULL;
    char* input_text = (char*) malloc(sizeof(char)*MAX_SIZE);

    while (true) {
        printf("racoon >> ");
        fgets(input_text, MAX_SIZE, stdin);
        lexer lexer = init_lexer(input_text);
        tokens = extract_tokens(&lexer);
        if (tokens == NULL) {
            break;
        }
    }

    return EXIT_SUCCESS;
}
