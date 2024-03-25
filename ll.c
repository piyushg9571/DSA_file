#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    int next_index; // Index of the next node in the array
} Node;

typedef struct {
    Node array[100]; // Assuming a fixed size array for simplicity
    int head; // Index of the first node in the array
    int next_available; // Index where the next node can be inserted
} LinkedList;

void ins_beg(LinkedList *list, int data);
void ins_end(LinkedList *list, int data);
void ins_at_position(LinkedList *list, int position, int data);
void del_beg(LinkedList *list);
void del_end(LinkedList *list);
void del_at_position(LinkedList *list, int position);
void traverse(const LinkedList *list);
void create_nodes(LinkedList *list);

int main() {
    char c;
    int choice;
    LinkedList list;
    list.head = -1;
    list.next_available = 0;

    printf("Do you want to enter data in nodes? (y/n): ");
    scanf(" %c", &c);

    if (c == 'y' || c == 'Y') {
        create_nodes(&list);
    } else {
        printf("!Empty Node!\n");
    }

    while (1) {
        printf("\nEnter the choice\n");
        printf("1. Insertion at Beginning\n2. Insertion at End\n3. Insertion at Particular Location\n");
        printf("4. Deletion at Beginning\n5. Deletion at End\n6. Deletion at Particular Location\n");
        printf("7. Traverse\n8. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data: ");
                int data;
                scanf("%d", &data);
                ins_beg(&list, data);
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                ins_end(&list, data);
                break;
            case 3:
                {
                    int position;
                    printf("Enter the position for insertion: ");
                    scanf("%d", &position);
                    printf("Enter the data: ");
                    scanf("%d", &data);
                    ins_at_position(&list, position, data);
                    break;
                }
            case 4:
                del_beg(&list);
                break;
            case 5:
                del_end(&list);
                break;
            case 6:
                {
                    int position;
                    printf("Enter the position for deletion: ");
                    scanf("%d", &position);
                    del_at_position(&list, position);
                    break;
                }
            case 7:
                traverse(&list);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}

void ins_beg(LinkedList *list, int data) {
    int index = list->next_available;
    list->array[index].data = data;
    list->array[index].next_index = list->head;
    list->head = index;
    list->next_available++;
}

void ins_end(LinkedList *list, int data) {
    int index = list->next_available;
    list->array[index].data = data;
    list->array[index].next_index = -1;
    if (list->head == -1) {
        list->head = index;
    } else {
        int temp = list->head;
        while (list->array[temp].next_index != -1) {
            temp = list->array[temp].next_index;
        }
        list->array[temp].next_index = index;
    }
    list->next_available++;
}

void ins_at_position(LinkedList *list, int position, int data) {
    if (position < 1 || position > list->next_available + 1) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        ins_beg(list, data);
        return;
    }
    if (position == list->next_available + 1) {
        ins_end(list, data);
        return;
    }
    int index = list->next_available;
    list->array[index].data = data;
    int count = 1;
    int temp = list->head;
    while (count < position - 1) {
        temp = list->array[temp].next_index;
        count++;
    }
    list->array[index].next_index = list->array[temp].next_index;
    list->array[temp].next_index = index;
    list->next_available++;
}

void del_beg(LinkedList *list) {
    if (list->head == -1) {
        printf("No item to delete\n");
        return;
    }
    int temp = list->head;
    list->head = list->array[temp].next_index;
    printf("Deleted element: %d\n", list->array[temp].data);
    list->next_available--;
}

void del_end(LinkedList *list) {
    if (list->head == -1) {
        printf("No item to delete\n");
        return;
    }
    int temp = list->head;
    int prev = -1;
    while (list->array[temp].next_index != -1) {
        prev = temp;
        temp = list->array[temp].next_index;
    }
    if (prev == -1) {
        printf("Deleted element: %d\n", list->array[temp].data);
        list->head = -1;
    } else {
        printf("Deleted element: %d\n", list->array[temp].data);
        list->array[prev].next_index = -1;
    }
    list->next_available--;
}

void del_at_position(LinkedList *list, int position) {
    if (position < 1 || position > list->next_available) {
        printf("Invalid position\n");
        return;
    }
    if (position == 1) {
        del_beg(list);
        return;
    }
    if (position == list->next_available) {
        del_end(list);
        return;
    }
    int count = 1;
    int temp = list->head;
    while (count < position - 1) {
        temp = list->array[temp].next_index;
        count++;
    }
    int next_index = list->array[temp].next_index;
    printf("Deleted element: %d\n", list->array[next_index].data);
    list->array[temp].next_index = list->array[next_index].next_index;
    list->next_available--;
}

void traverse(const LinkedList *list) {
    if (list->head == -1) {
        printf("No items to traverse\n");
        return;
    }
    printf("Linked List: ");
    int temp = list->head;
    while (temp != -1) {
        printf("%d ", list->array[temp].data);
        temp = list->array[temp].next_index;
    }
    printf("\n");
}

void create_nodes(LinkedList *list) {
    int num_nodes;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &num_nodes);

    printf("Enter data for each node:\n");
    for (int i = 0; i < num_nodes; i++) {
        int data;
        printf("Node %d: ", i + 1);
        scanf("%d", &data);
        ins_end(list, data);
    }
}
