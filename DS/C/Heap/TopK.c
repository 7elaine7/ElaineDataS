/*****************************************************************************
File name: ElaineDataS/DS/C/heap/TopK.c
Description: 求数组的Top K
Author: Elaine Sun
Date: 20-03-09
*****************************************************************************/
#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//  求数组中top 7的值
void init_heap(HEAP_S *heap)
{
    for(int n = 0; n < MAX_HEAP_SIZE; n++)
    {
        heap->dheap[n] = NULL;
    }
    heap->dnum = 0;
}

DATA_S* create_data(int data)
{
    DATA_S* data_s;
    data_s = (DATA_S*)malloc(sizeof(DATA_S));

    if(data_s)
    {
        data_s->data = data;
    }
    else
    {
        printf("Fail to malloc!\n");
    }
    return data_s;
}
void fill_heap(HEAP_S* heap, int* array, int num)
{
    
    for(int n = 0; n < num; n++)
    {
        heap->dheap[n+1] =  create_data(array[n]);
    }
    heap->dnum = num;
}

void swap(HEAP_S *heap, int m, int n)
{
    DATA_S *tmp;
    tmp = heap->dheap[m];
    heap->dheap[m] = heap->dheap[n];
    heap->dheap[n] = tmp;
}

void heapify(HEAP_S* heap, int parent)
{
    int min, left, right;
    while(true)
    {
        min = parent;
        left = parent*2;
        right = parent*2+1;
        if(left <= heap->dnum && heap->dheap[parent]->data > heap->dheap[left]->data)
        {
            min = left;
        }
        if(right <= heap->dnum && heap->dheap[right]->data < heap->dheap[min]->data)
        {
            min = right;
        }
        if(min == parent)
            break;
        swap(heap, parent, min);
        parent = min;
    }
}

//建小顶堆
void build_heap(HEAP_S *heap)
{
    for(int n = heap->dnum / 2; n > 0; n--)
    {
        heapify(heap, n);
    }
}

void dump(HEAP_S *heap)
{
    for(int n = 1; n <= heap->dnum; n++)
    {
        printf("[%02d] = %4d\n", n, heap->dheap[n]->data);
    }
}

int main(int argc, char *argv[])
{
    HEAP_S heap;   
    int array[17] = {7, 17, 9, 1, 2, 7, 77, 8, 16, 52, 27, 6, 277, 66, 1, 88, 16};
    int array_size = sizeof(array) / sizeof(array[0]);
    int value;

    init_heap(&heap);

    while(true)
    {
        printf("Pls. enter the Top count do you want to get:\n");
        scanf("%d", &value);
        if(value > array_size)
        {
            printf("The Top count is out of the range, pls. re-enter!\n");
        }
        else
        {
            printf("Top %d will list~~\n", value);
            break;
        }
    }

    fill_heap(&heap, array, value);
    dump(&heap);

    printf("After build heap:\n");
    build_heap(&heap);
    dump(&heap);

    for(int n = value; n < array_size; n++)
    {
        if((&heap)->dheap[1]->data < array[n])
        {
            (&heap)->dheap[1]->data = array[n];
            build_heap(&heap);
        }
    }

    printf("The top %d is:\n", value);
    dump(&heap);
    
    return EXIT_SUCCESS;

}

