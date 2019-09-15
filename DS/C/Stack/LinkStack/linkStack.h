/*****************************************************************************
File name: ElaineDataS/DS/C/Stack/Stack/LinkStack/linkStack.h
Description: Linked Stack common function
Author: Elaine Sun
Date: 19-09-15
*****************************************************************************/

typedef struct Stack{
    int data;
    struct Stack *next;
}LinkStack;

#define ERROR -1