/*****************************************************************************
File name: ElaineDataS/DS/C/search/loopbsearch.c
Description: Loop array binary search
Author: Elaine Sun
Date: 19-11-06
*****************************************************************************/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define ERR -1

int loop_bsearch(int *arr, int size, int value)
{
    int low = 0;
    int high = size - 1;
    int mid;
    while(low <= high)
    {
        mid = low + ((high - low) >> 1);
        if(arr[mid] == value)
            return mid;
        if(arr[low] <= arr[mid])    //左边有序
        {
            if((arr[mid] >= value) && (arr[low] <= value))      //value在左边区域
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }            
        }
        else    //mid右边是有序的
        {
            if((arr[mid] <= value) && (arr[high] >= value))    //value在右边的区域
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            } 
        }  
    }
    return ERR;
}

int main(int argv, char *argc[])
{
    int array[8] = {4, 5, 6, 7, 8, 1, 2, 3};
    int size = sizeof(array) / sizeof(array[0]);
    int value;

    while(true)
    {
        printf("Pls. enter the value you want to find:");
        scanf("%d", &value);

        int result = loop_bsearch(array, size, value);
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