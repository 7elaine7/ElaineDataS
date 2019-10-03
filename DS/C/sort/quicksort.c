/*****************************************************************************
File name: ElaineDataS/DS/C/sort/quicksort.c
Description: Quick sort
Author: Elaine Sun
Date: 19-09-30
*****************************************************************************/
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>

void dump(ARRAY_S *array_s)
{
    int i = 0;
    for(; i < array_s->size; i++)
    {
        printf("%s::%s: array[%d] = %d\n", __FILE__, __FUNCTION__, i, array_s->array[i]);
    }
}
int select_q(ARRAY_S *array_s, int n1, int n2)
{
    int q = array_s->array[n2];
    int i = n1;
    int j = n1;
    int tmp;
    for(; j<n2; j++)
    {
        if(array_s->array[j] < q)
        {
            tmp = array_s->array[j];
            array_s->array[j] = array_s->array[i];
            array_s->array[i] = tmp;
            i++;
        }
    }
    array_s->array[n2] = array_s->array[i];
    array_s->array[i] = q;

    return i;
}
void quicksort(ARRAY_S* array_s, int n1, int n2)
{
    if(n1 >= n2)
        return;
    
    int q = select_q(array_s, n1, n2);
    quicksort(array_s, n1, q-1);
    quicksort(array_s, q+1, n2);
}

