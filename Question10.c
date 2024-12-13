#include <stdio.h>
void clr() {
    while (getchar() != '\n');
}

int main() {
    int quantity[5] = {0};
    double total = 0;
    while (1) {
        printf("1. Add items to shopping cart\n");
        printf("2. Show current total\n");
        printf("3. Check out\n");
        printf("4. Cancel session\n");
        printf("q. Quit\n");

        char choice;
        scanf(" %c", &choice);
        clr();

        double apples = 0.50, bananas = 0.80, oranges = 0.70, milk = 1.30, eggs = 2.10;
        switch (choice) {
            case '1': {
                printf("Available items:\n");
                printf("Code    Name             Price\n");
                printf("1    Apples          $%lf\n", apples);
                printf("2    Bananas         $%lf\n", bananas);
                printf("3    Oranges         $%lf\n", oranges);
                printf("4    Milk            $%lf\n", milk);
                printf("5    Eggs            $%lf\n", eggs);

                int opt, qty=0;

                printf("Choose an option:\n");
                scanf("%d", &opt);

                if (opt >= 1 && opt <= 5) {
                    printf("Enter quantity below 100\n");
                    scanf("%d", &qty);
                    quantity[opt-1] += qty;

                    if (quantity[opt-1] >= 0 && quantity[opt-1] <= 100) {
                        switch (opt) {
                            case 1:
                                total += apples * qty;
                            break;
                            case 2:
                                total += bananas * qty;
                            break;
                            case 3:
                                total += oranges * qty;
                            break;
                            case 4:
                                total += milk * qty;
                            break;
                            case 5:
                                total += eggs * qty;
                            break;
                        }
                    } else {
                        printf("Invalid quantity\n");
                    }
                    printf("Item added to cart\n");
                } else {
                    printf("Invalid option.\n");
                }
                break;
            }
            case '2': {
                printf("Current total: $%.2lf\n", total);
                break;
            }
            case '3': {
                printf("You purchased:\n");
                if (quantity[0] != 0) {
                    printf("%d Apples totalling $%.2lf\n", quantity[0], apples * quantity[0]);
                }
                if (quantity[1] != 0) {
                    printf("%d Bananas totalling $%.2lf\n", quantity[1], bananas * quantity[1]);
                }
                if (quantity[2] != 0) {
                    printf("%d Oranges totalling $%.2lf\n", quantity[2], oranges * quantity[2]);
                }
                if (quantity[3] != 0) {
                    printf("%d of Milk totalling $%.2lf\n", quantity[3], milk * quantity[3]);
                }
                if (quantity[4] != 0) {
                    printf("%d Eggs totalling $%.2lf\n", quantity[4], eggs * quantity[4]);
                }
                printf("Total: $%.2lf\n", total);
                total = 0;
                for (int i = 0; i < 5; i++) {
                    quantity[i] = 0;
                }
                break;
            }
            case '4': {
                total = 0;
                for (int i = 0; i < 5; i++) {
                    quantity[i] = 0;
                }
                printf("Starting afresh\n");
                break;
            }
            case 'q': {
                printf("Quitting...\n");
                return 0;
            }
            default:
                printf("Invalid option. Please choose a valid menu option.\n");
                break;
        }
    }
}
