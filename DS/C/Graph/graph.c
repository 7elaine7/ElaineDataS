/*****************************************************************************
File name: ElaineDataS/DS/C/Graph/graph.c
Description: graph function, Breadth-First-Search(BFS), Depth-First-Search(DFS)
Author: Elaine Sun
Date: 20-03-12
*****************************************************************************/
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool found = false;

void init_graph(Graph *graph)
{
    for(int n = 0; n < MAX_GRAPH_SIZE; n++)
    {
        graph->arr_ver[n] = NULL;
    }
}

Vertex* create_vertex(int data)
{
    Vertex *vertex;
    vertex = (Vertex*)malloc(sizeof(Vertex));
    if(vertex)
    {
        vertex->data = data;
        vertex->vertex_adj = NULL;
    }
    else
    {
        printf("Fail to melloc vertex memory!\n");
        return NULL;
    }

    return vertex;
}

Vertex_Adj* create_vertex_adj(Vertex* vertex)
{
    Vertex_Adj *vertex_adj;
    vertex_adj = (Vertex_Adj*)malloc(sizeof(Vertex_Adj));
    if(vertex_adj)
    {
        vertex_adj->v_node = vertex;
        vertex_adj->next = NULL;
    }
    else
    {
        printf("Fail to melloc vertex adj memory!\n");
        return NULL;
    }
    return vertex_adj;
}

void insert_adj(Vertex *vnode, Vertex *adj)
{
    Vertex_Adj** v_adj;
    v_adj = &(vnode->vertex_adj);
    while(*v_adj)
    {
        v_adj = &(*v_adj)->next;
    }
    *v_adj = create_vertex_adj(adj);
}

void dump(Graph *graph)
{
    int i;

    for(i = 0; i < MAX_GRAPH_SIZE; i++)
    {
        Vertex *v;
        Vertex_Adj *adj;
        v = graph->arr_ver[i];
        if(v == NULL)
            continue;
        
        printf("Vertex[%02d]: %8d ->", i, v->data);

        adj = v->vertex_adj;
        while(adj)
        {
            printf(" %8d,", adj->v_node->data);
            adj = adj->next;
        }
        printf("\n");
    }
}

/*
    0 ----- 1 ----- 2
    |       |       |
    |       |       |
    3 ----- 4 ----- 5
            |       |
            |       |
            6 ----- 7

*/
void fake_graph(Graph *graph)
{
    init_graph(graph);
    for(int i = 0; i < 8; i++)
    {
        graph->arr_ver[i] = create_vertex(i);
    }

    //connect 0 -> 1, 0 -> 3
    insert_adj(graph->arr_ver[0], graph->arr_ver[1]);
    insert_adj(graph->arr_ver[0], graph->arr_ver[3]);
    //connect 1 -> 2, 1 -> 4
    insert_adj(graph->arr_ver[1], graph->arr_ver[2]);
    insert_adj(graph->arr_ver[1], graph->arr_ver[4]);
    //connect 2 -> 5
    insert_adj(graph->arr_ver[2], graph->arr_ver[5]);
    //connect 3 -> 4
    insert_adj(graph->arr_ver[3], graph->arr_ver[4]);
    //connect 4 -> 5, 4 -> 6
    insert_adj(graph->arr_ver[4], graph->arr_ver[5]);
    insert_adj(graph->arr_ver[4], graph->arr_ver[6]);
    //connect 5 -> 7
    insert_adj(graph->arr_ver[5], graph->arr_ver[7]);
    //connect 6 -> 7
    insert_adj(graph->arr_ver[6], graph->arr_ver[7]);      
}

/*Queue function*/
Queue* create_linkQueue()
{
    Queue* queue;
    queue = (Queue*)malloc(sizeof(Queue));    //结构体指针一定要malloc
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

void link_enqueue(Queue *queue, int value)
{
    if(NULL == queue)
    {
        printf("Fail to enqueue, the queue is not exist!\n");
        return;
    }
    QueueNode *node;
    node = (QueueNode*)malloc(sizeof(QueueNode));
    if(NULL == node)
    {
        printf("Fail to enqueue, allocate memory for node failed!\n");
        return;
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
}

int link_dequeue(Queue *queue)
{
    QueueNode *tmp = NULL;     
    
    if(NULL == queue)
    {
        printf("Fail to dequeue, the queue is not exist!\n");
        return -1;
    }
    if(empty_queue(queue))
    {
        printf("Fail to dequeue, the queue is empty already!\n");
        return -1;        
    }
    tmp = queue->head;
    int value = queue->head->data;
    queue->len--;
    queue->head = queue->head->next;
    if(NULL == queue->head)
    {
        queue->tail = NULL;
    }

    free(tmp);
    return value;
}

void dump_map(int *pre, int s, int t)
{
    if((pre[t] != -1) && (t != s))
        dump_map(pre, s, pre[t]);
    printf(" %d ->", t);
}

void BFS(Graph *graph, int s, int t)
{
    Queue *queue = create_linkQueue();
    link_enqueue(queue, graph->arr_ver[s]->data);

    bool visited[8];
    int pre[8];
    for(int n = 0; n < 8; n++)
    {
        visited[n] = false;
        pre[n] = -1;
    }

    visited[s] = true;
    while(queue->len != 0)
    {
        int value = link_dequeue(queue);
        Vertex_Adj *adj = graph->arr_ver[value]->vertex_adj;
        //找出与value相链接的点
        while(adj)
        {
            int q = adj->v_node->data;
            if(!visited[q])
            {
                pre[q] = value;
                if(q == t)
                {
                    dump_map(pre, s, t);
                    printf("\n");
                    return;
                }
                visited[q] = true;
                link_enqueue(queue, q);
            }
            adj = adj->next;   
        }
    } 

}

void reDFS(Graph *graph, int w, int t, bool *visited, int *pre)
{
    if(found == true)
        return;
    visited[w] = true;
    if(w == t)
    {
        found = true;
        return;
    }
    Vertex_Adj *adj = graph->arr_ver[w]->vertex_adj;
    while(adj)
    {
        int q = adj->v_node->data;
        if(!visited[q])
        {
            pre[q] = w;
            reDFS(graph, q, t, visited, pre);
        }
        adj = adj->next;
    }

}

void DFS(Graph *graph, int s, int t)
{
    bool visited[8];
    int pre[8];
    for(int n = 0; n < 8; n++)
    {
        visited[n] = false;
        pre[n] = -1;
    }
    reDFS(graph, s, t, visited, pre);
    dump_map(pre, s, t);
    printf("\n");
}

int main(int argc, char *argv[])
{
    Graph graph;
    fake_graph(&graph);
    dump(&graph);

    BFS(&graph, 0, 7);
    DFS(&graph, 0, 7);
    return EXIT_SUCCESS;
}