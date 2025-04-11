#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL; // Stack initially empty

// Function to push an element onto the stack
void push(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return -1;
    }
    Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;
    free(temp);
    printf("%d popped from stack\n", poppedValue);
    return poppedValue;
}

// Function to return the top element of the stack
int peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    return top->data;
}

// Function to check if the stack is empty
int isEmpty() {
    return top == NULL;
}

// Function to display the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    Node* temp = top;
    printf("Stack elements: ");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Driver function
int main() {
    push(10);
    push(20);
    push(30);
    display();
    printf("Top element is %d\n", peek());
    pop();
    display();
    printf("Stack is %s\n", isEmpty() ? "empty" : "not empty");
    return 0;
}
