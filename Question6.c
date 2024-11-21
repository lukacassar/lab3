#include <stdio.h>


int main() {
    double income, tax = 0;
    double firstBracket = 10000, secondBracket = 18000;
    int workICT, collect;

    printf("Enter Income: \n");
    scanf("%lf", &income);

    printf("Do you work in the ICT Industry? Type 1 if yes, any other integer if no.\n");
    scanf("%d", &workICT);

    printf("Do you collect old electronic equipment for green disposal? Type 1 if yes, any other integer if no\n");
    scanf("%d", &collect);

    if (collect == 1) {
        firstBracket = 15000;
        secondBracket += 8000;
    }

    if (income <= firstBracket) {
        tax = income * 0.18;
    } else if (income <= secondBracket) {
        tax = (firstBracket * 0.18) + ((income - firstBracket) * 0.20);
    } else if (income > secondBracket) {
        tax = (firstBracket * 0.18) + ((secondBracket - firstBracket) * 0.20) + ((income - secondBracket) * 0.25);
    }

    if (workICT == 1) {
        tax = tax - (tax * 0.05);
    }

    printf("Tax: €%.2f\n", tax);
    return 0;
}
