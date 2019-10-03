/*****************************************************************************
File name: ElaineDataS/DS/C/sort/sort_2.c
Description: Merge sort
Author: Elaine Sun
Date: 19-09-24
*****************************************************************************/
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void dump(ARRAY_S *array_s)
{
    int i;
    for(i = 0; i < array_s->size; i++)
    {
        printf("array[%d] = %d\n", i, array_s->array[i]);
    }
}
void Merge(ARRAY_S *array, int n1, int start, int n2)
{
    int *arr = NULL;
    int num = 0;
    int s1 = n1;
    int s2 = start;

    int size = n2 - n1 + 1;

    arr  = (int*)malloc(sizeof(int) * (size+1));

    if(NULL == arr)
    {
        printf("Fail to allocate the memory!\n");
        return;
    }

    while((s1 < start) && (s2 <= n2))
    {
        if(array->array[s1] <= array->array[s2])
        {
            arr[num] = array->array[s1];
            s1++;
        }
        else
        {
            arr[num] = array->array[s2];
            s2++;
        }
        num++;
    }

    if(s1 == start)
    {
        memcpy(&(array->array[n1]), arr, sizeof(int) * (num));
    }
    else if(s2 > n2)
    {
        memcpy(&arr[num], &(array->array[s1]), sizeof(int) * (size - num));
        memcpy(&(array->array[n1]), arr, sizeof(int) * size);
    }

    if(NULL != arr)
    {
        free(arr);
        arr = NULL;
    }

}
void Merge_sort(ARRAY_S *array, int num1, int num2)
{
    if(num1 >= num2)
        return;

    int mid = (num1 + num2) / 2; 

    Merge_sort(array, num1, mid);
    Merge_sort(array, mid+1, num2);    

    Merge(array, num1, mid+1, num2);
}


int main(int argv, char *argc[])
{
    ARRAY_S *array_s = (ARRAY_S*)malloc(sizeof(ARRAY_S));
    if(NULL == array_s)
    {
        printf("Fail to allocate memory!\n");
        return EXIT_SUCCESS;
    }
    int array[10] = {2, 9, 6, 8, 1, 7, 3, 7, 10, 12}; 
    array_s->array = array;
    array_s->size = sizeof(array) / sizeof(array[0]);

    Merge_sort(array_s, 0, array_s->size-1);
    dump(array_s);

    if(NULL != array_s)
    {
        free(array_s);
        array_s = NULL;
    }

    return EXIT_SUCCESS;
}