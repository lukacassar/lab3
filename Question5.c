#include <stdio.h>

int main() {
    int n = 20;
    double input, lastInput = 0;
    double arr[n];

    printf("Enter %d ascending order numbers between 1 and 100\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &input);
        if ((input < 1 || input > 100) || input < lastInput) {
            printf("Invalid Input\n");
            i--;
        } else {
            arr[i] = input;
            lastInput = input;
        }
    }

    // Mean
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    double average = sum / n;
    printf("Mean = %lf\n", average);

    // Mode (definitely overcomplicated but it works :D)
    double frequency[n];
    for (int i = 0; i < n; i++) {
        frequency[i] = 0;
    }


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i] == arr[j]) {
                frequency[i]++;
            }
        }
    }

    int maxFrequency = 0;
    int sameFreq[n];
    int a = 0;
    for (int i = 0; i < n; i++) {
        if (frequency[i] > maxFrequency) {
            maxFrequency = frequency[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if(frequency[i] == maxFrequency) {
            sameFreq[a] = i;
            a++;

        }
    }
    double printFreq[a];
    for (int i = 0; i < a; i++) {
        printFreq[i] = arr[sameFreq[i]];
    }

    double finalArr[a];
    for(int i = 0; i < a; i++) {
        finalArr[i] = printFreq[i];
    }

    double temp;
    for(int i = 0; i < a; i++) {
        for(int j = 0; j < a; j++) {
            if(finalArr[i] < finalArr[j]) {
                temp = finalArr[i];
                finalArr[i] = finalArr[j];
                finalArr[j] = temp;
            }
        }
    }
    double printer;
    double original = finalArr[0];

    printf("Mode frequency is %d\n", maxFrequency);
    printf("Mode: %lf\n", original);
    for(int i = 0; i < a; i++) {
        printer = finalArr[i];
        if (printer != original && i != 0) {
            printf("Mode: %lf\n", finalArr[i]);
            original = printer;
        }
    }

    // Median
    double sortedArr[20];
    for(int i = 0; i < n; i++) {
        sortedArr[i] = arr[i];
    }
    double sortTemp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(sortedArr[i] > sortedArr[j]) {
                sortTemp = sortedArr[i];
                sortedArr[i] = sortedArr[j];
                sortedArr[j] = sortTemp;
            }
        }
    }

    int half;
    double median;
    if(n % 2 == 0) {
        half = n / 2;
        median = (sortedArr[half] + sortedArr[half - 1]) / 2;
        printf("Median = %lf\n", median);
    } else {
        half = (n-1) / 2;
        median = sortedArr[half];
        printf("Median = %lf\n", median);
    }

    return 0;
}

