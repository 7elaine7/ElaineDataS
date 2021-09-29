/*
NC78 反转链表
描述
输入一个长度为n链表，反转链表后，输出新链表的表头。

数据范围 
要求：空间复杂度  ，时间复杂度  。
示例1
输入：  {1,2,3}
返回值：{3,2,1}
示例2
输入：  {}
返回值：{}
说明：空链表则输出空 
*/
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param pHead ListNode类 
 * @return ListNode类
 */
typedef struct ListNode Node;
struct ListNode* ReverseList(struct ListNode* pHead ) {
    // write code here
    //printf("the first num is : %d\n", pHead->val);
    Node* Pre = NULL;
    Node* Current = pHead;
    Node* Next = Current;
    while(Next)
    {
        Next = Current->next;
        Current->next = Pre;
        Pre = Current;
        Current = Next;
    }
    
    return Pre;
}