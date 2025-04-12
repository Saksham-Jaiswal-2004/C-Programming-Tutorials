#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

// Stack structure
struct Stack {
    int top;
    char items[MAX];
};

// Function to initialize stack
void initStack(struct Stack *s) {
    s->top = -1;
}

// Function to check if stack is empty
int isEmpty(struct Stack *s) {
    return (s->top == -1);
}

// Function to push element into stack
void push(struct Stack *s, char ch) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->items[++(s->top)] = ch;
}

// Function to pop element from stack
char pop(struct Stack *s) {
    if (isEmpty(s))
        return '\0';
    return s->items[(s->top)--];
}

// Function to get top element of stack
char peek(struct Stack *s) {
    if (isEmpty(s))
        return '\0';
    return s->items[s->top];
}

// Function to check precedence of operators
int precedence(char ch) {
    switch (ch) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
        default: return 0;
    }
}

// Function to reverse a string
void reverseString(char *str) {
    int i, j;
    char temp;
    int len = strlen(str);
    for (i = 0, j = len - 1; i < j; i++, j--) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to convert infix to prefix
void infixToPrefix(char *infix, char *prefix) {
    struct Stack s;
    initStack(&s);
    int i, j = 0;
    
    // Reverse the infix expression
    reverseString(infix);

    // Process reversed infix expression
    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add to output
        if (isalnum(ch)) {
            prefix[j++] = ch;
        }
        // If ')', push to stack
        else if (ch == ')') {
            push(&s, ch);
        }
        // If '(', pop and add to output until ')' is found
        else if (ch == '(') {
            while (!isEmpty(&s) && peek(&s) != ')')
                prefix[j++] = pop(&s);
            pop(&s); // Remove ')'
        }
        // If operator, pop from stack according to precedence
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) > precedence(ch))
                prefix[j++] = pop(&s);
            push(&s, ch);
        }
    }

    // Pop remaining operators
    while (!isEmpty(&s))
        prefix[j++] = pop(&s);

    prefix[j] = '\0';

    // Reverse the result to get final prefix expression
    reverseString(prefix);
}

int main() {
    char infix[MAX], prefix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);
    printf("Prefix Expression: %s\n", prefix);

    return 0;
}
