#include <stdio.h>
#include <string.h>

int Admin(char products[][3][15], int sales[]);
int User(char u[], char p[], char products[][3][15], int sales[]);

int main() {
    int choice, n = 1;
    char id[10], passwd[15], products[20][3][15];
    int sales[20] = {0}; // Array to store sales of each product

    while (n) {
        printf("\n\nWelcome to our online store\nPlease select   0 to exit\n\t\t1 for Customer Login\n\t\t2 for Administration Login\n");
        scanf("%d", &choice);

        switch (choice) {
            case 2:
                printf("Please enter Login-ID: ");
                scanf("%s", id);
                printf("Please enter Password: ");
                scanf("%s", passwd);
                printf("Welcome!!\n");
                n = Admin(products, sales);
                break;
            case 1:
                printf("Please enter Username: ");
                scanf("%s", id);
                printf("Please enter Password: ");
                scanf("%s", passwd);
                printf("Welcome!!\n");
                n = User(id, passwd, products, sales);
                break;
            case 0:
                n = 0;
                return 0;
            default:
                printf("Invalid input\n");
        }
    }
}

int Admin(char products[][3][15], int sales[]) {
    int n = 1, choice, i, j;
    while (n) {
        printf("Administrator options\nSelect  1 to add products\n\t2 to display product details\n\t3 to generate sales report\n\t0 to exit\n");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("Thank you :)\n");
                n = 0;
                return 1;
                break;
            case 1:
                for (i = 0; i < 20; i++) {
                    printf("Enter product name: ");
                    scanf("%s", products[i][1]);
                    sprintf(products[i][0], "ID0%d\0", i);
                    printf("Enter product rate: ");
                    scanf("%s", products[i][2]);
                    printf("Want to add another product details? (y/n): ");
                    char c;
                    scanf(" %c", &c);
                    if (c == 'n' || c == 'N')
                        break;
                }
                break;
            case 2:
                printf("ID \tName\tRate\t\n");
                for (i = 0; i < 20; i++) {
                    for (j = 0; j < 3; j++)
                        printf("%s\t", products[i][j]);
                    printf("\n");
                }
                break;
            case 3:
                printf("Sales Report:\n");
                printf("Product ID \t Sales\n");
                for (i = 0; i < 20; i++) {
                    printf("%s\t\t%d\n", products[i][0], sales[i]);
                }
                break;
            default:
                printf("Invalid Input\n");
        }
    }
}

int User(char u[], char p[], char products[][3][15], int sales[]) {
    int n = 1, choice, i, j;
    char cart[20][4][15];
    while (n) {
        printf("User options\nSelect  0 to checkout\n\t1 to add products to cart\n\t2 to display product details\n\t3 to find product by ID\n\t4 to display cart items\n");
        scanf("%d", &choice);
        switch (choice) {
            case 0:
                printf("ID \tName\tRate\tQuantity\n");
                int bill = 0;
                for (i = 0; i < 20; i++) {
                    for (j = 0; j < 4; j++)
                        printf("%s\t", cart[i][j]);
                    bill += (atoi(cart[i][2]) * atoi(cart[i][3]));
                    sales[i] += atoi(cart[i][3]); // Update sales count
                    printf("\n");
                }
                float tax = 2.8 * bill / 100;
                printf("Amount is %d\n", bill);
                float amt = (float)bill + tax;
                printf("Tax is %.2f\n", tax);
                printf("Total bill amount is %.2f\n", amt);
                printf("Thank you for shopping with us %s:)\n", u);
                n = 0;
                return 1;
                break;
            case 1:
                char name[15];
                int q;
                printf("Enter name of product to be added to cart: ");
                scanf("%s", name);
                for (i = 0; i < 20; i++) {
                    if (strcmp(name, products[i][1]) == 0) {
                        for (j = 0; j < 20; j++) {
                            if (cart[j][0][0] == '\0') {
                                strcpy(cart[j][0], products[i][0]);
                                strcpy(cart[j][1], products[i][1]);
                                strcpy(cart[j][2], products[i][2]);
                                printf("Enter quantity of product to be added to cart: ");
                                scanf("%d", &q);
                                cart[j][3][0] = q + '0'; // Convert integer to character
                                break;
                            }
                        }
                        break;
                    }
                }
                break;
            case 2:
                printf("ID \tName\tRate\t\n");
                for (i = 0; i < 20; i++) {
                    for (j = 0; j < 3; j++)
                        printf("%s\t", products[i][j]);
                    printf("\n");
                }
                break;
            case 3:
                char id[15];
                printf("Enter product ID to search product: ");
                scanf("%s", id);
                for (i = 0; i < 20; i++) {
                    if (strcmp(id, products[i][0]) == 0) {
                        printf("%s\t%s\t%s\n", products[i][0], products[i][1], products[i][2]);
                        break;
                    }
                }
                break;
            case 4:
                printf("ID \tName\tRate\tQuantity\n");
                for (i = 0; i < 20; i++) {
                    for (j = 0; j < 4; j++)
                        printf("%s\t", cart[i][j]);
                    printf("\n");
                }
                break;
            default:
                printf("Invalid Input\n");
        }
    }
}
