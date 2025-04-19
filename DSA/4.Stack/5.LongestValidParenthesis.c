#include <stdio.h>
#include <string.h>

int longestValidParentheses(char* s) 
{
    int maxLen = 0;
    int len = strlen(s);
    int stack[len + 1];
    int top = -1;

    stack[++top] = -1;

    for (int i = 0; i < len; i++) 
    {
        if (s[i] == '(') 
        {
            stack[++top] = i;
        } 
        else 
        {
            top--;
            if (top == -1) 
            {
                stack[++top] = i;
            } 
            else 
            {
                int validLen = i - stack[top];

                if (validLen > maxLen)
                maxLen = validLen;
            }
        }
    }

    return maxLen;
}

int main()
{
    char s1[] = "(()";      
    char s2[] = ")()())";   
    char s3[] = "";         
    char s4[] = "((()))())";

    printf("Test 1: %d\n", longestValidParentheses(s1));
    printf("Test 2: %d\n", longestValidParentheses(s2));
    printf("Test 3: %d\n", longestValidParentheses(s3));
    printf("Test 4: %d\n", longestValidParentheses(s4));

    return 0;
}
