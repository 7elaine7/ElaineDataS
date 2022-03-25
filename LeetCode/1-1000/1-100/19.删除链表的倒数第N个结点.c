/*
19. 删除链表的倒数第 N 个结点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]
示例 2：
输入：head = [1], n = 1
输出：[]
示例 3：
输入：head = [1,2], n = 1
输出：[1]
提示：
链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
进阶：你能尝试使用一趟扫描实现吗？
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    Node** p = &head;
    Node** slow = &head;
    Node** fast = &head;
    for(int i = 1; i < n; ++i)
    {
        if(!(*fast))
            return head;
        fast = &(*fast)->next;
    }
    while(*fast && (*fast)->next)
    {
        fast = &(*fast)->next;
        slow = &(*slow)->next;
    }
    Node* tmp = *slow;
    *slow = tmp->next;
    tmp->next = NULL;
    return *p;
}