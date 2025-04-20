#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int val)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorder(struct node* root)
{
    if(root->left != NULL)
    inorder(root->left);

    printf("%d ", root->data);

    if(root->right != NULL)
    inorder(root->right);
}

struct node* inOrderPredecessor(struct node* root)
{
    root = root->left;

    while(root->right != NULL)
    root = root->right;

    return root;
}

struct node* insertBST(struct node* root, int key)
{
    if(root == NULL)
        return createNode(key);
    
    if(root->data == key)
        return root;
    else if(key < root->data)
        root->left = insertBST(root->left, key);
    else
        root->right = insertBST(root->right, key);
    
    return root;
}

struct node* deleteBST(struct node* root, int key)
{
    struct node* iPre;

    if(root == NULL)
    return NULL;

    if(root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }

    if(key < root->data)
    root->left = deleteBST(root->left, key);
    else if(key > root->data)
    root->right = deleteBST(root->right, key);
    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left =deleteBST(root->left, iPre->data);
    }

    return root;
}


int main()
{
    struct node* root = createNode(9);
    root->left = createNode(4);
    root->right = createNode(11);
    root->left->left = createNode(2);
    root->left->right = createNode(7);
    root->left->right->left = createNode(5);
    root->left->right->right = createNode(8);
    root->right->right = createNode(15);
    root->right->right->left = createNode(14);

    inorder(root);
    printf("\n");
    
    int num;
    printf("\nEnter Number to insert: ");
    scanf("%d", &num);
    
    root = insertBST(root, num);
    
    inorder(root);
    printf("\n");

    printf("\nEnter Number to delete: ");
    scanf("%d", &num);

    deleteBST(root, num);

    inorder(root);

    return 0;
}