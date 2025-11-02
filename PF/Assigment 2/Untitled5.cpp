#include <stdio.h>
#include <string.h>

void encodeMessage(char message[]);
void decodeMessage(char message[]);
void reverseString(char str[]);
void toggleBits(char *c);

int main() {
    int choice;
    char message[200];

    do {
        printf("\n===== TCS Secure Message System =====\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("=====================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("\nEnter message to ENCODE: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                encodeMessage(message);
                break;
            case 2:
                printf("\nEnter message to DECODE: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = '\0';
                decodeMessage(message);
                break;
            case 3:
                printf("\nExiting system... Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}

void reverseString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void toggleBits(char *c) {
    *c ^= (1 << 1);
    *c ^= (1 << 4);
}

void encodeMessage(char message[]) {
    reverseString(message);
    for (int i = 0; i < strlen(message); i++) {
        toggleBits(&message[i]);
    }
    printf("\nEncoded Message: %s\n", message);
}

void decodeMessage(char message[]) {
    for (int i = 0; i < strlen(message); i++) {
        toggleBits(&message[i]);
    }
    reverseString(message);
    printf("\nDecoded Message: %s\n", message);
}
