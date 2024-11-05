#include <stdio.h>

int main(void)
{
    long num = 0;
    long sum = 0L; /* initialize sum to zero */
    int status = 1;

    while (status == 1)
    {
        sum = sum + num;
        printf("Please enter next integer (q to quit): ");
        status = scanf("%ld", &num);
    }
    printf("Those integers sum to %ld.\n", sum);

    return 0;
}
