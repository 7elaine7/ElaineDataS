#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    //空间的大小
    int size;
    //已经使用的空间大小
    int len;
    //存放数据的指针
    int *p;
}Array;

#define ERROR -1

void dump(Array *array);
int alloc(Array *array);
int relloc(Array *array, int num);
int insert(Array *array, int value);
int search(Array *array, int value);
int delete(Array *array, int pos);

