#include<stdio.h>
#include<stdlib.h>

struct list
{
    int val;
    struct list* next;
};

struct charList
{
    char val;
    struct charList* next;
};

struct list* createList(int data)
{
    struct list* temp = (struct list*) malloc(sizeof(struct list));
    temp->val = data;
    temp->next = NULL;

    return temp;
}

struct charList* createCharList(char data)
{
    struct charList* temp = (struct charList*) malloc(sizeof(struct charList));
    temp->val = data;
    temp->next = NULL;

    return temp;
}

void insertInt(struct list* root, int pos, int val)
{
    struct list* temp = root;

    for(int i=0 ; i<pos-2 ; i++)
    {
        temp = temp->next;
    }

    struct list* buffer = temp->next;
    temp->next = createList(val);
    temp->next->next = buffer;
}

void deleteChar(struct charList* root, int pos)
{
    struct charList* temp = root;

    for(int i=0 ; i<pos-2 ; i++)
    {
        temp = temp->next;
    }

    struct charList* buffer = temp->next;
    temp->next = temp->next->next;
    buffer->next = NULL;
    free(buffer);
}

void printList1(struct list* root)
{
    struct list* temp = root;
    while(temp!=NULL)
    {
        printf("%d ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

void printList2(struct charList* root)
{
    struct charList* temp = root;
    while(temp!=NULL)
    {
        printf("%c ", temp->val);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct list* root1 = createList(1);
    struct charList* root2 = createCharList('a');

    struct list* temp1 = root1;
    struct charList* temp2 = root2;

    for(int i=0 ; i<9 ; i++)
    {
        temp1->next = createList(i+2);
        temp2->next = createCharList((char)(i+98));

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    printf("Initially:\n");
    printList1(root1);
    printList2(root2);

    insertInt(root1, 5, 555);
    deleteChar(root2, 8);

    printf("\nAfter Changes:\n");
    printList1(root1);
    printList2(root2);

    return 0;
}