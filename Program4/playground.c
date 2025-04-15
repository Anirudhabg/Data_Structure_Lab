// Write a C program to simulate the working of a singly linked list providing the following operations: a. Display &
// Insert b. Delete from the beginning/end c. Delete a given element

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Node
{
    int data;
    struct Node *next;
} node;

node *head = NULL;

int countNode()
{
    node *ptr = head;
    int i = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        i++;
    }
    return i;
}

bool isEmpty()
{
    if (countNode() <= 0)
    {
        printf("\nList is Empty");
    }
    return countNode() <= 0;
}

void freeAllNodes()
{
    node *ptr = head;
    while (ptr != NULL)
    {
        node *temp = ptr;
        ptr = ptr->next;
        free(temp);
    }
    head = NULL;
}

void printList()
{
    node *ptr = head;
    if (!isEmpty())
    {
        printf("\n List is: \t");
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->next;
        }
        printf("\n");
    }
}

void insertAtBeginning()
{
    node *newnode = (node *)malloc(sizeof(node));
    printf("\n Insert: ");
    scanf("%d", &newnode->data);
    newnode->next = head;
    head = newnode;
    printf("Element inserted in the beginning!!\n");
}

void insertAtEnd()
{
    node *newnode = (node *)malloc(sizeof(node));
    node *ptr = head;
    if (head == NULL)
    {
        insertAtBeginning();
        return;
    }
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    printf("\n Insert: ");
    scanf("%d", &newnode->data);
    ptr->next = newnode;
    newnode->next = NULL;
    printf("Element inserted in the end!!\n");
}

void deleteAtBeginning()
{
    node *ptr = head;
    if (!isEmpty())
    {
        head = head->next;
        printf("%d is deleted from the beginning of the list.\n", ptr->data);
        free(ptr);
    }
}

void deleteAtEnd()
{
    node *ptr = head;
    node *prev;
    int n = countNode();
    if (n == 1)
    {
        deleteAtBeginning();
        return;
    }
    if (!isEmpty())
    {
        while (ptr->next != NULL)
        {
            prev = ptr;
            ptr = ptr->next;
        }
        prev->next = NULL;
        printf("%d is deleted from the end of the list.\n", ptr->data);
        free(ptr);
    }
}

void deleteFromValue()
{
    if (!isEmpty())
    {
        int value;

        printf("\nEnter the value to delete: ");
        scanf("%d", &value);

        node *ptr = head;
        node *prev = NULL;

        while (ptr != NULL && ptr->data != value)
        {
            prev = ptr;
            ptr = ptr->next;
        }

        if (ptr == NULL)
        {
            printf("Value %d not found in the list.\n", value);
            return;
        }

        if (prev == NULL) // value is in the head
        {
            head = head->next;
        }
        else
        {
            prev->next = ptr->next;
        }

        printf("%d is deleted from the list.\n", ptr->data);
        free(ptr);
    }
}

void deleteFromTheGivenIndex()
{
    node *ptr = head;
    node *prev;

    int i = 0;
    int pos;
    int n = countNode();
    if (n == 1)
    {
        deleteAtBeginning();
        return;
    }
    if (!isEmpty())
    {
        printf("\nEnter Index: ");
        scanf("%d", &pos);

        if (pos < 0 || pos > n + 1)
        {
            printf("Index not found!! \n");
            return;
        }
        while (i != pos - 1)
        {
            prev = ptr;
            ptr = ptr->next;
            i++;
        }
        prev->next = ptr->next;
        ptr->next = NULL;

        printf("%d is deleted from the index %d of the list.\n", ptr->data, pos);
        free(ptr);
    }
}

void main()
{
    int choice, insertChoice, deleteChoice;
    while (1)
    {
        printf("\n 1. Insert\t 2. Delete\t 3. Display\t 4. Exit\n Choose any one option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\n 1. Insert at Beginning\t 2. Insert at End \t 3. Exit\n Choose any one option: ");
            scanf("%d", &insertChoice);
            switch (insertChoice)
            {
            case 1:
                insertAtBeginning();
                break;
            case 2:
                insertAtEnd();
                break;
            case 3:
                break;
            default:
                printf("\n Invalid Choice !!!");
            }
            break;
        case 2:
            if (!isEmpty())
            {
                printf("\n 1. Delete at Beginning\t 2. Delete at End\t 3. Delete from the Given Index\t 4. Delete from Value\t 5. Exit\n Choose any one option: ");
                scanf("%d", &deleteChoice);
                switch (deleteChoice)
                {
                case 1:
                    deleteAtBeginning();
                    break;
                case 2:
                    deleteAtEnd();
                    break;
                case 3:
                    deleteFromTheGivenIndex();
                    break;
                case 4:
                    deleteFromValue();
                    break;
                case 5:
                    break;
                default:
                    printf("\n Invalid Choice !!!");
                }
            }
            break;
        case 3:
            printList();
            break;
        case 4:
            freeAllNodes();
            exit(0);
            break;
        default:
            printf("\n Invalid Choice !!!");
        }
    }
}