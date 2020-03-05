/*****************************************************************************
File name: ElaineDataS/DS/C/heap/heap.h
Description: heap function
Author: Elaine Sun
Date: 20-03-05
*****************************************************************************/
#define MAX_HEAP_SIZE 1<<7

typedef struct Data_s{
    int data;
}DATA_S;

typedef struct Heap{
    int dnum;
    DATA_S* dheap[MAX_HEAP_SIZE];
}HEAP_S;
