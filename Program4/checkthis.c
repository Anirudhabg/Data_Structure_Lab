#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

node *createNode(int value)
{
    node *newnode = (node *)malloc(sizeof(node));
    if (newnode)
    {
        newnode->data = value;
        newnode->next = NULL;
    }
    return newnode;
}

int countNode()
{
    int count = 0;
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        count++;
    }
    return count;
}

bool isEmpty()
{
    return head == NULL;
}

void freeAllNodes()
{
    node *ptr;
    while (head)
    {
        ptr = head;
        head = head->next;
        free(ptr);
    }
}

void printList()
{
    if (isEmpty())
    {
        printf("\nList is empty!\n");
        return;
    }
    printf("\nList: ");
    for (node *ptr = head; ptr != NULL; ptr = ptr->next)
    {
        printf("%d ", ptr->data);
    }
    printf("\n");
}

void insertAtBeginning(int value)
{
    node *newnode = createNode(value);
    if (newnode)
    {
        newnode->next = head;
        head = newnode;
        printf("Element inserted at the beginning.\n");
    }
}

void insertAtEnd(int value)
{
    node *newnode = createNode(value);
    if (newnode)
    {
        if (isEmpty())
        {
            head = newnode;
        }
        else
        {
            node *ptr = head;
            while (ptr->next)
                ptr = ptr->next;
            ptr->next = newnode;
        }
        printf("Element inserted at the end.\n");
    }
}

void insertAtGivenIndex(int value, int pos)
{
    int n = countNode();
    if (pos < 0 || pos > n)
    {
        printf("Index out of bounds!\n");
        return;
    }
    node *newnode = createNode(value);
    if (newnode)
    {
        if (pos == 0)
        {
            newnode->next = head;
            head = newnode;
        }
        else
        {
            node *ptr = head;
            for (int i = 1; i < pos; i++)
                ptr = ptr->next;
            newnode->next = ptr->next;
            ptr->next = newnode;
        }
        printf("Element inserted at position %d.\n", pos);
    }
}

void deleteAtBeginning()
{
    if (isEmpty())
    {
        printf("List is empty.\n");
        return;
    }
    node *ptr = head;
    head = head->next;
    printf("Element %d deleted from the beginning.\n", ptr->data);
    free(ptr);
}

void deleteAtEnd()
{
    if (isEmpty())
    {
        printf("List is empty.\n");
        return;
    }
    node *ptr = head, *prev = NULL;
    while (ptr->next)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev)
    {
        prev->next = NULL;
    }
    else
    {
        head = NULL;
    }
    printf("Element %d deleted from the end.\n", ptr->data);
    free(ptr);
}

void deleteFromGivenIndex(int pos)
{
    int n = countNode();
    if (pos < 0 || pos >= n)
    {
        printf("Index out of bounds!\n");
        return;
    }
    node *ptr = head, *prev = NULL;
    for (int i = 0; i < pos; i++)
    {
        prev = ptr;
        ptr = ptr->next;
    }
    if (prev)
    {
        prev->next = ptr->next;
    }
    else
    {
        head = ptr->next;
    }
    printf("Element %d deleted from position %d.\n", ptr->data, pos);
    free(ptr);
}

int main()
{
    int choice, insertChoice, insertValue, deleteChoice, index;

    while (1)
    {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nChoose an option: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &insertValue);
            printf("\n1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\nChoose an option: ");
            scanf("%d", &insertChoice);
            if (insertChoice == 1)
                insertAtBeginning(insertValue);
            else if (insertChoice == 2)
                insertAtEnd(insertValue);
            else if (insertChoice == 3)
            {
                printf("Enter position: ");
                scanf("%d", &index);
                insertAtGivenIndex(insertValue, index);
            }
            break;

        case 2:
            if (isEmpty())
            {
                printf("List is empty.\n");
                break;
            }
            printf("\n1. Delete from Beginning\n2. Delete from End\n3. Delete from Position\nChoose an option: ");
            scanf("%d", &deleteChoice);
            if (deleteChoice == 1)
                deleteAtBeginning();
            else if (deleteChoice == 2)
                deleteAtEnd();
            else if (deleteChoice == 3)
            {
                printf("Enter position: ");
                scanf("%d", &index);
                deleteFromGivenIndex(index);
            }
            break;

        case 3:
            printList();
            break;

        case 4:
            freeAllNodes();
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }
}
