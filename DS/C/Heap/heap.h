/*****************************************************************************
File name: ElaineDataS/DS/C/heap/heap.h
Description: heap function
Author: Elaine Sun
Date: 20-03-05
*****************************************************************************/
#define MAX_HEAP_SIZE 1<<7
#define HEAP_SIZE 30 

typedef struct Data_s{
    int data;
}DATA_S;

typedef struct Heap{
    int dnum;
    DATA_S* dheap[MAX_HEAP_SIZE];
}HEAP_S;

typedef struct GData{
    char group;
    int data;
}GDATA;

typedef struct GHeap{
    int num;
    GDATA* gheap[MAX_HEAP_SIZE];
}GHEAP;

typedef struct D_Heap{
    int count;
    int heap[HEAP_SIZE];
}DHEAP;