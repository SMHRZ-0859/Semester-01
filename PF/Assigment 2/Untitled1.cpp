#include <stdio.h>
#include <string.h>

#define MAX_BOOKS 100

int isbns[MAX_BOOKS];
char titles[MAX_BOOKS][50];
float prices[MAX_BOOKS];
int quantities[MAX_BOOKS];
int count = 0;

void addNewBook() {
    int isbn, qty;
    float price;
    char title[50];
    char more;

    do {
        int duplicate = 0;

        printf("\nEnter ISBN Number: ");
        scanf("%d", &isbn);

        for (int i = 0; i < count; i++) {
            if (isbns[i] == isbn) {
                printf("\nError: Duplicate ISBN! Book already exists.\n");
                duplicate = 1;
                break;
            }
        }

        if (duplicate == 0) {
            printf("Enter Book Title: ");
            scanf(" %[^\n]", title);
            printf("Enter Book Price: ");
            scanf("%f", &price);
            printf("Enter Book Quantity: ");
            scanf("%d", &qty);

            isbns[count] = isbn;
            strcpy(titles[count], title);
            prices[count] = price;
            quantities[count] = qty;

            count++;
            printf("\nBook added successfully!\n");
        }

        printf("\nAdd More Books? (Y/N): ");
        scanf(" %c", &more);
    } while (more == 'Y' || more == 'y');
}

void processSale() {
    if (count == 0) {
        printf("\nNo books in inventory!\n");
        return;
    }

    int searchISBN, sold, found = 0;
    printf("\nEnter ISBN Number for Sale: ");
    scanf("%d", &searchISBN);

    for (int i = 0; i < count; i++) {
        if (isbns[i] == searchISBN) {
            found = 1;
            printf("\nBook Found: %s\n", titles[i]);
            printf("Current Stock: %d\n", quantities[i]);
            printf("Enter Quantity to Sell: ");
            scanf("%d", &sold);

            if (sold <= quantities[i]) {
                quantities[i] -= sold;
                printf("\nSale Successful! Remaining Stock: %d\n", quantities[i]);
            } else {
                printf("\nError: Not enough stock available!\n");
            }
            break;
        }
    }

    if (!found) {
        printf("\nBook not found!\n");
    }
}

void generateLowStockReport() {
    if (count == 0) {
        printf("\nNo books in inventory!\n");
        return;
    }

    int found = 0;
    printf("\n===== LOW STOCK REPORT (Qty < 5) =====\n");
    printf("ISBN\tTitle\t\tPrice\tQuantity\n");
    printf("-----------------------------------------\n");

    for (int i = 0; i < count; i++) {
        if (quantities[i] < 5) {
            printf("%d\t%-10s\t%.2f\t%d\n", isbns[i], titles[i], prices[i], quantities[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("All books have sufficient stock.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\n\t\tLiberty Books Inventory System");
        printf("\n==============================================================");
        printf("\n1. Add New Book");
        printf("\n2. Process a Sale");
        printf("\n3. Generate Low-Stock Report");
        printf("\n4. Exit");
        printf("\n==============================================================");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addNewBook();
                break;
            case 2:
                processSale();
                break;
            case 3:
                generateLowStockReport();
                break;
            case 4:
                printf("\nExiting program... Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
