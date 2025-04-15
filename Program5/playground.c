// Write a C program to Implement the following searching techniques a. Linear Search b. Binary Search.

#include <stdio.h>
#include<stdlib.h>
void linearSearch(int array[50], int n, int ele)
{
    printf("\n--Linear Search--");
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (array[i] == ele)
        {
            printf("\n %d found at position %d", ele, i + 1);
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("\n %d is not found in the given array.", ele);
    }
}

void binarySearch(int array[50], int n, int ele)
{
    printf("\n--Binary Search--");
    int flag = 0;
    int left = 0;
    int right = n - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (array[mid] == ele)
        {
            printf("\n %d found at position %d", ele, mid + 1);
            flag = 1;
            break;
        }
        else if (ele < array[mid])
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    if (flag == 0)
    {
        printf("\n %d is not found in the given array.", ele);
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

    printf("\n Enter the element to search: ");
    scanf("%d", &ele);

    while (1)
    {
        printf("\n 1. Linear Search\t 2. Binary Search\t 3. Exit\n Choose any one option: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            linearSearch(array, n, ele);
            break;
        case 2:
            binarySearch(array, n, ele);
            break;
        case 3:
            exit(0);
            break;
        default:
            printf("\n Invalid Option !!");
        }
    }
}