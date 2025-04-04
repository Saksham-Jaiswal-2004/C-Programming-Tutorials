#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* insertSorted(Node* head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;

    if (!head || head->data >= value) {
        newNode->next = head;
        return newNode;
    }

    Node* current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

void printList(Node* head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void generateUniqueRandomNumbers(int arr[], int size, int min, int max) {
    int count = 0;
    int num;
    int used[21] = {0};
    
    while (count < size) {
        num = (rand() % (max - min + 1)) + min;
        if (!used[num]) {
            arr[count++] = num;
            used[num] = 1;
        }
    }
}

int main() {
    srand(time(0));

    int arr1[SIZE], arr2[SIZE];
    generateUniqueRandomNumbers(arr1, SIZE, 5, 20);
    generateUniqueRandomNumbers(arr2, SIZE, 5, 20);

    printf("******** Array ********\n");
    printf("Original Heap: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr1[i]);
    printf("\n");

    heapSort(arr1, SIZE);

    printf("Sorted Heap: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr1[i]);
    printf("\n");

    printf("\n******** Linked List ********\n");
    printf("Original Heap: \n");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", arr2[i]);
    printf("\n");

    Node* head = NULL;
    for (int i = 0; i < SIZE; i++)
        head = insertSorted(head, arr2[i]);

    printf("Sorted Heap: \n");
    printList(head);

    return 0;
}
