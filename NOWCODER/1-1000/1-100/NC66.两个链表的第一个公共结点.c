/*
NC66 两个链表的第一个公共结点
描述
输入两个无环的单向链表，找出它们的第一个公共结点，如果没有公共节点则返回空。（注意因为传入数据是链表，所以错误测试数据的提示是用其他方式显示的，保证传入数据是正确的）

数据范围： n <= 1000
要求：空间复杂度 O(1)，时间复杂度 O(n)
示例1
输入：{1,2,3},{4,5},{6,7}
返回值：{6,7}
说明：
第一个参数{1,2,3}代表是第一个链表非公共部分，第二个参数{4,5}代表是第二个链表非公共部分，最后的{6,7}表示的是2个链表的公共部分
这3个参数最后在后台会组装成为2个两个无环的单链表，且是有公共节点的      
示例2
输入：{1},{2,3},{}
返回值：{}
说明：
2个链表没有公共节点 ,返回null，后台打印{}
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
//function 1
typedef struct ListNode Node;
struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2 ) {
    // write code here
    Node* res = NULL;
    Node* p1 = pHead1;
    Node* p2 = pHead2;
    int len1 = 0;    //链表1长度
    int len2 = 0;    //链表2长度

    while(p1)
    {
        len1++;
        p1 = p1->next;
    }
    while(p2)
    {
        len2++;
        p2 = p2->next;
    }

    p1 = pHead1;
    p2 = pHead2;
    int tmp = len1 > len2 ? len1 - len2 : len2 - len1;
    while(tmp--)
    {
        len1 > len2 ? (p1 = p1->next) : (p2 = p2->next);
    }
    while(p1 != p2 && p1 && p2)
    {
        p1 = p1->next;
        p2 = p2->next;
    }

    return res = p1;
}

//function 2
typedef struct ListNode Node;
struct ListNode* FindFirstCommonNode(struct ListNode* pHead1, struct ListNode* pHead2 ) {
    // write code here
    Node* p1 = pHead1;
    Node* p2 = pHead2;
    //p1走完走list2，p2走完走list1，两者走的长度相同，如果有公共结点肯定会重合
    while(p1 != p2)
    {
        p1 = !p1 ? pHead2 : p1->next;
        p2 = !p2 ? pHead1 : p2->next;
    }
    return p1;
}
