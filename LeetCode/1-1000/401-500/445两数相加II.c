/*
445. 两数相加 II
给你两个 非空 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
你可以假设除了数字 0 之外，这两个数字都不会以零开头。
进阶：
如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
示例：
输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 8 -> 0 -> 7
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
int get_len(struct ListNode* l)
{
    int len = 0;
    struct ListNode* p = l;
    while(p)
    {
        p = p->next;
        len++;
    }
    return len;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int size1 = get_len(l1);
    int size2 = get_len(l2);
    int size = size1 > size2 ? size1 : size2;
    int* s1 = (int*)malloc(sizeof(int) * size);
    int* s2 = (int*)malloc(sizeof(int) * size);
    int count1 = 0;
    while(l1)
    {
        s1[count1++] = l1->val;
        l1 = l1->next;
    }
    int count2 = 0;
    while(l2)
    {
        s2[count2++] = l2->val;
        l2 = l2->next;
    }
    struct ListNode* head = NULL;
    int flag = 0;
    while(count1 > 0 || count2 > 0)
    {
        count1--;
        count2--;
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        int sum;
        if(count1 < 0)
        {
            sum = s2[count2] + flag;
        }
        else if(count2 < 0)
        {
            sum = s1[count1] + flag;
        }
        else
        {
            sum = s1[count1] + s2[count2] + flag;
        }
        tmp->val = sum % 10;
        flag = sum / 10;
        tmp->next = head;
        head = tmp;
    }
    if(flag != 0)
    {
        struct ListNode* tmp = (struct ListNode*)malloc(sizeof(struct ListNode));
        tmp->val = flag;
        tmp->next = head;
        head = tmp;
    }
    return head;
}