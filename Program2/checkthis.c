#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

int pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack[top--];
}

int main()
{
    char expression[100];
    printf("Enter the postfix expression with space between tokens: \n");
    fgets(expression, sizeof(expression), stdin);

    char *token = strtok(expression, " \n");

    while (token != NULL)
    {
        if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
        {
            // It's an operand (also handles negative numbers)
            push(atoi(token));
        }
        else
        {
            // It's an operator
            int a = pop();
            int b = pop();
            int result;

            switch (token[0])
            {
            case '+':
                result = b + a;
                break;
            case '-':
                result = b - a;
                break;
            case '*':
                result = b * a;
                break;
            case '/':
                result = b / a;
                break;
            default:
                printf("Invalid operator: %s\n", token);
                return 1;
            }
            push(result);
        }

        token = strtok(NULL, " \n");
    }

    printf("Result of the expression is: %d\n", pop());
    return 0;
}
