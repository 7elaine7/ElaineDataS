/*
剑指 Offer 06. 从尾到头打印链表
输入一个链表的头节点，从尾到头反过来返回每个节点的值（用数组返回）。
示例 1：
输入：head = [1,3,2]
输出：[2,3,1]
限制：
0 <= 链表长度 <= 10000
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct ListNode Node;
int* reversePrint(struct ListNode* head, int* returnSize){
    *returnSize = 0;
    int* res;
    if(!head)
        return res;

    Node** pre = &head;
    Node* current = head;
    Node* n = current->next;
    while(n)
    {
        current->next = n->next;
        n->next = *pre;
        *pre = n;
        (*returnSize)++;
        n = current->next;
    }
    *returnSize += 1;
    res = (int*)malloc(sizeof(int) * (*returnSize));
    int i = 0;
    while(*pre)
    {
        res[i++] = (*pre)->val;
        pre = &(*pre)->next;
    }
    return res;
}