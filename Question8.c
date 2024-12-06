#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 500

int main(int argc, char *argv[]) {
    FILE *fp = NULL;
    FILE *src = stdin;

    if (argc == 2) {
        if ((fp = fopen(argv[1], "r")) == NULL) {
            printf("Error: Can't open file %s\n", argv[1]);
            exit(1);
        }
        src = fp;
    } else {
        printf("Input a stream of text. Type 'exit' to terminate, either by itself or as the last word - anything beyond 'exit' will be ignored in this case\n");
    }

    char input[MAX];
    int errors = 0, err = 0;
    int len;

    while (fgets(input, MAX, src) != NULL) {
        input[strcspn(input, "\n")] = '\0';

        if (strncmp(input, "exit", 4) == 0) {
            break;
        }

        len = strlen(input);
        err = 0;

        for (int i = 1; i < len; i++) {
            if (isspace(input[i - 1]) && ispunct(input[i])) {
                printf("There is a punctuation '%c' preceded by a space at position %d\n", input[i], i);
                err++;
            }
            if (isspace(input[i - 1]) && isspace(input[i])) {
                printf("There is a double space at positions %d and %d\n", i, i+1);
                err++;
            }
        }

        errors += err;

        char *word = strtok(input, " ");
        while (word != NULL) {
            if (strcmp(word, "exit") == 0) {
                break;
            }

            len = strlen(word);
            err = 0;

            int hasHyphen = 0;
            for (int i = 0; i < len; i++) {
                if (word[i] == '-') {
                    hasHyphen = 1;
                    break;
                }
            }

            int hasCapital = 0, x = 0;
            int poses[len];
            for (int i = 1; i < len; i++) {
                if (word[i] >= 'A' && word[i] <= 'Z') {
                    hasCapital = 1;
                    poses[x] = i + 1;
                    x++;
                }
            }

            if (len > 10 && hasHyphen == 0) {
                printf("Word %s is longer than 10 characters and has no hyphen\n", word);
                err++;
            }
            if (hasCapital == 1) {
                for (int i = 0; i < x; i++) {
                    printf("Word %s has a capital letter at letter position/s %d\n", word, poses[i]);
                    err++;
                }
            }
            if (word[0] < 'A' || (word[0] > 'Z' && word[0] < 'a') || word[0] > 'z') {
                printf("Word %s does not start with an alphabetical letter. This may be a punctuation preceded by a space and will not be counted as an error.\n", word);
            }

            errors += err;

            word = strtok(NULL, " ");
        }
    }

    if (errors == 0) {
        printf("No errors found\n");
    } else if (errors == 1) {
        printf("1 error found\n");
    } else {
        printf("%d errors found\n", errors);
    }

    if (fp != NULL) {
        fclose(fp);
    }

    return 0;
}
