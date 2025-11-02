#include <stdio.h>
#include <string.h>

char codes[100][10];
int quantities[100];
float prices[100];
char names[100][50];
int count = 4;

char cartCodes[100][10];
int cartQuantities[100];
float cartTotals[100];
int cartCount = 0;

char customerName[50];
char customerCNIC[20];

void initialInventory() {
    strcpy(codes[0], "001");
    strcpy(names[0], "Soap");
    quantities[0] = 50;
    prices[0] = 100;

    strcpy(codes[1], "002");
    strcpy(names[1], "Shampoo");
    quantities[1] = 10;
    prices[1] = 200;

    strcpy(codes[2], "003");
    strcpy(names[2], "Oil");
    quantities[2] = 20;
    prices[2] = 300;

    strcpy(codes[3], "004");
    strcpy(names[3], "Toothpaste");
    quantities[3] = 8;
    prices[3] = 150;
}

void customerInfo() {
    char temp;
    printf("\nEnter Customer Name: ");
    scanf("%c", &temp); 
    gets(customerName);

    printf("Enter CNIC Number: ");
    gets(customerCNIC);

    printf("\nCustomer Information Saved Successfully!\n");
}

void displayInventory() {
    if (count == 0) {
        printf("\nNo items in inventory!\n");
        return;
    }

    printf("\nProduct Code\tName\t\tQuantity\tPrice\n");
    printf("---------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%s\t\t%-10s\t%d\t\t%.2f\n", codes[i], names[i], quantities[i], prices[i]);
    }
}

void addItemToCart() {
    char code[10];
    int qty, found, i;
    char more;

    do {
        found = 0;
        printf("\nEnter Product Code: ");
        scanf("%s", code);
        printf("Enter Quantity: ");
        scanf("%d", &qty);

        for (i = 0; i < count; i++) {
            if (strcmp(codes[i], code) == 0) {
                found = 1;
                if (quantities[i] >= qty) {
                    strcpy(cartCodes[cartCount], code);
                    cartQuantities[cartCount] = qty;
                    cartTotals[cartCount] = prices[i] * qty;
                    cartCount++;

                    quantities[i] -= qty;
                    printf("\nItem added to cart successfully!\n");
                } else {
                    printf("\nNot enough stock available!\n");
                }
                break;
            }
        }

        if (!found) {
            printf("\nInvalid product code!\n");
        }

        printf("\nAdd more items? (Y/N): ");
        scanf(" %c", &more);

    } while (more == 'Y' || more == 'y');
}

float displayTotalBill() {
    if (cartCount == 0) {
        printf("\nNo items in cart!\n");
        return 0;
    }

    float total = 0;
    printf("\n---------------- BILL DETAILS ----------------\n");
    printf("Code\tQuantity\tTotal\n");
    for (int i = 0; i < cartCount; i++) {
        printf("%s\t%d\t\t%.2f\n", cartCodes[i], cartQuantities[i], cartTotals[i]);
        total += cartTotals[i];
    }
    printf("---------------------------------------------\n");
    printf("Total Bill (without discount): %.2f\n", total);
    return total;
}

void showInvoice(float total) {
    float discountedTotal = total;
    char promo[20];

    printf("\nIf you have a promocode, enter it (or type 'no'): ");
    scanf("%s", promo);

    if (strcmp(promo, "Eid2025") == 0) {
        discountedTotal = total * 0.75;
        printf("\nPromo applied! 25%% discount given.\n");
    } else {
        printf("\nNo valid promo code applied.\n");
    }

    printf("\n================ INVOICE ================\n");
    printf("Customer Name: %s\n", customerName);
    printf("CNIC: %s\n", customerCNIC);
    printf("------------------------------------------\n");
    printf("Total (without discount): %.2f\n", total);
    printf("Final Bill (after discount if any): %.2f\n", discountedTotal);
    printf("==========================================\n");
}

int main() {
    int choice;
    float total = 0;

    initialInventory();

    do {
        printf("\n\t\tSupermarket Management System");
        printf("\n=============================================================");
        printf("\n1. Customer Information");
        printf("\n2. Display Inventory");
        printf("\n3. Add Item to Cart");
        printf("\n4. Display Total Bill");
        printf("\n5. Show Invoice");
        printf("\n6. Exit");
        printf("\n=============================================================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                customerInfo();
                break;
            case 2:
                displayInventory();
                break;
            case 3:
                addItemToCart();
                break;
            case 4:
                total = displayTotalBill();
                break;
            case 5:
                if (total > 0)
                    showInvoice(total);
                else
                    printf("\nPlease calculate bill first!\n");
                break;
            case 6:
                printf("\nExiting system... Goodbye!\n");
                break;
            default:
                printf("\nInvalid option! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
