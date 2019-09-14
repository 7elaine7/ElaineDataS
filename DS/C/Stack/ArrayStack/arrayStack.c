/*****************************************************************************
File name: ElaineDataS/DS/C/Stack/ArrayStack/arrayStack.c
Description: Array Stack common function
Author: Elaine Sun
Date: 19-09-14
*****************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "arrayStack.h"

//创建并初始化顺序栈
ArrayStack* creat_arrayStack(int size)
{
    ArrayStack *ps = NULL;
    ps = (ArrayStack*)malloc(sizeof(ArrayStack));
    if( ps == NULL)
    {
        printf("Fail to allocate the memory!\n");
        return NULL;
    }

    ps->size = size;
    ps->num = -1;  //初始化空，没有元素
    ps->array = (int*)malloc(sizeof(int) * size);  //为栈数据分配size大的空间
    if(ps->array == NULL)
    {
        printf("Fail to allocate memery for stack!\n");
    }

    return ps;
}

void destroy_arrayStack(ArrayStack* p)
{
    if(p == NULL)
        return;
    if(p->array != NULL)
    {
        free(p->array);
    }
    free(p);
    printf("The Stack destroy success!\n");
    return;
}

int pop_arrayStack(ArrayStack *p)
{
    int value;
    if(p->num == -1)
    {
        printf("The stack is empty!\n");
        return EXIT_FAILURE;
    }

    value = p->array[p->num];
    p->num--;

    return value;
}

int push_arrayStack(ArrayStack *p, int value)
{
    if(Full_arrayStack(p))
    {
        printf("The stack is full\n");
        return EXIT_FAILURE;
    }
    p->num++;
    p->array[p->num] = value;
    return EXIT_SUCCESS;
}

int full_push_arrayStack(ArrayStack *p, int value)
{
    int *ptr = (int*)realloc(p->array, sizeof(int) * 2 * (p->size));
    if(ptr == NULL)
    {
        printf("Fail to realloc the new memory!\n");
        return EXIT_FAILURE;
    }

    p->array = ptr;
    p->size = 2*p->size;

    push_arrayStack(p, value);

    return EXIT_SUCCESS;

}

void arrayStackDump(ArrayStack *p)
{
    printf("The stack size is: %d, the stack value number is: %d\n", p->size, p->num + 1);
    for(int i = 0; i <= p->num; i++)
    {
        printf("array[%d] = %d\n", i, p->array[i]);
    }
}

int main(int argv, char *argc[])
{
    int size;
    int value;
    int tmp;
    char ch;
    printf("pls. enter the stack size U want to create:");
    scanf("%d", &size);
    ArrayStack *newps = creat_arrayStack(size);

    while(true)
    {
        printf("pls. enter the push value:");
        fflush(stdin);
        scanf("%d", &value);
        tmp = push_arrayStack(newps, value);
        if(EXIT_FAILURE == tmp)
        {
            printf("Full stack, re-push the value!\n");
            if(EXIT_FAILURE == full_push_arrayStack(newps, value))
            {
                exit(EXIT_FAILURE);
            }
        }
        printf("Do you want to continue to push : Y/N?\n");
        fflush(stdin);
        scanf(" %c", &ch);
        if(ch != 'Y' && ch != 'y')
            break;
    }

    arrayStackDump(newps);

    while(newps->num != -1)
    {
        pop_arrayStack(newps);
    }

    pop_arrayStack(newps);
    destroy_arrayStack(newps);

    return EXIT_SUCCESS;

}
