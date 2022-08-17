#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "src/include/lexer.h"
#include "src/include/error.h"

#define MAX_SIZE 256

int run();

int main() {
    run();
}

int run() {
    lexer lexer;
    token* token_arr;
    char* input_text = (char*) malloc(sizeof(char)*MAX_SIZE);

    while (true) {
        printf("racoon > ");
        fgets(input_text, MAX_SIZE, stdin);

        lexer = init_lexer(input_text);
        token_arr = generate_tokens(&lexer);

        if (token_arr == NULL) {
            repr_error(init_error(INVALID_CHAR_ERR, INVALID_CHAR_ERR_DETAIL));
        }
    }

    return EXIT_SUCCESS;
}