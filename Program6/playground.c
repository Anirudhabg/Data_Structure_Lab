// Write a C program to implement the following sorting algorithms using user defined functions:
// a. Bubble sort (Ascending order) b. Selection sort (Descending order).

#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int array[50], int n)
{
    printf("\n -- Bubble Sort (Ascending Order) --");
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < n - i - 1)
        {
            if (array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
            j++;
        }
    }

    printf("\n Array is:\t");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
}

void selectionSort(int array[50], int n)
{
    printf("\n -- Selection Sort (Descending Order) --");
    for (int i = 0; i < n; i++)
    {
        int max = i;
        for (int j = i + 1; j < n; j++)
        {
            if (array[j] > array[max])
            {
                max = j;
            }
        }
        int temp = array[i];
        array[i] = array[max];
        array[max] = temp;
    }

    printf("\n Array is:\t");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t", array[i]);
    }
}

void main()
{
    int array[50];
    int n, ele, choice;

    printf("\n Enter the size of the array: ");
    scanf("%d", &n);

    printf("\n Enter the array elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    while (1)
    {
        printf("\n 1. Bubble Sort\t 2. Selection Sort\t 3. Exit\n Choose any one option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            bubbleSort(array, n);
            break;
        case 2:
            selectionSort(array, n);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\n Invalid Option !!");
        }
    }
}