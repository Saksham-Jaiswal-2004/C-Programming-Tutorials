#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node
{
    char val;
    struct node *next;
};

int isEmpty(struct node *top)
{
    if (top == NULL)
        return 1;

    return 0;
}

int isFull(struct node *top)
{
    struct node *p = (struct node *)malloc(sizeof(struct node));

    if (p == NULL)
        return 1;

    return 0;
}

struct node *push(struct node *top, char data)
{
    if (isFull(top))
    {
        printf("Stack Overflow!\n");
        return NULL;
    }
    else
    {
        struct node *n = (struct node *)malloc(sizeof(struct node));
        n->val = data;
        n->next = top;
        top = n;
        return n;
    }
}

struct node *pop(struct node *top)
{
    if (isEmpty(top))
    {
        printf("Stack Underflow!\n");
        return NULL;
    }
    else
    {
        struct node *temp = top;
        top = top->next;
        temp->next = NULL;
        free(temp);
        return top;
    }
}

bool isValid(char *s)
{
    struct node *top = NULL;

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            top = push(top, s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (!isEmpty(top))
            {
                if(s[i] == ')')
                {
                    if(top->val == '(')
                    top = pop(top);
                    else
                    return false;
                }
                if(s[i] == ']')
                {
                    if(top->val == '[')
                    top = pop(top);
                    else
                    return false;
                }
                if(s[i] == '}')
                {
                    if(top->val == '{')
                    top = pop(top);
                    else
                    return false;
                }
            }
            else
                return false;
        }
    }

    if (isEmpty(top))
        return true;
    else
        return false;
}

int main()
{
    char s1[100] = "(({}))";
    char s2[100] = "[(])";
    char s3[100] = "(]";

    if (isValid(s1))
        printf("First String is Valid.\n");
    else
        printf("First String is Not Valid.\n");

    if (isValid(s2))
        printf("Second String is Valid.\n");
    else
        printf("Second String is Not Valid.\n");

    if (isValid(s3))
        printf("Third String is Valid.\n");
    else
        printf("Third String is Not Valid.\n");

    return 0;
}