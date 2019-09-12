/*****************************************************************************
File name: ElaineDataS/DS/C/Linked_list/singel_list.c
Description: singel list common function
Author: Elaine Sun
Version: 
Date: 
History: 
*****************************************************************************/

#include "node.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//dump all the value
void dump(Node **rootp)
{
    Node *p = *rootp;    //头指针

    int index = 0;

    while(p)
    {
        printf("[%02d]: %08d\n", index++, p->data);
        p = p->link;
    }
}
//search value，返回指向search node的指针的指针
Node** search(Node **rootp, int value)
{
    Node *p = *rootp;
    while(p != NULL)
    {
        if(p->data == value)
        {
            p = NULL;
            return rootp;
        }
        rootp = &(p->link);
        p = *rootp;
    }
    p = NULL;
    return NULL;
}
//insert Node new in the *p
void insert(Node **p, Node *new)
{
    if(NULL == p)
    {
        printf("error");
        return;
    }
    if(*p)  //链表不空，中间插，头插都可以
    {
        new->link = *p;
    }
    *p = new;   // *p为空，尾插  p依然指向链表头
}
//delete node
Node* delete(Node **p)
{
    if(NULL == p || NULL == *p)
    {
        printf("the delte node is NULL");
        return NULL;
    }
    Node *tmp = *p;
    *p = tmp->link;
    tmp->link = NULL;   //delete p的指针的指针的节点

    return tmp;     //delete节点的指针
} 
//单链表反转
void reverse(Node **rootp)
{
    Node *pre;
    Node *next;
    Node *current = *rootp;
    for(pre = NULL; current != NULL; current = next)
    {
        next = current->link;
        current->link = pre;
        pre = current;
    }
    *rootp = pre;   //新表头地址
    current = next = pre = NULL;
}
//链表中环检测, 快慢指针，快指针一定会在慢指针没走完一圈的时候与之相遇！amazing～～
//一个指针从起点开始，另一个指针从相遇点开始，两个指针再次相遇的点就是环的入口点
bool Iscircle(Node **rootp, Node **meet)
{
    Node *slow = *rootp;
    Node *fast = slow;
    while(fast)
    {
        if((fast == slow) && (fast != *rootp))
        {
            printf("Circle exist!\n");
            *meet = slow;

            return true;
        }
        slow = slow->link;
        fast = fast->link->link; 
    }
    printf("Circle is not exist in the List~~\n");
    return false;
}
Node* LoopStart(Node **rootp)
{
    Node **p;
    
    Node *LoopStart;
    Node *slow = *rootp;

    if(Iscircle(rootp, p))  //为什么p未被初始化可以直接传入取*p
    {
        LoopStart = *p;
        while(slow != LoopStart)
        {
            slow = slow->link;
            LoopStart = LoopStart->link;
        }
        return LoopStart;
    }

    return NULL;
}
//两个有序链表合并
Node** merge(Node *p1, Node *p2)
{
    Node *p, *tmp;
    Node **rtp = &tmp;

    if(p1->data >= p2->data)
    {
        p = p2;
        *rtp = p;
        p2 = p2->link;
    }
    else
    {
        p = p1;
        *rtp = p;
        p1 = p1->link;
    }
    
    while(p1 && p2)
    {
        if(p1->data >= p2->data)
        {
            p->link = p2;
            p = p2;
            p2 = p2->link;
        }
        else
        {
            p->link = p1;
            p = p1;
            p1 = p1->link;
        }
    }
    if(NULL == p1)
    {
        p->link = p2;
    }
    else
    {
        p->link = p1;
    }
    return rtp;   //返回新链表表头
}

