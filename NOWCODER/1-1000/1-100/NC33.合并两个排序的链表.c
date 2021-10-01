/*
NC33 合并两个排序的链表
描述
输入两个递增的链表，单个链表的长度为n，合并这两个链表并使新链表中的节点仍然是递增排序的。
数据范围： 0 \le n \le 10000≤n≤1000，-1000 \le 节点值 \le 1000−1000≤节点值≤1000
要求：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)
示例1
输入：{1,3,5},{2,4,6}
返回值：{1,2,3,4,5,6}

示例2
输入：{},{}
返回值：{}

示例3
输入：{-1,2,4},{1,3,4}
返回值：{-1,1,2,3,4,4}
*/
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param pHead1 ListNode类 
 * @param pHead2 ListNode类 
 * @return ListNode类
 */
typedef struct ListNode Node;
struct ListNode* Merge(struct ListNode* pHead1, struct ListNode* pHead2 ) {
    // write code here
    Node* head = NULL;
    Node** tmp = &head;

    while(pHead1 && pHead2)
    {
        if(pHead1->val < pHead2->val)
        {
            *tmp = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            *tmp = pHead2;
            pHead2 = pHead2->next;
        }
        tmp = &(*tmp)->next;
    }
    *tmp = pHead1 ? pHead1 : pHead2;
    return head;
}