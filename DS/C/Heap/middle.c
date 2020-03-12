/*****************************************************************************
File name: ElaineDataS/DS/C/heap/middle.c
Description: 求中位数
Author: Elaine Sun
Date: 20-03-09
*****************************************************************************/
#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void fill_heap(DHEAP *heap, int *array, int start, int end)
{
    int count = 0;
    for(int n = start; n <= end; n++)
    {
        heap->heap[count+1] = array[n];
        count++;
    }
    heap->count = count;
}

void swap(DHEAP *heap, int m, int n)
{
    int tmp = heap->heap[m];
    heap->heap[m] = heap->heap[n];
    heap->heap[n] = tmp;
}

//小顶堆
void heapify_small(DHEAP *heap, int parent)
{
    int min, left, right;

    while(true)
    {
        min = parent;
        left = parent * 2;
        right = parent * 2 + 1;
        if(left <= heap->count && heap->heap[left] < heap->heap[parent])
        {
            min = left;
        }
        if(right <= heap->count && heap->heap[right] < heap->heap[min])
        {
            min = right;
        }
        if(min == parent)
            break;
        swap(heap, parent, min);
        parent = min;
    }
}

void build_small_heap(DHEAP *heap)
{
    for(int n = heap->count / 2; n > 0; n--)
    {
        heapify_small(heap, n);
    }
}

//小顶堆排序从大到小
void sort_small_heap(DHEAP *heap)
{
    int tmp = heap->count;
    while(heap->count > 1)
    {
        build_small_heap(heap);
        swap(heap, 1, heap->count);
        heap->count--;
    }
    heap->count = tmp;
}

//大顶堆
void heapify_big(DHEAP *heap, int parent)
{
    int max, left, right;

    while(true)
    {
        max = parent;
        left = parent * 2;
        right = parent * 2 + 1;
        if(left <= heap->count && heap->heap[left] > heap->heap[parent])
        {
            max = left;
        }
        if(right <= heap->count && heap->heap[right] > heap->heap[max])
        {
            max = right;
        }
        if(max == parent)
            break;
        swap(heap, parent, max);
        parent = max;
    }
}

void build_big_heap(DHEAP *heap)
{
    for(int n = heap->count / 2; n > 0; n--)
    {
        heapify_big(heap, n);
    }
}

//大顶堆排序从小到大
void sort_big_heap(DHEAP *heap)
{
    int tmp = heap->count;
    while(heap->count > 1)
    {
        build_big_heap(heap);
        swap(heap, 1, heap->count);
        heap->count--;
    }
    heap->count = tmp;
}

void dump(DHEAP *heap)
{
    for(int n = 1; n <= heap->count; n++)
    {
        printf("[%02d] = %4d\n", n, heap->heap[n]);
    }
}

int main(int argc, char *argv[])
{
    int array[10] = {7, 77, 1, 17, 12, 38, 27, 66, 5, 26};
    int size = sizeof(array) / sizeof(array[0]);
    DHEAP heap;
    int value;

    fill_heap(&heap, array, 0, 9);
    dump(&heap);
    printf("Sort from small to large!\n");
    sort_big_heap(&heap);
    dump(&heap);

    DHEAP heap1, heap2;
    fill_heap(&heap1, (&heap)->heap, 1, 5);
    printf("Build the large heap:\n");
    build_big_heap(&heap1);
    dump(&heap1);

    fill_heap(&heap2, (&heap)->heap, 6, 10);
    printf("Build the small heap:\n");
    build_small_heap(&heap2);
    dump(&heap2);
    
    while(true)
    {
        if(size >= HEAP_SIZE*2 - 4)
        {
            printf("Heap is full!\n");
            break;
        }
        printf("pls. insert the data:\n");
        scanf("%d", &value);
        if(value <= (&heap1)->heap[1])
        {
            (&heap1)->heap[(&heap1)->count+1] = value;
            (&heap1)->count++;
        }
        else if(value >= (&heap2)->heap[1])
        {
            (&heap2)->heap[(&heap2)->count+1] = value;
            (&heap2)->count++;
        }
        else
        {
            (&heap1)->heap[(&heap1)->count+1] = value;
            (&heap1)->count++;
            build_big_heap(&heap1);
        }
        size++;
        if(size % 2 == 0)//偶数
        {
            if((&heap1)->count != size/2)
            {
                (&heap2)->heap[(&heap2)->count+1] = (&heap1)->heap[1];
                swap(&heap1, 1, (&heap1)->count);
                (&heap2)->count++;
                (&heap1)->count--;
            }
        }
        else//奇数
        {
            if((&heap1)->count != size/2 + 1)
            {
                (&heap1)->heap[(&heap1)->count+1] = (&heap2)->heap[1];
                swap(&heap2, 1, (&heap2)->count);
                (&heap1)->count++;
                (&heap2)->count--;
            }
        }
        build_big_heap(&heap1);
        build_small_heap(&heap2);
        printf("The middle number is: %d\n", (&heap1)->heap[1]);

        printf("Do you want to continue to insert? Y/N:\n");
        char ch;
        scanf(" %c", &ch);
        if(ch != 'Y' && ch != 'y')
            break;
    }
    return EXIT_SUCCESS;

}