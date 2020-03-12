/*****************************************************************************
File name: ElaineDataS/DS/C/Graph/graph.h
Description: graph function
Author: Elaine Sun
Date: 20-03-12
*****************************************************************************/
#define MAX_GRAPH_SIZE 1<<7

typedef struct vertex_adj{
    struct vertex *v_node;
    struct vertex_adj *next;
}Vertex_Adj;

typedef struct vertex{
    int data;
    Vertex_Adj* vertex_adj; 
}Vertex;

typedef struct graph{
    Vertex* arr_ver[MAX_GRAPH_SIZE];
}Graph;

/*queue function*/

typedef struct linkQueue{
    int data;
    struct linkQueue *next; 
}QueueNode;

typedef struct pQueue
{
    int len;    //队列长度
    QueueNode *head;
    QueueNode *tail;
}Queue;

#define empty_queue(queue)  ((queue->len) == 0)
