/*
2. 两数相加
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

//function 1
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    Node* head = NULL;
    Node** current = &head;
    int b = 0;  //进位
    while(l1 && l2)
    {
        Node* new = (Node*)malloc(sizeof(Node));
        int sum = b + l1->val + l2->val;
        new->val = sum % 10;
        new->next = NULL;
        *current = new;
        current = &((*current)->next);
        b = sum / 10;
        l1 = l1->next;
        l2 = l2->next;
    }
    Node* p;
    if(l1)
        p = l1;
    else if(l2)
        p = l2;
    else
    {
        if(b == 0)
            return head;
        else
        {
            Node* new = (Node*)malloc(sizeof(Node));
            new->val = b;
            new->next = NULL;
            *current = new;
            return head;
        }
    }
    *current = p;
    //l1, l2剩余的部分沿用剩下的节点，不新建
    while(*current)
    {
        int sum = (*current)->val + b;
        (*current)->val = sum % 10;
        b = sum / 10;
        if(b == 0)
            break;
        current = &((*current)->next);
    }
    if(b > 0)
    {
        Node* new = (Node*)malloc(sizeof(Node));
        new->val = b;
        new->next = NULL;
        *current = new;
    }
    return head;
}

//function 2，优化
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


typedef struct ListNode Node;
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    Node* head = NULL;
    Node** current = &head;
    int b = 0;  //进位
    while(l1 || l2)
    {
        Node* new = (Node*)malloc(sizeof(Node));
        int x = l1 ? l1->val : 0;
        int y = l2 ? l2->val : 0;
        int sum = b + x + y;
        new->val = sum % 10;
        new->next = NULL;
        *current = new;
        current = &((*current)->next);
        b = sum / 10;
        if(l1)
            l1 = l1->next;
        if(l2)
            l2 = l2->next;
    }

    if(b > 0)
    {
        Node* new = (Node*)malloc(sizeof(Node));
        new->val = b;
        new->next = NULL;
        *current = new;
    }
    return head;
}


