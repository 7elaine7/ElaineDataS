/*
148. 排序链表
在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
示例 1:
输入: 4->2->1->3
输出: 1->2->3->4
示例 2:
输入: -1->5->3->4->0
输出: -1->0->3->4->5
*/
//function 1, 快排
//注意第一个点是比较点
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
void swap(Node* a, Node* b)
{
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}
Node* select_q(Node* start, Node* end)
{
    Node* p = start;
    Node* q = start;
    while(p != end)
    {
        if(p->val < start->val)
        {
            q = q->next;
            swap(p, q);
        }
        p = p->next;
    }
    swap(start, q);
    return q;
}
void quik_sort(Node* start, Node* end)
{
    //end点是不纳入比较的
    if(start == end || start->next == end)
        return;
    Node* q = select_q(start, end);
    quik_sort(start, q);
    quik_sort(q->next, end);
}

struct ListNode* sortList(struct ListNode* head){
    if(NULL == head || NULL == head->next)
        return head;
    quik_sort(head, NULL);
    return head;
}

//function 2, 归并
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
Node* merge(Node* l1, Node* l2)
{
    Node* head = NULL;
    Node** tmp = &head;
    while(l1 && l2)
    {
        if(l1->val <= l2->val)
        {
            *tmp = l1;
            l1 = l1->next;
        }
        else
        {
            *tmp = l2;
            l2 = l2->next;
        }
        tmp = &((*tmp)->next);
    }
    *tmp = l1 ? l1 : l2;
    return head;
}
Node* merge_sort(Node* head)
{
    if(!head || !head->next)
        return head;
    Node* slow = head;
    Node* fast = head;
    Node* pre = head;
    while(fast && fast->next)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    pre->next = NULL;   //一定要置为空

    return merge(merge_sort(head), merge_sort(slow));
}
struct ListNode* sortList(struct ListNode* head){
    if(NULL == head || NULL == head->next)
        return head;
    return merge_sort(head);
}