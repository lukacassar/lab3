#include <stdio.h>
#include <string.h>
#include <stdlib.h>
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
    int errors = 0;

    
    while (fscanf(src, "%s", input) != EOF) {
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

       
        int hasCapital = 0, x = 0;
        int poses[len];
        for (int i = 1; i < len; i++) {
            if (input[i] >= 'A' && input[i] <= 'Z') {
                hasCapital = 1;
                poses[x] = i + 1;
                x++;
            }
        }

   
        int err = 0;
        if (len > 10 && hasHyphen == 0) {
            printf("Word %s is longer than 10 characters and has no hyphen\n", input);
            err++;
        }
        if (hasCapital == 1) {
            for (int i = 0; i < x; i++) {
                printf("Word %s has a capital letter at letter position/s %d\n", input, poses[i]);
                err++;
            }
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

   
    if (fp != NULL) {
        fclose(fp);
    }

    return 0;
}
