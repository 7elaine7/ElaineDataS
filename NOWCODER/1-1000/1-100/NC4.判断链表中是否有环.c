/*
NC4 判断链表中是否有环
描述
判断给定的链表中是否有环。如果有环则返回true，否则返回false。
数据范围：链表长度 0 \le n \le 100000≤n≤10000，链表中任意节点的值满足 |val| <= 100000∣val∣<=100000
要求：空间复杂度 O(1)O(1)，时间复杂度 O(n)O(n)
输入分为2部分，第一部分为链表，第二部分代表是否有环，然后回组成head头结点传入到函数里面。-1代表无环，其他的数字代表有环，这些参数解释仅仅是为了方便读者自测调试。实际在编码时读入的是链表的头节点。
示例1
{3,2,0,-4},1
返回值：true
说明：第一部分{3,2,0,-4}代表一个链表，第二部分的1表示，-4到位置1，即-4->2存在一个链接，组成传入的head为一个带环的链表 ,返回true     
示例2
输入：{1},-1
返回值：false
说明：第一部分{1}代表一个链表，-1代表无环，组成传入head为一个无环的单链表，返回false     
示例3
输入：{-1,-7,7,-4,19,6,-9,-5,-2,-5},6
返回值：true
*/
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param head ListNode类 
 * @return bool布尔型
 */
typedef struct ListNode Node;
bool hasCycle(struct ListNode* head ) {
    // write code here
    Node* slow = head;
    Node* fast = head;
    while((fast != NULL) && (fast->next != NULL))
    {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast)
            return true;
    }
    return false;
}