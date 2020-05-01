/*
21. 合并两个有序链表
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
示例：
输入：1->2->4, 1->3->4
输出：1->1->2->3->4->4
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//function 1，用了个头节点
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
//function 2 ，二级指针，快一点
typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    Node* head = NULL;
    Node** p = &head;
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            *p = l1;
            l1 = l1->next;
        }
        else
        {
            *p = l2;
            l2 = l2->next;
        }
        p = &((*p)->next);  //(), -> priority: 1; *, & priority: 2
    }
    if(l1)
        *p = l1;
    else
        *p = l2;
    return head;
}