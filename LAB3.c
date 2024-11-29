#include <stdio.h>
#include <stdlib.h>
#define MAX 3 // Maximum size of the stack

// Function declarations
int isFull();
int isEmpty();
void push(int element);
int pop();
void display();
void checkPalindrome();

// Global variables
int stack[MAX];
int top = -1;

// Main function to drive the menu
int main() {
    int choice, element;

    while (1) {
        printf("\nChoose an operation:\n");
        printf("1. Push an element onto stack\n");
        printf("2. Pop an element from stack\n");
        printf("3. Check if stack contents form a palindrome\n");
        printf("4. Demonstrate overflow and underflow\n");
        printf("5. Display stack status\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push(element should be single digit): ");
                scanf("%d", &element);
                push(element);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                // Demonstrate overflow
                printf("Attempting to fill stack to overflow...\n");
                for (int i = 0; i < MAX + 1; i++) {
                    push(i + 1);
                }
                // Demonstrate underflow
                printf("Attempting to empty stack to underflow...\n");
                for (int i = 0; i < MAX + 1; i++) {
                    pop();
                }
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// Function definitions

// Function to check if stack is full
int isFull() {
    return top == MAX - 1;
}

// Function to check if stack is empty
int isEmpty() {
    return top == -1;
}

// Function to push an element onto the stack
void push(int element) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d\n", element);
        return;
    } else {
        stack[++top] = element;
        printf("%d pushed onto stack.\n", element);
    }
}

// Function to pop an element from the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Cannot pop an element\n");
        return -1;
    } else {
        printf("%d popped from stack.\n", stack[top]);
        return stack[top--];
    }
}

// Function to display the current status of the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements are: ");
        for (int i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

// Function to check if stack elements form a palindrome
void checkPalindrome() {
    if (isEmpty()) {
        printf("Stack is empty. Cannot check for palindrome.\n");
        return;
    }
    int isPalindrome = 1;
    for (int i = 0; i <= top / 2; i++) {
        if (stack[i] != stack[top - i]) {
            isPalindrome = 0;
            break;
        }
    }
    if (isPalindrome) {
        printf("Stack contents form a palindrome.\n");
    } else {
        printf("Stack contents do not form a palindrome.\n");
    }
}