/*****************************************************************************
File name: ElaineDataS/DS/C/Stack/ArrayStack/arrayStack.h
Description: Array Stack common function
Author: Elaine Sun
Version: 
Date: 
History: 
*****************************************************************************/

typedef struct Stack{
    int size;       //栈的大小
    int num;        //当前存储元素的个数index
    int *array;     //栈数组数据存储首地址
}ArrayStack;

#define Full_arrayStack(pstack) (pstack->num == (pstack->size - 1))