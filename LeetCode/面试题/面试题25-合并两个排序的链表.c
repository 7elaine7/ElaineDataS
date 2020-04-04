/*
面试题25. 合并两个排序的链表
输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
示例1：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
限制：
0 <= 链表长度 <= 1000
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->next = NULL;
    struct ListNode* p = head;
    while(l1 && l2)
    {
        if(l1->val > l2->val)
        {
            p->next = l2;
            l2 = l2->next;
        }
        else
        {
            p->next = l1;
            l1 = l1->next;
        }
        p = p->next;
    }
    if(!l1)
    {
        p->next = l2;
    }
    else if(!l2)
    {
        p->next = l1;
    }
    p = NULL;
    free(p);

    head = head->next;
    return head;
}