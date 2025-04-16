// Using circular representation for a polynomial, design, develop, and execute a program in C to accept two
// polynomials, add them, and then print the resulting polynomial.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coef;
    int exp;
    struct Node *next;
} node;

node *insertNode(node *head, int coef, int exp)
{
    node *newNode = (node *)malloc(sizeof(node));

    node *ptr;

    newNode->coef = coef;
    newNode->exp = exp;
    newNode->next = NULL;

    if (head == NULL || head->exp < exp)
    {
        newNode->next = head;
        head = newNode;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL && ptr->next->exp >= exp)
        {
            ptr = ptr->next;
        }
        newNode->next = ptr->next;
        ptr->next = newNode;
    }
    return head;
}

node *createNode(node *head)
{
    int n, exp, coef;
    printf("\n Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("\n Enter thr coefficient for %d term: ", i + 1);
        scanf("%d", &coef);
        printf("\n Enter thr expression for %d term: ", i + 1);
        scanf("%d", &exp);

        head = insertNode(head, coef, exp);
    }
    return head;
}

void printPolynomial(node *head)
{
    if (head == NULL)
    {
        printf("\n No Polynomial!!");
        return;
    }

    node *ptr = head;
    while (ptr != NULL)
    {
        int coef = ptr->coef;
        if (coef < 0)
        {
            coef *= (-1);
        }
        printf("%dx^%d ", coef, ptr->exp);
        ptr = ptr->next;
        if (ptr != NULL && ptr->coef >= 0)
        {
            printf("+ ");
        }
        else if (ptr != NULL && ptr->coef < 0)
        {
            printf("- ");
        }
    }
}

void polynomialAddition(node *polynomialOne, node *polynomialTwo)
{
    node *ptrOne = polynomialOne;
    node *ptrTwo = polynomialTwo;
    node *result = NULL;

    while (ptrOne != NULL && ptrTwo != NULL)
    {
        if (ptrOne->exp == ptrTwo->exp)
        {
            int coef = ptrOne->coef + ptrTwo->coef;
            result = insertNode(result, coef, ptrOne->exp);
            ptrOne = ptrOne->next;
            ptrTwo = ptrTwo->next;
        }
        else if (ptrOne->exp > ptrTwo->exp)
        {
            result = insertNode(result, ptrOne->coef, ptrOne->exp);
            ptrOne = ptrOne->next;
        }
        else if (ptrOne->exp < ptrTwo->exp)
        {
            result = insertNode(result, ptrTwo->coef, ptrTwo->exp);
            ptrTwo = ptrTwo->next;
        }
    }
    while (ptrOne != NULL)
    {
        result = insertNode(result, ptrOne->coef, ptrOne->exp);
        ptrOne = ptrOne->next;
    }

    while (ptrTwo != NULL)
    {
        result = insertNode(result, ptrTwo->coef, ptrTwo->exp);
        ptrTwo = ptrTwo->next;
    }

    printf("\n Added Polynomial is: ");
    printPolynomial(result);
}

void main()
{
    node *polynomialOne = NULL;
    node *polynomialTwo = NULL;

    printf("\n Enter the first polynomial: ");
    polynomialOne = createNode(polynomialOne);

    printf("\n Enter the second polynomial: ");
    polynomialTwo = createNode(polynomialTwo);

    printPolynomial(polynomialOne);
    printf("\n");

    printPolynomial(polynomialTwo);
    printf("\n");

    polynomialAddition(polynomialOne, polynomialTwo);
}