//删除链表倒数第n个节点
void removeNfromEnd(Node **rootp, int n)
{
    Node *slow = *rootp;
    Node *fast = slow;
    while(n--)
    {
        if(NULL == fast->link)
            break;
        fast = fast->link;
    }
    if(n > 0)
    {
        printf("remove fail : the len for listed_link less than n, n = %d\n", n);
        return;
    }
    if(NULL == fast->link)
    {
        printf("remove the head node!\n");
        *rootp = slow->link;
    }
    else
    {
        while(NULL != fast->link) //slow指向倒数第n+1个节点
        {
            slow = slow->link;
            fast = fast->link;
        }
        slow->link = slow->link->link;
    }
    slow = NULL;
    fast = NULL;

}

//求链表中间节点
Node* Middle(Node **rootp)
{
    Node *slow = *rootp;
    Node *fast = slow;
    while(fast && fast->link)
    {
        slow = slow->link;
        fast = fast->link->link;
    }
    fast = NULL;
    return slow;
}

int main(int argv, char *argc[])

{
    Node **rootp = (Node**)malloc(sizeof(Node*));
    *rootp = NULL;
    Node List[10];
    Node **p;
    Node **meet = (Node**)malloc(sizeof(Node*));
    Node *loopStart;
    int index;

    for(index = 0; index < 10; index++)
    {
        List[index].data = index;
        List[index].link = NULL;
    }

    //insert the value in the link
    printf("------------ insert 2->0->1->8->6->3->5 ------------\n");
    insert(rootp, &List[5]);
    insert(rootp, &List[3]);
    insert(rootp, &List[6]);
    insert(rootp, &List[8]);
    insert(rootp, &List[1]);
    insert(rootp, &List[0]);
    insert(rootp, &List[2]);

    dump(rootp);
    printf("-------------------- insert end --------------------\n");

    //search value and insert the value
    printf("----------------- insert 7 before 6 ----------------\n");
    p = search(rootp, 6);
    insert(p, &List[7]);
    dump(rootp);

    //delete value
    printf("--------------------- delete 3 ---------------------\n");
    p = search(rootp, 3);
    Node *tmp = delete(p);
    if(search(&tmp, 3) && !search(rootp, 3))
    {
        printf("delete 3 success\n");
    }
    dump(rootp);

    //reverse the list
    printf("------------------ reverse the list ----------------\n");
    reverse(rootp);
    dump(rootp);

    //get the middle node
    printf("-------------- the middle node is: %02d --------------\n", Middle(rootp)->data);
    
    //remove the node from the end
    printf("--------- remove the 2th node from the end ---------\n");
    removeNfromEnd(rootp, 2);
    dump(rootp);

    //make circle
    List[2].link = &List[7];

    if(Iscircle(rootp, meet))
    {
        printf("the meet node is: %d\n", (*meet)->data);
        loopStart = LoopStart(rootp);

        if(NULL != loopStart)
        {
            printf("loopStart: %d\n", loopStart->data);
        }
    }

//create new list1, 如果用函数建立，只是局部，函数调用完会销毁
    printf("---------------- create list 1 ---------------------\n");
    Node **headp1 = (Node**)malloc(sizeof(Node*));
    *headp1 = NULL;
    Node List1[10];
    for(index = 0; index < 10; index++)
    {
        List1[index].data = index;
        List1[index].link = NULL;
    }

    insert(headp1, &List1[9]);
    insert(headp1, &List1[7]);
    insert(headp1, &List1[5]);
    insert(headp1, &List1[1]);
    insert(headp1, &List1[0]);

    dump(headp1);

//create new list2
    printf("---------------- create list 2 ---------------------\n");
    Node **headp2 = (Node**)malloc(sizeof(Node*));
    *headp2 = NULL;
    Node List2[10];
    for(index = 0; index < 10; index++)
    {
        List2[index].data = index;
        List2[index].link = NULL;
    }

    insert(headp2, &List2[8]);
    insert(headp2, &List2[7]);
    insert(headp2, &List2[6]);
    insert(headp2, &List2[5]);
    insert(headp2, &List2[3]);
    insert(headp2, &List2[2]);

    dump(headp2);

    printf("----------------- merge list 3 ---------------------\n");

    Node **new = merge(*headp1, *headp2);

    dump(new);

    return 0;
}