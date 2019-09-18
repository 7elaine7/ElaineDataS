/*****************************************************************************
File name: ElaineDataS/DS/C/Queue/LinkQueue/linkQueue.c
Description: Linked Queue common function
Author: Elaine Sun
Date: 19-09-18
*****************************************************************************/

#include "linkQueue.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

pQueue* create_linkQueue()
{
    pQueue* queue;
    queue = (pQueue*)malloc(sizeof(pQueue));    //结构体指针一定要malloc
    if(NULL == queue)
    {
        printf("Fail to allocate the memory!\n");
        return NULL;
    }
    queue->len = 0;
    queue->head = NULL;
    queue->tail = NULL;

    return queue;
}

int link_enqueue(pQueue *queue, int value)
{
    if(NULL == queue)
    {
        printf("Fail to enqueue, the queue is not exist!\n");
        return EXIT_FAILURE;
    }
    QueueNode *node;
    node = (QueueNode*)malloc(sizeof(QueueNode));
    if(NULL == node)
    {
        printf("Fail to enqueue, allocate memory for node failed!\n");
        return EXIT_FAILURE;
    }
    node->data = value;
    node->next = NULL;
    if(queue->head == NULL)     //什么都没有
    {
        queue->head = node;
    }
    else
    {
        queue->tail->next = node;
    }
    
    queue->len++;
    queue->tail = node;
    return EXIT_SUCCESS;
}

int link_dequeue(pQueue *queue, int *value)
{
    QueueNode *tmp = NULL;     
    
    if(NULL == queue)
    {
        printf("Fail to dequeue, the queue is not exist!\n");
        return EXIT_FAILURE;
    }
    if(empty_queue(queue))
    {
        printf("Fail to dequeue, the queue is empty already!\n");
        return EXIT_FAILURE;        
    }
    tmp = queue->head;
    *value = queue->head->data;
    queue->len--;
    queue->head = queue->head->next;
    if(NULL == queue->head)
    {
        queue->tail = NULL;
    }

    free(tmp);
    return EXIT_SUCCESS;
}

void destroy_linkQueue(pQueue* queue)
{
    int data;
    if(queue == NULL)
    {
        printf("The queue does not exist!\n");
        return;
    }
    if(empty_queue(queue))
    {
        printf("The queue is empty already!\n");
        return;
    }
    while(!empty_queue(queue))
    {
        link_dequeue(queue, &data);
        printf("De-queue value: %d\n", data);
    }

    free(queue); 
}

void dump_linkQueue(pQueue* queue)
{
    if(queue == NULL)
    {
        printf("Can't dump, the queue does not exist!\n");
        return;
    }
    if(empty_queue(queue))
    {
        printf("Can't dump, the queue is empty!\n");
        return;
    }
    QueueNode *p;
    p = queue->head;    //声明之后有赋值 所以不用malloc

    printf("The queue len: %d, head value: %d, tail value: %d\n", queue->len, queue->head->data, queue->tail->data);

    while(p)
    {
        printf(" --> %d\n", p->data);
        p = p->next;
    }
}

int main(int argv, char *argc[])
{
    int value;
    char ch;
    pQueue* queue = create_linkQueue();
    if(NULL == queue)
    {
        printf("Create failed!\n");
        return EXIT_FAILURE;
    }

    while(true)
    {
        printf("Pls. enter the value you want to en-queue:");
        scanf("%d", &value);
        if(EXIT_FAILURE == link_enqueue(queue, value))
            return EXIT_FAILURE;
        else
        {
            printf("En-queue %d success!\n", value);
        }

        printf("If you want to continue to en-queue? Y/N\n");
        scanf(" %s", &ch);
        if(ch != 'Y' && ch != 'y')
            break;
    }

    dump_linkQueue(queue);

    while(true)
    {
        printf("Do you want to de-queue? Y/N\n");
        scanf(" %s", &ch);
        if(ch != 'Y' && ch != 'y')
            break;
        if(EXIT_FAILURE == link_dequeue(queue, &value))
            return EXIT_FAILURE;
        else
        {
            printf("De-queue %d success!\n", value);
        }
    }

    dump_linkQueue(queue);

    destroy_linkQueue(queue);

    return EXIT_SUCCESS;
}