#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at the beginning of the list
void insertBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Insert at the end of the list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Insert at a specific position in the list
void insertPosition(struct Node** head, int data, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        insertBeginning(head, data);
        return;
    }
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete the first node of the list
void deleteBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = temp->next;
    free(temp);
}

// Delete the last node of the list
void deleteEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev != NULL) {
        prev->next = NULL;
        free(temp);
    } else {
        *head = NULL;
        free(temp);
    }
}

// Delete node at a specific position in the list
void deletePosition(struct Node** head, int position) {
    if (position <= 0) {
        printf("Invalid position.\n");
        return;
    }
    if (position == 1) {
        deleteBeginning(head);
        return;
    }
    struct Node* temp = *head;
    struct Node* prev = NULL;
    for (int i = 1; temp != NULL && i < position; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of range.\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Search for a key in the list
void search(struct Node* head, int key) {
    int position = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        position++;
        if (temp->data == key) {
            printf("Key %d found at position %d.\n", key, position);
            return;
        }
        temp = temp->next;
    }
    printf("Key %d not found in the list.\n", key);
}

// Reverse the linked list
void reverseList(struct Node** head) {
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Remove duplicates from the list
void removeDuplicates(struct Node** head) {
    struct Node* current = *head;
    struct Node* nextNode = NULL;
    while (current != NULL && current->next != NULL) {
        nextNode = current;
        while (nextNode->next != NULL) {
            if (current->data == nextNode->next->data) {
                struct Node* duplicate = nextNode->next;
                nextNode->next = nextNode->next->next;
                free(duplicate);
            } else {
                nextNode = nextNode->next;
            }
        }
// Bubble sort for the linked list
void bubbleSort(struct node **head) {
    if (*head == NULL || (*head)->next == NULL) {
        return; // List is empty or has only one node, no need to sort
    }

    int swapped;
    struct node *ptr1;
    struct node *lptr = NULL;

    do {
        swapped = 0;
        ptr1 = *head;

        while (ptr1->next != lptr) {
            if (ptr1->data > ptr1->next->data) {
                // Swap the data
                int temp = ptr1->data;
                ptr1->data = ptr1->next->data;
                ptr1->next->data = temp;
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Calculate the length of the linked list
int length(struct node *head) {
    int count = 0;
    struct node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Display the linked list
void display(struct node *head) {
    printf("\nLinked List:\n");
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node *head = NULL;
    int choice, data, position, key;

    do {
        printf("\nOperations Menu:\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at specific position\n");
        printf("7. Search\n");
        printf("8. Reverse\n");
        printf("9. Remove Duplicates\n");
        printf("10. Bubble Sort\n");
        printf("11. Length of Linked List\n");
        printf("12. Display\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertBeginning(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertPosition(&head, data, position);
                break;
            case 4:
                deleteBeginning(&head);
                break;
            case 5:
                deleteEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deletePosition(&head, position);
                break;
            case 7:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(head, key);
                break;
            case 8:
                reverse(&head);
                break;
            case 9:
                removeDuplicates(&head);
                break;
            case 10:
                bubbleSort(&head);
                break;
            case 11:
                printf("Length of the Linked List: %d\n", length(head));
                break;
            case 12:
                display(head);
                break;
            case 0:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
