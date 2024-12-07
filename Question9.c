#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int main() {
    FILE *out = fopen("output.txt", "w");
        if (out == NULL) {
            printf("Can't open output.txt\n");
        }

    double num;
    printf("Enter a stream of real numbers within the range 0 to 100. To finish, input a non-number character, and anything after that will be ignored.\n");
    while (scanf("%lf", &num) == 1) {
        if (num < 0 || num > 100) {
            printf("%lf is an invalid input and has been ignored\n", num);
        } else {
            fprintf(out, "%lf\n", num);
        }
    }

    printf("Output saved to output.txt");
    fclose(out);
    return 0;

}
