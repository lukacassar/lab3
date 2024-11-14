#include <stdio.h>

int main() {
    double arr[20];

    int n=0;
    while(n<20) {
        printf("Enter 20 numbers\n");
        scanf("%lf",&arr[n]);
        n++;
    }

    printf("Computing the mean\n");
    double sum = 0;
    for(int i = 0; i <=19; i++) {
        sum = sum + arr[i];
    }
    double average = sum / 20;
    printf("Mean = %lf\n",average);

    printf("Computing the mode\n");
    double mode[20];
    int k = 0;
    for (int i = 0; i <=19; i++) {
        for (int j = 0; j <=19; j++) {
            if(arr[i] == arr[j]) {
                k++;
            }
        }
        mode[i]=k;
        k=0;
    }
    int highest = 0;
    for(int i = 0; i <=19; i++) {
        if(mode[i] > mode[i+1]) {
            highest = i;
        }
        if(mode[i] == mode[i+1]) {
    }
    return 0;
}
