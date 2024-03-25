#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Function prototypes
void push(int data);
int pop();
int peek();
void traverse();

int main() 
{
    int choice;
    int value;

    while (1) 
    {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Traverse\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the value to push: ");
                scanf(" %d", &value);
                push(value);
                break;
            case 2:
                printf("Popped element: %d\n", pop());
                break;
            case 3:
                printf("Top element: %d\n", peek());
                break;    
            case 4:
                traverse();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void push(int data) 
{
    if (top == MAX - 1) 
    {
        printf("Stack Overflow! Cannot push element.\n");
    } 
    else 
    {
        top = top + 1;
        stack[top] = data;
        printf("Element %d pushed into the stack.\n", data);
    }
}

int pop() 
{
    if (top == -1) 
    {
        printf("Stack Underflow! Cannot pop element.\n");
        return -1;
    }
    else 
    {
        int data = stack[top];
        top = top - 1;
        printf("Element %d popped from the stack.\n", data);
        return data;
    }
}

int peek() 
{
    if (top == -1) 
    {
        printf("Stack is empty.\n");
        return -1;
    } 
    else 
    {
        return stack[top];
    }
}

void traverse() 
{
    if (top == -1) 
    {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    int tmp = top;
    for (int i = tmp; i > -1; i--) 
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}
