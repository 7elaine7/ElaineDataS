/*****************************************************************************
File name: ElaineDataS/DS/C/Queue/LinkQueue/linkQueue.h
Description: Linked Queue common function
Author: Elaine Sun
Date: 19-09-18
*****************************************************************************/

typedef struct linkQueue{
    int data;
    struct linkQueue *next; 
}QueueNode;

typedef struct pQueue
{
    int len;    //队列长度
    QueueNode *head;
    QueueNode *tail;
}pQueue;

#define empty_queue(queue)  ((queue->len) == 0)
