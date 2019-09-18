/*****************************************************************************
File name: ElaineDataS/DS/C/Queue/ArrayQueue/arrayQueue.h
Description: Linked Stack common function
Author: Elaine Sun
Date: 19-09-16
*****************************************************************************/

typedef struct arrayQueue
{
    int size;   //队列大小
    int num;    //队列存储的数目
    int head;   //队列头
    int tail;   //队列尾
    int *array; //数组内存地址
}ArrayQueue;

#define arrayFull(queue) (queue->num == queue->size)
#define arrayEmpty(queue) (queue->num == 0)
