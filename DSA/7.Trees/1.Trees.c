#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

int main()
{
    struct node* root = createNode(54);
    struct node* a = createNode(32);
    struct node* b = createNode(91);

    root->left = a;
    root->right = b;

    printf("Root Node: %d\n", root->data);
    printf("Left Child of Root: %d\n", root->left->data);
    printf("Right Child of Root: %d\n", root->right->data);

    return 0;
}