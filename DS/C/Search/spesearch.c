/*****************************************************************************
File name: ElaineDataS/DS/C/search/spesearch.c
Description: 
1. 查找第一个值等于给定值的元素
2. 查找最后一个值等于给定值的元素
3. 查找第一个大于等于给定值的元素
4. 查找最后一个小于等于给定值的元素
Author: Elaine Sun
Date: 19-11-06
*****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ERR -1

int search_first_eq(int *arr, int size, int value)
{
    int left  = 0;
    int right = size - 1;
    int mid;
    while(left <= right)
    {
        mid = left + ((right - left) >> 1);
        if(arr[mid] == value)
        {
            if((arr[mid - 1] != value) || mid == 0 )
                return mid;
            else
            {
                right = mid - 1;
            }
        }
        else if(arr[mid] < value)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }        
    }
    return ERR;
}

int search_last_eq(int *arr, int size, int value)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while(left <= right)
    {
        mid = left + ((right - left) >> 1);
        if(arr[mid] == value)
        {
            if((mid == size - 1) || arr[mid + 1] != value)
            {
                return mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        else if(arr[mid] > value)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ERR;
}

int search_first(int *arr, int size, int value)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while(left <= right)
    {
        mid = left + ((right - left) >> 1);
        if(arr[mid] >= value)
        {
            if((arr[mid - 1] < value) || mid == 0)
                return mid;
            else
                right = mid - 1;
        }
        else
            left = mid + 1;
    }
    return ERR;
}

int search_last(int *arr, int size, int value)
{
    int left = 0;
    int right = size - 1;
    int mid;

    while(left <= right)
    {
        mid = left + ((right - left) >> 1);
        if(arr[mid] <= value)
        {
            if((arr[mid + 1] > value) || mid == size - 1)
                return mid;
            else
                left = mid + 1;
        }
        else
            right = mid - 1;
    }
    return ERR;
}

int main(int argv, char *argc[])
{
    int array[12] = {1, 2, 7, 7, 7, 8, 77, 77, 177, 520, 777, 777};
    int size = sizeof(array) / sizeof(array[0]);
   int value;

    while(true)
    {
        printf("Pls. enter the value you want to find:");
        scanf("%d", &value);

        int result = search_last(array, size, value);
        if(ERR == result)
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