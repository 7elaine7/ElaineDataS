/*****************************************************************************
File name: ElaineDataS/DS/C/heap/heap.c
Description: insert, delete, heapify, create
Author: Elaine Sun
Date: 20-03-05
*****************************************************************************/
#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void init_heap(HEAP_S *heap)
{
    int n;
    for(n = 0; n < MAX_HEAP_SIZE; ++n)
    {
        heap->dheap[n] = NULL;
    }
}

DATA_S* create_data(int data)
{
    DATA_S *data_s;
    data_s = (DATA_S*)malloc(sizeof(DATA_S));

    if(data_s)
    {
        data_s->data = data;
    }
    else
    {
        printf("Fail to malloc for data!\n");
    }

    return data_s;
}

void fill_heap(HEAP_S *heap)
{
    int data[10] = {7, 9, 2, 8, 6, 1, 3, 5, 10, 4};
    int n;
    for(n = 0; n < 10; ++n)
        heap->dheap[n+1] = create_data(data[n]);
    heap->dnum = 10;
}

void swap(HEAP_S *heap, int m, int n)
{
    DATA_S *tmp;
    tmp = heap->dheap[m];
    heap->dheap[m] = heap->dheap[n];
    heap->dheap[n] = tmp;
}

//insert then heapify from bottom to top
void insert(HEAP_S *heap, int data)
{
    heap->dheap[heap->dnum+1] = create_data(data);
    heap->dnum++;

    if(heap->dnum > MAX_HEAP_SIZE)
        return;
    int n = heap->dnum;

    while(n/2 > 0 && heap->dheap[n]->data > heap->dheap[n/2]->data)
    {
        swap(heap, n, n/2);
        n = n/2;
    }
}

//heapify from top to bottom
void heapify(HEAP_S *heap, int parent)
{
    int left, right, max;

    while(true)
    {
        left = parent*2;
        right = parent*2 +1;
        max = parent;

        if(left <= heap->dnum && heap->dheap[left]->data > heap->dheap[parent]->data)
        {
            max = left;
        }
        if(right <= heap->dnum && heap->dheap[right]->data > heap->dheap[max]->data)
        {
            max = right;
        }
        if(max == parent)
            break;
        swap(heap, max, parent);
        parent = max;
    }
}

void build_heap(HEAP_S *heap)
{
    int n;
    for(n = heap->dnum / 2; n>0; --n)
    {
        heapify(heap, n);
    }
}

void sort_heap(HEAP_S *heap)
{
    int num = heap->dnum;
    while(heap->dnum)
    {
        build_heap(heap);
        swap(heap, 1, heap->dnum);
        heap->dnum--;
    }
    heap->dnum = num;
}

void dump(HEAP_S *heap)
{
    int n;
    for(n = 1; n <= heap->dnum; ++n)
    {
        printf("[%02d]: %4d\n", n, heap->dheap[n]->data);
    }
}

int main(int argc, char *argv[])
{
    HEAP_S heap;
    init_heap(&heap);
    fill_heap(&heap);
    dump(&heap);

    printf("After Heapify:\n");
    build_heap(&heap);
    dump(&heap);

    printf("After insert 17:\n");
    insert(&heap, 17);
    dump(&heap);

    printf("After insert 7:\n");
    insert(&heap, 7);
    dump(&heap);

    printf("After sort:\n");
    sort_heap(&heap);
    dump(&heap);

    return EXIT_SUCCESS;   
}