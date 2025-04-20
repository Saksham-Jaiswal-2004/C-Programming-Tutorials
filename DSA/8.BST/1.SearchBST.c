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

int isBST(struct node* root) {
    static struct node* prev = NULL;

    if (root == NULL)
        return 1;

    if (!isBST(root->left))
        return 0;

    if (prev != NULL && root->data <= prev->data)
        return 0;

    prev = root;

    return isBST(root->right);
}

int searchBST(struct node* root, int key)
{
    if(root == NULL)
    return NULL;
    
    if(root->data == key)
    return 1;
    else if(root->data < key)
    {
        if(root->right != NULL)
        return searchBST(root->right, key);
    }
    else
    {
        if(root->left != NULL)
        return searchBST(root->left, key);
    }

    return 0;
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

    if(isBST(root))
    printf("It's a BST.\n");
    else
    printf("It's not a BST.\n\n");

    int num;
    printf("Enter Number to search: ");
    scanf("%d", &num);
    if(searchBST(root, num))
    printf("%d is present in BST\n", num);
    else
    printf("%d is not present in BST\n", num);

    return 0;
}