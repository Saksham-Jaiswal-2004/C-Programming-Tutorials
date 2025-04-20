#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//Creating Linked List Structure
struct Node 
{
    int data;
    struct Node* next;
};

//Function Randomly access data in an Array
void accessArray(int arr[], int position) 
{
    printf("Accessing element at index %d: %d\n", position, arr[position]); //Printing index with data
}

//Function Randomly access data in a Linked List
void accessLinkedList(struct Node* head, int position)
{
    struct Node* temp = head;
    for (int i=0; i<position; i++) //for loop to traverse through the linked list to get data
    {
        temp = temp->next;
    }
    printf("Accessing element at index %d: %d\n", position, temp->data); //Printing index with data
}

//Function to insert an element in an Array
void insertArray(int arr[], int* size, int element, int position) 
{
    for (int i=*size; i>position; i--) //for loop to store array data of previous index so that a space is created at the required position to insert data
    {
        arr[i] = arr[i-1];
    }
    arr[position] = element; //Storing data at the required position
    (*size)++;
}

//Function to insert an element in a Linked List
void insertLinkedList(struct Node** head, int element, int position) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //Creating a new node
    newNode->data = element; //Storing required data in it
    newNode->next = NULL;

    if (position == 0) //If position is 0 then making the node as head (First Element)
    {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp=*head;
    for (int i=0; i<position-1 && temp!=NULL; i++) 
    {
        temp = temp->next;
    }
    newNode->next = temp->next; //Storing address of consecutive node in the linked list
    temp->next = newNode; //Storing address of our newly created node in the previous node
}


//Main Function to handle all operations
int main() 
{
    srand(time(0)); //Seed to generate random numbers

    const int size = 10; //Initializing size for array
    int arr[size]; 
    int arrSize = 0;

    for (int i=0; i<size; i++) //for loop to store random data in the array
    {
        arr[i] = i+1;
    }
    arrSize = size;

    //Creating First element of Linked List with array data
    struct Node* head = (struct Node*)malloc(sizeof(struct Node)); //Assigning required storage/space
    head->data = arr[0];
    head->next = NULL;
    struct Node* temp = head;
    
    //for loop to create and link other elements or nodes of the Linked List with array data
    for (int i=1; i<size; i++) 
    {
        temp->next = (struct Node*)malloc(sizeof(struct Node));
        temp = temp->next; //Storing address
        temp->data = arr[i]; //Storing Data
        temp->next = NULL;
    }

    printf("*****Randomly Accessing an Element*****\n");
    
    int index = rand()%size; //Randomly generating index from where data will be fetched
    
    //Randomly Accessing a value in Array
    printf("Array:\n");
    clock_t start=clock(); //Storing time before function execution
    accessArray(arr, index); //Calling function randomly access an element in array
    clock_t end=clock();  //Storing time after function execution
    printf("Time taken: %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC); //Printing time taken during this execution
    
    printf("\n");

    //Randomly Accessing a value in Array
    printf("Linked List:\n");
    start=clock(); //Storing time before function execution
    accessLinkedList(head, index); //Calling function randomly access an element in linked list
    end=clock(); //Storing time after function execution
    printf("Time taken: %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC); //Printing time taken during this execution

    printf("\n\n*****Inserting an Element*****\n");
    int newElement = 10; //New element to be inserted
    int position = 4; //Position at which the element is to be inserted

    printf("Array:\n");
    start=clock(); //Storing time before function execution
    insertArray(arr, &arrSize, newElement, position); //Calling function insert an element in array
    end=clock(); //Storing time after function execution
    printf("Time taken: %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    printf("\n");

    printf("Linked List:\n");
    start=clock(); //Storing time before function execution
    insertLinkedList(&head, newElement, position); //Calling function insert an element in linked list
    end=clock(); //Storing time after function execution
    printf("Time taken: %f seconds.\n", (double)(end - start) / CLOCKS_PER_SEC);
    
    printf("\n\nHence it can be seen through time taken that random access of a number from a list of numbers is advantageous while implementing through ARRAY over LINKED-LIST!");
    printf("\n\nHence it can be seen through time taken that insertion of a number into a list of numbers is advantageous while implementing through LINKED-LIST over ARRAY!\n");

    return 0;
}