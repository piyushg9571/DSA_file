#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void insertAtBeginning(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL)
        head = newNode;
    else
    {
        struct node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
}

void deleteAtBeginning()
{
    if (head == NULL)
        printf("No item to delete\n");
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp); // Free the memory of the deleted node
    }
}

void deleteAtEnd()
{
    if (head == NULL)
        printf("No item to delete\n");
    else
    {
        struct node *prev = NULL;
        struct node *temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL) // Only one node
            head = NULL;
        else
            prev->next = NULL;
        free(temp); // Free the memory of the deleted node
    }
}

void traverse()
{
    struct node *temp = head;
    if (temp == NULL)
        printf("No item to traverse\n");
    else
    {
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

int main()
{
    char choice;
    printf("Do you want to enter the data in nodes(y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y')
    {
        int num_nodes, data;
        printf("Enter the number of nodes you want to create: ");
        scanf("%d", &num_nodes);

        for (int i = 0; i < num_nodes; i++)
        {
            printf("Enter data for node %d: ", i + 1);
            scanf("%d", &data);
            insertAtEnd(data);
        }
    }
    else
    {
        printf("!Empty Node!\n");
    }

    while (1)
    {
        int choice;
        printf("\nEnter the choice\n");
        printf("1. Insertion at Beginning\n2. Insertion at End\n3. Deletion at Beginning\n4. Deletion at End\n5. Traverse\n6. Exit\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtBeginning(data);
            break;
        case 2:
            printf("Enter the data: ");
            scanf("%d", &data);
            insertAtEnd(data);
            break;
        case 3:
            deleteAtBeginning();
            break;
        case 4:
            deleteAtEnd();
            break;
        case 5:
            traverse();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    return 0;
}
