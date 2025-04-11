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

// Function to convert infix to postfix
void infixToPostfix(char *infix, char *postfix) {
    struct Stack s;
    initStack(&s);
    int i, j = 0;

    for (i = 0; infix[i] != '\0'; i++) {
        char ch = infix[i];

        // If operand, add to output
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }
        // If '(', push to stack
        else if (ch == '(') {
            push(&s, ch);
        }
        // If ')', pop and add to output until '(' is found
        else if (ch == ')') {
            while (!isEmpty(&s) && peek(&s) != '(')
                postfix[j++] = pop(&s);
            pop(&s); // Remove '('
        }
        // If operator, pop from stack according to precedence
        else {
            while (!isEmpty(&s) && precedence(peek(&s)) >= precedence(ch))
                postfix[j++] = pop(&s);
            push(&s, ch);
        }
    }

    // Pop remaining operators
    while (!isEmpty(&s))
        postfix[j++] = pop(&s);

    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);
    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
