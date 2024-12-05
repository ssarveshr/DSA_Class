#include <stdio.h>
#include <stdlib.h>
#define MAX 3

// Function Declarations
int isfull(int count);
int isempty(int count);
void cenqueue(char ele, int *rear, int *count, char cq[]);
char cdequeue(int *front, int *count, char cq[]);
void display(int front, int count, char cq[]);

int main() 
{
    char cq[MAX];
    int front = 0, rear = -1, count = 0;
    int ch;

    while (1) 
    {
        printf("\nMenu:\n");
        printf("1. Insert an Element into Circular QUEUE\n");
        printf("2. Delete an Element from Circular QUEUE\n");
        printf("3. Display Circular QUEUE\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch) 
        {
            case 1: 
                if (isfull(count)) 
                {
                    printf("Overflow: Circular queue is full.\n");
                } 
                else 
                {
                    char ele;
                    printf("Enter the character to be inserted into the circular queue: ");
                    scanf(" %c", &ele);  // Notice the space before %c to ignore any newline characters
                    cenqueue(ele, &rear, &count, cq);
                }
                break;

            case 2: 
                if (isempty(count)) 
                {
                    printf("Underflow: Circular queue is empty.\n");
                } 
                else 
                {
                    char ele = cdequeue(&front, &count, cq);
                    printf("Deleted element: %c\n", ele);
                }
                break;

            case 3: 
                display(front, count, cq);
                break;

            case 4: 
                printf("Exiting...\n");
                exit(0);

            default: 
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function Definitions

int isfull(int count) 
{
    return count == MAX;
}

int isempty(int count) 
{
    return count == 0;
}

void cenqueue(char ele, int *rear, int *count, char cq[]) 
{
    *rear = (*rear + 1) % MAX;
    cq[*rear] = ele;
    (*count)++;
}

char cdequeue(int *front, int *count, char cq[]) 
{
    char ele = cq[*front];
    *front = (*front + 1) % MAX;
    (*count)--;
    return ele;
}

void display(int front, int count, char cq[]) 
{
    if (isempty(count)) 
    {
        printf("Circular queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    for (int i = 0; i < count; i++) 
    {
        printf("%c ", cq[(front + i) % MAX]);
    }
    printf("\n");
}