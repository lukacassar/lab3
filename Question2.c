#include <stdio.h>

int main(void)
{
    printf("Enter a number to compute its factorial\n");
    int num;
    scanf("%d", &num);
    int original = num;
    int factorial = 1;

    if(num < 0) {
        printf("Cannot take factorial of a negative");
        return 0;
    }
    for(int i = num; i>0; i--) {
        factorial = factorial * i;
    }
        printf("the factorial of %d is %d", original, factorial);


    return 0;
}
