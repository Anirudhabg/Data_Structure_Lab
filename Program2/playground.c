/* Design, develop, and execute a program in C to evaluate a valid postfix expression using stack.
Assume that the postfix expression is read as a single line consisting of non-negative single
digit operands and binary arithmetic operators.
The arithmetic operators are + (add), - (subtract), * (multiply) and / (divide). */

// CASE 1:
// Input: 623+-382/+*2-3+
// Output: Result of the expression 623+-382/+*2-3+ is: 8.

// CASE 2:
// Input: 821*+
// Output: Result of the expression 821*+ is: 10.

#include <stdio.h>
#include <ctype.h>

#define MAX 50

int STACK[MAX];

int TOP = -1;

void push(int x)
{
    STACK[++TOP] = x;
}

int pop()
{
    if (TOP == -1)
        return -1;

    return STACK[TOP--];
}

int getRes(int a, int b, char s)
{
    if(s == '+')
        return a + b;
    else if(s == '-')
        return b - a;
    else if(s == '*')
        return a * b;
    else if(s == '/')
        return b / a;
}

void main()
{
    char s, EXPRESSION[50];
    int i = 0;
    printf("Enter the expression in postfix form only: \n");
    scanf("%s", EXPRESSION);
    int a, b, c, d;
    while (EXPRESSION[i] != '\0')
    {
        s = EXPRESSION[i];
        if (isdigit(s))
        {
            d = s - 48;
            push(d);
        }
        else
        {
            a = pop();
            b = pop();

            c = getRes(a, b, s);
            push(c);
        }
        i++;
    }
    printf("Result of the expression %s is: %d.", EXPRESSION, pop());
}