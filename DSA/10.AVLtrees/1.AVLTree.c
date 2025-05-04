#include<stdio.h>
#include<stdlib.h>

struct node
{
    int key;
    struct node* left;
    struct node* right;
    int height;
};

int max(int a, int b)
{
    return a>b?a:b;
}

int getHeight(struct node* n)
{
    if(n == NULL)
    return 0;
    else
    return n->height;
}

struct node* createNode(int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->key = data;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;

    return newNode;
}

int getBalanceFactor(struct node* n)
{
    if(n == NULL)
    return 0;
    else
    return (getHeight(n->left) - getHeight(n->right));
}

struct node* rightRotate(struct node* y)
{
    struct node* x = y->left;
    struct node* t2 = x->right;

    x->right = y;
    y->left = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

struct node* leftRotate(struct node* x)
{
    struct node* y = x->right;
    struct node* t2 = y->left;

    y->left = x;
    x->right = t2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

struct node* insert(struct node* node, int key)
{
    if(node == NULL)
    return createNode(key);

    if(key < node->key)
    node->left = insert(node->left, key);
    else if(key > node->key)
    node->right = insert(node->right, key);

    return node;

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int bf = getBalanceFactor(node);

    // Left Left Case
    if(bf>1 && key<node->left->key)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if(bf<-1 && key>node->left->key)
    {
        return leftRotate(node);
    }

    // Right Left Case
    if(bf<-1 && key<node->left->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    // Left Right Case
    if(bf>1 && key>node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    return node;
}

void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

int main()
{
    struct node* root = NULL;
    
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preorder(root);

    return 0;
}