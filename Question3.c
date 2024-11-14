#include <stdio.h>

int main(void)
{
    int PIN = 9999;
    int entry;
    printf("PIN is %d \n", PIN);
    int n = 5;

    while(n!=0) {
    printf("Enter PIN\n");
        scanf("%d",&entry);
        if(entry != PIN) {
            printf("Wrong PIN\n");
            n--;
        } else {
            printf("Thank you for using this program\n");
            return 0;
        }
    }
    if (n == 0) {
        printf("You have been locked out");
    }

    return 0;
}
