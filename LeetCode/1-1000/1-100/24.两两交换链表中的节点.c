/*
24. 两两交换链表中的节点
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。
示例 1：
输入：head = [1,2,3,4]
输出：[2,1,4,3]
示例 2：
输入：head = []
输出：[]
示例 3：
输入：head = [1]
输出：[1]
提示：
链表中节点的数目在范围 [0, 100] 内
0 <= Node.val <= 100
*/

//function 1, 递归
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* newHead = head->next;
    head->next = swapPairs(newHead->next);
    newHead->next = head;
    return newHead;
}

//function 2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* swapPairs(struct ListNode* head){
    if(!head || !head->next)
        return head;
    Node* fast = head->next;
    Node* slow = head;
    Node** p = &head;
    while(fast && slow)
    {
        slow->next = fast->next;
        fast->next = slow;
        *p = fast;
        if(!slow->next || !slow->next->next)
            return head;
        p = &(slow->next);
        slow = slow->next;
        fast = slow->next;
    }
    return head;
}