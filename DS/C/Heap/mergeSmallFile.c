/*****************************************************************************
File name: ElaineDataS/DS/C/heap/mergeSmallFile.c
Description: 将几个有序数组合并成一个有序数组
Author: Elaine Sun
Date: 20-03-08
*****************************************************************************/

#include "heap.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void init_heap(GHEAP* heap)
{
    for(int n = 0; n < MAX_HEAP_SIZE; ++n)
    {
        heap->gheap[n] = NULL;
    }
    heap->num = 0;
}

GDATA* create_data(int data, char group)
{
    GDATA *gdata;
    gdata = (GDATA*)malloc(sizeof(GDATA));

    if(gdata)
    {
        gdata->data = data;
        gdata->group = group;
    }
    else
    {
        printf("Fail to malloc for data!\n");
    }
    return gdata;
}

void fill_heap(GHEAP* heap)
{
    int num[5] = {2, 6, 10, 1, 12};
    char c[5] = {'A', 'B', 'C', 'D', 'E'};

    for(int i = 0; i < 5; i++)
    {
        heap->gheap[i+1] = create_data(num[i], c[i]);
    }
    heap->num = 5;
}

void swap(GHEAP *heap, int m, int n)
{
    GDATA *tmp;
    tmp = heap->gheap[m];
    heap->gheap[m] = heap->gheap[n];
    heap->gheap[n] = tmp;
}

//堆化
void heapify(GHEAP *heap, int parent)
{
    int min;
    while(true)
    {
        min = parent;
        if(parent*2 <= heap->num && heap->gheap[parent]->data > heap->gheap[parent*2]->data)
        {
            min = parent*2;
        }
        if(parent*2+1 <= heap->num && heap->gheap[parent*2+1]->data < heap->gheap[min]->data)
        {
            min = parent*2+1;
        }
        if(min == parent)
            break;
        swap(heap, parent, min);
        parent = min;
    }
}

//小顶堆
void build_heap(GHEAP *heap)
{
    for(int n = (heap->num) / 2; n > 0; n--)
    {
        heapify(heap, n);
    }
}

//从小到大
void sort_heap(GHEAP *heap)
{
    int n = heap->num;
    while(heap->num > 1)
    {
        build_heap(heap);
        swap(heap, 1, heap->num);
        heap->num--;
    }
    heap->num = n;
}

void dump(GHEAP *heap)
{
    for(int n = 1; n <= heap->num; n++)
    {
        printf("[%02d]: (%c, %4d)\n", n, heap->gheap[n]->group, heap->gheap[n]->data);
    }
}

GDATA* get_data(char group)
{
    int A[6] = {2, 3, 5, 7, 9, 11};
    int B[5] = {6, 8, 17, 28, 32};
    int C[6] = {10, 18, 27, 37, 50, 51};
    int D[7] = {1, 7, 16, 21, 26, 29, 52};
    int E[5] = {12, 15, 25, 27, 77}; 

    static int n1 = 1;
    static int n2 = 1;
    static int n3 = 1;
    static int n4 = 1;
    static int n5 = 1;//第一个值已经被取出
    
    GDATA *gdata;
    gdata = (GDATA*)malloc(sizeof(GDATA));
    if(!gdata)
    {
        printf("Fail to malloc for data!\n");
        return NULL;
    }

    switch(group)
    {
        case 'A':
            if(n1 < 6)
            {
                gdata->data = A[n1];
                gdata->group = 'A';
                n1++;
                break;
            }
        case 'B':
            if(n2 < 5)
            {
                gdata->data = B[n2];
                gdata->group = 'B';
                n2++;
                break;
            }
        case 'C':
            if(n3 < 6)
            {
                gdata->data = C[n3];
                gdata->group = 'C';
                n3++;
                break;
            }
        case 'D':
            if(n4 < 7)
            {
                gdata->data = D[n4];
                gdata->group = 'D';
                n4++;
                break;
            }
        case 'E':
            if(n5 < 5)
            {
                gdata->data = E[n5];
                gdata->group = 'E';
                n5++;
                break;
            }
        default:
            return NULL;
    }

    return gdata;
}

int main(int argc, char *argv[])
{
    GHEAP heap;
    init_heap(&heap);
    fill_heap(&heap);
    //小顶堆
    build_heap(&heap);
    dump(&heap);

    int array[MAX_HEAP_SIZE];
    int count = 0;
    GDATA *tmpdata;
    tmpdata = (GDATA*)malloc(sizeof(GDATA));

    while(true)
    {
        array[count] = (&heap)->gheap[1]->data;
        tmpdata = get_data((&heap)->gheap[1]->group);
        if(tmpdata == NULL)
        {
            break;
        }
        else
        {
            (&heap)->gheap[1] = tmpdata; 
        }
        
        build_heap(&heap);
        count++;
    }

    sort_heap(&heap);
    for(;(&heap)->num > 0; (&heap)->num --)
    {
        array[count] = (&heap)->gheap[(&heap)->num]->data;
        count++;
    }

    for(int n = 0; n < count; n++)
    {
        printf("[%02d]: %4d\n", n, array[n]);
    }
   
    return EXIT_SUCCESS;
}