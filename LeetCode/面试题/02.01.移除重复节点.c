/*
面试题 02.01. 移除重复节点
编写代码，移除未排序链表中的重复节点。保留最开始出现的节点。
示例1:

 输入：[1, 2, 3, 3, 2, 1]
 输出：[1, 2, 3]
示例2:

 输入：[1, 1, 1, 1, 2]
 输出：[1, 2]
提示：
链表长度在[0, 20000]范围内。
链表元素在[0, 20000]范围内。
进阶：
如果不得使用临时缓冲区，该怎么解决？
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//function 1， 哈希
#define SIZE 20001
typedef struct ListNode Node;
struct ListNode* removeDuplicateNodes(struct ListNode* head){
    int* hash = (int*)malloc(sizeof(int) * SIZE);
    memset(hash, 0, sizeof(int) * SIZE);
    Node **p = &head;
    while(*p)
    {
        int tmp = (*p)->val;
        if(hash[tmp] == 0)
        {
            hash[tmp] = 1;
            p = &((*p)->next);
        }            
        else
        {
            Node* d = *p;
            *p = (*p)->next;
            free(d);
            d = NULL;
        }
    }
    return head;
}

//function 2， 双循环，原地
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* removeDuplicateNodes(struct ListNode* head){
    Node *p = head;
    while(p)
    {
        Node** n = &(p->next);
        while(*n)
        {
            if((*n)->val == p->val)
            {
                Node* tmp = *n;
                *n = (*n)->next;
            }
            else
            {
                n = &((*n)->next);
            }
        }
        p = p->next;
    }
    return head;
}