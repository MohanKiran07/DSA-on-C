#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 100

// Node structure for the deque
struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
};

// Deque structure
struct Deque {
    struct Node* front;
    struct Node* rear;
};

// Function to create a new node
struct Node* createNode(char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to create an empty deque
struct Deque* createDeque() {
    struct Deque* deque = (struct Deque*)malloc(sizeof(struct Deque));
    if (!deque) {
        printf("Memory allocation error\n");
        exit(1);
    }
    deque->front = deque->rear = NULL;
    return deque;
}

// Function to insert an element at the rear of the deque
void insertRear(struct Deque* deque, char data) {
    struct Node* newNode = createNode(data);
    if (deque->rear == NULL) {
        deque->front = deque->rear = newNode;
    } else {
        deque->rear->next = newNode;
        newNode->prev = deque->rear;
        deque->rear = newNode;
    }
}

// Function to remove an element from the front of the deque
char deleteFront(struct Deque* deque) {
    if (deque->front == NULL) {
        printf("Underflow\n");
        return '\0';
    }
    struct Node* temp = deque->front;
    char data = temp->data;
    deque->front = deque->front->next;
    if (deque->front == NULL) {
        deque->rear = NULL;
    } else {
        deque->front->prev = NULL;
    }
    free(temp);
    return data;
}

// Function to remove an element from the rear of the deque
char deleteRear(struct Deque* deque) {
    if (deque->rear == NULL) {
        printf("Underflow\n");
        return '\0';
    }
    struct Node* temp = deque->rear;
    char data = temp->data;
    deque->rear = deque->rear->prev;
    if (deque->rear == NULL) {
        deque->front = NULL;
    } else {
        deque->rear->next = NULL;
    }
    free(temp);
    return data;
}

// Function to check if the deque is empty
int isEmpty(struct Deque* deque) {
    return deque->front == NULL;
}

// Function to check if a given string is a palindrome using deque
int isPalindrome(char* str) {
    int len = strlen(str);
    struct Deque* deque = createDeque();

    // Insert all characters of the string into the deque
    for (int i = 0; i < len; i++) {
        insertRear(deque, str[i]);
    }

    // Check for palindrome by comparing characters from both ends
    while (!isEmpty(deque) && deque->front != deque->rear) {
        if (deleteFront(deque) != deleteRear(deque)) {
            return 0; // Not a palindrome
        }
    }

    // Clean up the deque
    while (!isEmpty(deque)) {
        deleteFront(deque);
    }
    free(deque);

    return 1; // Is a palindrome
}

int main() {
    char str[max];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isPalindrome(str)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }

    return 0;
}