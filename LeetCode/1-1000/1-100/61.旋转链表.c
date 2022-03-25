/*
61. 旋转链表
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。
示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]
示例 2：
输入：head = [0,1,2], k = 4
输出：[2,0,1]
提示：
链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* rotateRight(struct ListNode* head, int k){
    if(!head || k == 0 || !head->next)
        return head;
    Node** slow = &head;
    Node** fast = &head;
    int count = -1;
    int i = 1;
    for(; i < k; ++i)
    {
        if((*fast)->next == NULL)
        {
            count = k % i;
            break;
        }
        fast = &(*fast)->next;
    }
    if(count == 0)
        return head;
    if(count > 0)
    {
        fast = slow;
        for(int i = 1; i < count; ++i)
        {
            fast = &(*fast)->next;
        }
    }
    while((*fast) && (*fast)->next)
    {
        slow = &(*slow)->next;
        fast = &(*fast)->next;
    }
    if(*slow == head)
        return head;
    (*fast)->next = head;
    head = *slow;
    *slow = NULL;
    return head;
}