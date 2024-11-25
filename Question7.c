#include <stdio.h>
#include <string.h>
#define MAX 500

int main() {
    printf("Input a stream of text. Type 'exit' to terminate, either by itself or as the last word - anything beyond 'exit' will be ignored in this case\n");

    char input[MAX];
    int errors = 0;

    while (scanf("%s", input) != EOF) {
        if (strcmp(input, "exit") == 0) {
            break;
        }

        int len = strlen(input);

        int hasHyphen = 0;
        for (int i = 0; i < len; i++) {
            if (input[i] == '-') {
                hasHyphen = 1;
                break;
            }
        }

        int pos, hasCapital = 0;
        for (int i = 1; i < len; i++) {
            if (input[i] >= 'A' && input[i] <= 'Z') {
                hasCapital = 1;
                pos = i + 1;
                break;
            }
        }

        int err = 0;
        if (len > 10 && hasHyphen == 0) {
            printf("Word %s is longer than 10 characters and has no hyphen\n", input);
            err++;
        }
        if (hasCapital == 1) {
            printf("Word %s has a capital letter at letter position %d\n", input, pos);
            err++;
        }
        if (input[0] < 'A' || (input[0] > 'Z' && input[0] < 'a') || input[0] > 'z') {
            printf("Word %s does not start with an alphabetical letter\n", input);
            err++;
        }

        errors += err;
    }

    if (errors == 0) {
        printf("No errors found\n");
    } else if (errors == 1) {
        printf("1 error found\n");
    } else {
        printf("%d errors found\n", errors);
    }

    return 0;
}
