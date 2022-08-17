#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 256

int main() {
    char* input_text = (char*) malloc(sizeof(char)*MAX_SIZE);

    while (true) {
        printf("racoon > ");
        scanf("%s", input_text);
    }
}