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

void preOrder(struct node* root)
{
    printf("%d ", root->data);

    if(root->left != NULL)
    preOrder(root->left);

    if(root->right != NULL)
    preOrder(root->right);
}

void inOrder(struct node* root)
{
    if(root->left != NULL)
    inOrder(root->left);

    printf("%d ", root->data);

    if(root->right != NULL)
    inOrder(root->right);
}

void postOrder(struct node* root)
{
    if(root->left != NULL)
    postOrder(root->left);
    
    if(root->right != NULL)
    postOrder(root->right);
    
    printf("%d ", root->data);
}

int main()
{
    // struct node* root = createNode(10);
    // root->left = createNode(5);
    // root->right = createNode(20);
    // root->left->left = createNode(3);
    // root->left->right = createNode(7);
    // root->right->left = createNode(15);
    // root->right->right = createNode(25);

    struct node* root = createNode(7);
    root->left = createNode(2);
    root->right = createNode(1);
    root->left->left = createNode(0);
    root->left->right = createNode(4);

    printf("Preorder Traversal: ");
    preOrder(root);
    printf("\n");
    printf("Inorder Traversal: ");
    inOrder(root);
    printf("\n");
    printf("Postorder Traversal: ");
    postOrder(root);

    return 0;
}