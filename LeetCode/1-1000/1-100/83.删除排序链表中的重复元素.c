/*
83. 删除排序链表中的重复元素
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
示例 1：
输入：head = [1,1,2]
输出：[1,2]
示例 2：
输入：head = [1,1,2,3,3]
输出：[1,2,3]
提示：
链表中节点数目在范围 [0, 300] 内
-100 <= Node.val <= 100
题目数据保证链表已经按升序 排列
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* deleteDuplicates(struct ListNode* head){
    if(!head || !head->next)
        return head;
    Node* slow = head;
    Node* fast = head->next;
    while(fast)
    {
        if(slow->val == fast->val)
        {
            slow->next = fast->next;
        }
        else
        {
            slow = slow->next;
        }
        fast = fast->next;
    }
    return head;
}
