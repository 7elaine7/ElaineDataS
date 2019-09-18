/*****************************************************************************
File name: ElaineDataS/DS/C/Queue/ArrayQueue/arrayQueue.c
Description: Linked Stack common function
Author: Elaine Sun
Date: 19-09-16
*****************************************************************************/

#include "arrayQueue.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

ArrayQueue* create_arrayQueue(size)
{
    ArrayQueue *queue = (ArrayQueue*)malloc(sizeof(ArrayQueue));
    if(NULL == queue)
    {
        printf("Fail to allocate memory!\n");
    }
    queue->array = (int*)malloc(sizeof(int) * size);
    if(queue->array == NULL)
    {
        printf("Fail to allocate memory for array!\n");
        free(queue);
        return NULL;
    }
    queue->size = size;
    queue->num = 0;
    queue->head = 0;
    queue->tail = 0;

    return queue;
}

void destroy_arrayQueue(ArrayQueue* queue)
{
    if(queue == NULL)
    {
        printf("Queue alreday not exist!\n");
        return;
    }

    if(queue->array != NULL)
        free(queue->array);

    free(queue);
}

int array_enqueue(ArrayQueue* queue, int value)
{
    if(NULL == queue)
    {
        printf("The array destroy!\n");
        return EXIT_FAILURE;
    }
    if(arrayFull(queue))
    {
        printf("The array is full!\n");
        return EXIT_FAILURE;
    }

    queue->array[queue->tail] = value;
    queue->num++;
    queue->tail = (queue->tail + 1) % queue->size;

    return EXIT_SUCCESS;
}

int array_dequeue(ArrayQueue* queue, int *data)
{
    if(NULL == queue)
    {
        printf("The array destroy!\n");
        return EXIT_FAILURE;
    }
    if(arrayEmpty(queue))
    {
        printf("The array is empty!\n");
        return EXIT_FAILURE;
    }

    *data = queue->array[queue->head];
    queue->head = (queue->head + 1) % queue->size;
    queue->num--;
    return EXIT_SUCCESS;
}

void dump_arrayQueue(ArrayQueue* queue)
{
    if(NULL == queue)
    {
        printf("The array destroy!\n");
        return;
    }
    if(arrayEmpty(queue))
    {
        printf("The array is already empty!\n");
        return;
    }
    
    printf("queue size = %d, num = %d, head = %d, tail = %d\n", queue->size, queue->num, queue->head, queue->tail);
    for(int i=0; i < queue->num; i++)
    {
        int pos = (queue->head + i) % queue->size;
        printf("[%d] --> %d\n", pos, queue->array[pos]);
    }
}

int main(int argv, char *argc[])
{
    int size;   //队列长度
    int value;
    char ch;
    int data;
    ArrayQueue *queue;
    printf("Pls. enter the queue size you want to create:");
    scanf("%d", &size);

    queue = create_arrayQueue(size);
    while(true)
    {
        printf("Pls. enter the enqueue value:");
        scanf("%d", &value);
        if(EXIT_FAILURE == array_enqueue(queue, value))
        {
            printf("Fail to enqueue %d!\n", value);
            break;
        }
        printf("If you want to continue to enqueue? Y/N\n");
        scanf(" %s", &ch);
        if(ch != 'Y' && ch != 'y')
            break;
    }

    dump_arrayQueue(queue);

    while(true)
    {
        printf("Do you want to continue to dequeue? Y/N\n");
        scanf(" %s", &ch);
        if(ch != 'Y' && ch != 'y')
            break;    
        
        int tmp = array_dequeue(queue, &data);
        if(EXIT_FAILURE == tmp)
        {
            printf("Fail to dequeue!\n");
            break;
        }
        printf("Dequeue %d success!\n", data);
    }

    dump_arrayQueue(queue);

    destroy_arrayQueue(queue);

    return EXIT_SUCCESS;

}