/*****************************************************************************
File name: ElaineDataS/DS/C/Stack/Stack/LinkStack/linkStack.h
Description: Linked Stack common function
Author: Elaine Sun
Date: 19-09-15
*****************************************************************************/

#include "linkStack.h"
#include <stdio.h>      //NULL, printf
#include <stdlib.h>     //malloc
#include <stdbool.h>    //true

LinkStack* creat_linkStack()
{
    LinkStack *pstack = NULL;
    pstack = (LinkStack*)malloc(sizeof(LinkStack));
    if(pstack == NULL)
    {
        printf("Fail to allocate the memory!\n");
        return NULL;
    }
    pstack->next = NULL;
    return pstack;
}

void destroy_linkStack(LinkStack *pstack)
{
    LinkStack *p;
    while(pstack->next!= NULL)
    {
        p = pstack->next;
        pstack->next = pstack->next->next;
        free(p);
    }
    free(pstack);
}

int push_linkStack(LinkStack *pstack, int value)
{
    LinkStack *new = (LinkStack*)malloc(sizeof(LinkStack));
    if(NULL == new)
    {
        printf("Fail to allocate the memory!\n");
        return EXIT_FAILURE;
    }

    new->data = value;
    new->next = pstack->next;
    pstack->next = new;

    return EXIT_SUCCESS;
}

int pop_linkStack(LinkStack *pstack)
{
    LinkStack *tmp;
    if(NULL == pstack->next)
    {
        printf("stack is empty\n");
        return ERROR;
    }
    int value = pstack->next->data;
    tmp = pstack->next;
    pstack->next = tmp->next;
    free(tmp);

    return value;
}

void dump_linkStack(LinkStack *pstack)
{
    LinkStack *p = pstack->next;
    if(NULL == p)
    {
        printf("Empty stack, can not dump!\n");
        return;
    }
    while(p->next != NULL)
    {
        printf("value: %d -> ", p->data);
        p = p->next;
    }
    printf("value: %d\n", p->data);
}

int main(int argv, char *argc[])
{
    LinkStack *stack = NULL;
    int value;
    char ch;
    int data;

    stack = creat_linkStack();
    while(true)
    {
        printf("Pls. enter the value you want to push:");
        scanf("%d", &value);
        if(EXIT_FAILURE == push_linkStack(stack, value))
        {
            printf("Push failed!\n");
            return EXIT_FAILURE;
        }

        printf("If you want to continue to push? Y/N\n");
        scanf(" %s", &ch);
        if(ch != 'Y' && ch != 'y')
            break;
    }

    dump_linkStack(stack);

    data = pop_linkStack(stack);
    if(ERROR == data)
    {
        printf("Pop failed!\n");
    }
    else
    {
        printf("Pop %d success!\n", data);
    }

    data = pop_linkStack(stack);
    if(ERROR == data)
    {
        printf("Pop failed!\n");
    }
    else
    {
        printf("Pop %d success!\n", data);
    }

    dump_linkStack(stack);
    
    destroy_linkStack(stack);

    return EXIT_SUCCESS;

}