/*****************************************************************************
File name: ElaineDataS/DS/C/Recursion/climbing.c
Description: Bubble Sort, Insertion Sort, Selection Sort, 
Author: Elaine Sun
Date: 19-09-22
*****************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Array{
    int size;
    int *array;
}ARRAY_S;

void Bubble_Sort(ARRAY_S *array_s)
{
    bool finish;
    int i, j;
    for(i = 0; i < array_s->size; i++)
    {
        finish = true;
        for(j = 0; j < array_s->size - i -1; j++)
        {
            if(array_s->array[j] > array_s->array[j+1])
            {
                finish = false;
                int tmp = array_s->array[j];
                array_s->array[j] = array_s->array[j+1];
                array_s->array[j+1] = tmp;
            }
        }
        if(true == finish)
        {
            printf("Finish sort, i = %d, j = %d\n", i, j);
            break;
        }
    }
}

void Insertion_Sort(ARRAY_S *array_s)
{
    int i, j;
    for(i = 1; i< array_s->size; i++)
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
    int min;
    int index;


    for(i = 0; i < array_s->size; i++)
    {
        index = i;
        for(j = i; j < array_s->size; j++)
        {
            if(array_s->array[j] <array_s->array[index])
            {
                index = j;
            }

        } 

        min = array_s->array[index];
        array_s->array[index] = array_s->array[i];
        array_s->array[i] = min;
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