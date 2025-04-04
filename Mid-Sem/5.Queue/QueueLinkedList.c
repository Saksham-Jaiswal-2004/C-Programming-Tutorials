#include<stdio.h>
#include<stdlib.h>

struct qnode
{
    int val;
    struct qnode* next;
};

typedef struct Queue
{
    struct qnode *front, *rear;
} Queue;

struct Queue* createQueue()
{
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    return q;
}

void enqueue(Queue* q, int data)
{
    struct qnode* temp = (struct qnode*)malloc(sizeof(struct qnode));
    if (!temp) {
        printf("Memory allocation failed!\n");
        return;
    }
    temp->val = data;
    temp->next = NULL;

    if(q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

int dequeue(Queue* q)
{
    if(q->front == NULL)
    {
        printf("Queue is Empty!\n");
        return -1;
    }

    struct qnode* temp = q->front;
    int value = temp->val;
    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
    return value;
}

int peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty!\n");
        return -1;
    }
    return q->front->val;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

void display(struct Queue* q) {
    struct qnode* temp = q->front;
    if (temp == NULL) {
        printf("Queue is empty!\n");
        return;
    }

    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    printf("Front element: %d\n", peek(q));

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    printf("Is Queue Empty? %s\n", isEmpty(q) ? "Yes" : "No");

    return 0;
}