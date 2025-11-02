#include <stdio.h>

#define MAX_SIZE 5

void push(int stack[], int *top, int maxSize);
void pop(int stack[], int *top);
void peek(int stack[], int top);
void display(int stack[], int top);

int main() {
    int stack[MAX_SIZE];
    int top = -1;
    int choice;

    do {
        printf("\n========== Stack Operations ==========\n");
        printf("1. PUSH (Insert Element)\n");
        printf("2. POP (Remove Top Element)\n");
        printf("3. PEEK (View Top Element)\n");
        printf("4. DISPLAY (Show Stack)\n");
        printf("5. EXIT\n");
        printf("======================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push(stack, &top, MAX_SIZE);
                break;
            case 2:
                pop(stack, &top);
                break;
            case 3:
                peek(stack, top);
                break;
            case 4:
                display(stack, top);
                break;
            case 5:
                printf("Exiting program... Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

void push(int stack[], int *top, int maxSize) {
    if (*top == maxSize - 1) {
        printf("\nStack Overflow! Cannot push more elements.\n");
        return;
    }

    int value;
    printf("Enter value to PUSH: ");
    scanf("%d", &value);

    (*top)++;
    stack[*top] = value;
    printf("Element %d pushed onto the stack.\n", value);
}

void pop(int stack[], int *top) {
    if (*top == -1) {
        printf("\nStack Underflow! No elements to pop.\n");
        return;
    }

    printf("Element %d popped from the stack.\n", stack[*top]);
    (*top)--;
}

void peek(int stack[], int top) {
    if (top == -1) {
        printf("\nStack is empty! Nothing to peek.\n");
        return;
    }

    printf("Top element is: %d\n", stack[top]);
}

void display(int stack[], int top) {
    if (top == -1) {
        printf("\nStack is empty!\n");
        return;
    }

    printf("\nCurrent Stack Elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d\n", stack[i]);
    }
}
