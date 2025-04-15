// Implement a program in C to convert an infix expression to postfix using stack operations.

// CASE 1:
// Input: a - b / c
// Output: abc/-

// CASE 2:
// Input: a + b
// Output: ab+

// CASE 3:
// Input: (a+b*d)/(c-f)+g
// Output: abd*ef-/g+

#include <stdio.h>
#include <ctype.h>

char STACK[100];

int TOP = -1;

void push(char x)
{
    STACK[++TOP] = x;
}

char pop()
{
    if (TOP == -1)
    {
        return -1;
    }
    return STACK[TOP--];
}

int priority(char x)
{
    if (x == '(')
    {
        return 0;
    }
    if (x == '+' || x == '-')
    {
        return 1;
    }
    if (x == '*' || x == '/')
    {
        return 2;
    }
    if (x == '^')
    {
        return 3;
    }
    return 0;
}

void main()
{
    char EXPRESSION[100];

    char *e, x;

    printf("Enter the expression: \n");

    scanf("%s", EXPRESSION);

    printf("\n");

    e = EXPRESSION;

    while (*e != '\0')
    {
        if (isalnum(*e))
        {
            printf("%c", *e);
        }
        else if (*e == '(')
        {
            push(*e);
        }
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
            {
                printf("%c", x);
            }
        }
        else
        {
            while (priority(STACK[TOP]) >= priority(*e))
            {
                printf("%c", pop());
            }
            push(*e);
        }
        e++;
    }
    while (TOP != -1)
    {
        printf("%c", pop());
    }
}