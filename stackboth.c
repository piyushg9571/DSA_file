#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node 
{
    int data;
    struct Node* next;
};

struct Node* stackTop = NULL;

void push(int value);
void pop();
void display();

int main() 
{
    int choice, value;
    printf("\nStack Operations\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");
    
    while (1) 
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

void push(int value) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) 
    {
        printf("Stack Overflow...\n");
        return;
    }
    newNode->data = value;
    newNode->next = stackTop;
    stackTop = newNode;
    printf("%d pushed to stack\n", value);
}

void pop() 
{
    if (stackTop == NULL) 
    {
        printf("Stack Underflow\n");
        return;
    }
    struct Node* temp = stackTop;
    printf("Popped element: %d\n", temp->data);
    stackTop = stackTop->next;
    free(temp);
}

void display() 
{
    if (stackTop == NULL) 
    {
        printf("Stack is empty\n");
        return;
    }
    struct Node* current = stackTop;
    printf("Stack elements: ");
    while (current != NULL) 
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
