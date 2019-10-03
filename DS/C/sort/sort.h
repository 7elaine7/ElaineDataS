/*****************************************************************************
File name: ElaineDataS/DS/C/sort/sort.h
Description: sort function
Author: Elaine Sun
Date: 19-09-24
*****************************************************************************/

typedef struct Array{
    int size;
    int *array;
}ARRAY_S;

typedef struct Bucket{
    int node[10];
    int count;
}BUCKET;

