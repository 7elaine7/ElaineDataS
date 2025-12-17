/*****************************************************************************
File name: ElaineDataS/DS/C/sort/sort_1.c
Description: Bubble Sort, Insertion Sort, Selection Sort, 
Author: Elaine Sun
Date: 19-09-22
*****************************************************************************/
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void Bubble_Sort(ARRAY_S *array_s)
{
    if(array_s->size <= 1)
        return;
    bool finish;
    int i, j;
    for(i = 0; i < array_s->size; ++i)
    {
        finish = true;
        for(j = 0; j < array_s->size - i -1; j++)
        {
            if(array_s->array[j] > array_s->array[j+1])
            {
                int tmp = array_s->array[j];
                array_s->array[j] = array_s->array[j+1];
                array_s->array[j+1] = tmp;
                finish = false;
            }
        }
        if(finish)
        {
            break;
        }
    }
}

void Insertion_Sort(ARRAY_S *array_s)
{
    if(array_s->size <= 1)
        return;
    int i, j;
    for(i = 1; i< array_s->size; ++i)
    {
        int value = array_s->array[i];
        j = i-1;
        for(; j >=0; j--)
        {
            if(value < array_s->array[j])
            {
                array_s->array[j+1] = array_s->array[j];
            }
            else
                break;
        }
        array_s->array[j+1] = value;
    }
}

void Selection_Sort(ARRAY_S *array_s)
{
    int i,j;

    if(array_s->size <= 1)
        return;
    
    for(i = 0; i < array_s->size - 1; ++i)
    {
        int min = i;
        for(j = i + 1; j < array_s->size; ++j)
        {
            if(array_s->array[j] < array_s->array[min])
                min = j;
        }
        if(min != i)
        {
            int tmp = array_s->array[i];
            array_s->array[i] = array_s->array[min];
            array_s->array[min] = tmp;        
        }

    }
}


void dump(ARRAY_S *array_s)
{
    int i;
    for(i = 0; i < array_s->size; i++)
    {
        printf("array[%d] = %d\n", i, array_s->array[i]);
    }
}

int main(int argv, char *argc[])
{
    ARRAY_S *array_s = (ARRAY_S*)malloc(sizeof(ARRAY_S));
    if(NULL == array_s)
    {
        printf("Fail to allocate memory!\n");
        return EXIT_SUCCESS;
    }

    int array[] = {9, 3, 6, 7, 1, 5, 7};
    array_s->array = array;
    array_s->size = sizeof(array)/sizeof(array[0]);

//    Bubble_Sort(array_s);
//    Insertion_Sort(array_s);
    Selection_Sort(array_s);

    dump(array_s);

    return EXIT_SUCCESS;
}