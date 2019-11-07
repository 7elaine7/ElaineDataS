/*****************************************************************************
File name: ElaineDataS/DS/C/search/bsearch.c
Description: Binary search
Author: Elaine Sun
Date: 19-11-06
*****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int binarysearch(int *arr, int size, int value)
{
    int low = 0;
    int high = size-1;
    int mid;
    while(low <= high)
    {
        mid = low + ((high - low) >> 1);
        if(arr[mid] == value)
        {
            return mid;
        }
        else if(value > arr[mid])
        {   
            low = mid + 1;
        }
        else if(value < arr[mid])
        {
            high = mid - 1;
        }
        
    }
    return -1;
}

int binarysearch_r(int *arr, int low, int high, int value)
{
    if(low > high)
    {
        return -1;
    }

    int mid = low + ((high - low) >> 1);
    if(arr[mid] == value)
        return mid;

    else if(value > arr[mid])
        return binarysearch_r(arr, mid + 1, high, value);
    else if(value < arr[mid])
        return binarysearch_r(arr, low, mid - 1, value);
    return -1;   
}

int main(int argv, char *argc[])
{
    int array[10] = {0, 1, 2, 7, 8, 17, 77, 177, 520, 777};
    int size = sizeof(array) / sizeof(array[0]);
    int value;

    while(true)
    {
        printf("Pls. enter the value you want to find:");
        scanf("%d", &value);
        //int result = binarysearch(array, size, value);
        int result = binarysearch_r(array, 0, size-1, value);
        if(-1 == result)
        {
            printf("No value in the array!\n");
        }
        else
        {
            printf("The index for value in the array is: %d\n", result);
        }
        printf("Do you want to continue to find? Y/N\n");
        char ch;
        scanf(" %c", &ch);
        if(ch != 'Y' && ch != 'y')
            break;
    }
    return EXIT_SUCCESS;
}