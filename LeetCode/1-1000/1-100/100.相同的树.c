/*
100. 相同的树
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。
如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
示例 1：
输入：p = [1,2,3], q = [1,2,3]
输出：true
示例 2：
输入：p = [1,2], q = [1,null,2]
输出：false
示例 3：
输入：p = [1,2,1], q = [1,1,2]
输出：false
 
提示：
两棵树上的节点数目都在范围 [0, 100] 内
-104 <= Node.val <= 104
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//function 1, BFS
#define NUM 250
typedef struct TreeNode Node;
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p && !q)
        return true;
    if(!p || !q)
        return false;
    Node** queue1 = (Node**)malloc(sizeof(Node*) * NUM);
    Node** queue2 = (Node**)malloc(sizeof(Node*) * NUM);
    for(int i = 0; i < NUM; ++i)
    {
        queue1[i] = NULL;
        queue2[i] = NULL;
    }
    int start1 = 0;
    int start2 = 0;
    int end1 = 0;
    int end2 = 0;
    queue1[0] = p;
    queue2[0] = q;
    while(start1 <= end1 && start2 <= end2)
    {
        Node* tmp1 = queue1[start1];
        Node* tmp2 = queue2[start2];

        if(!tmp1 && !tmp2)
        {
            start1++;
            start2++;
        }
        else if((!tmp1 && tmp2) || (!tmp2 && tmp1) || (tmp1->val != tmp2->val))
            return false;
        else
        {
            queue1[++end1] = queue1[start1]->left;
            queue1[++end1] = queue1[start1++]->right;
            queue2[++end2] = queue2[start2]->left;
            queue2[++end2] = queue2[start2++]->right;            
        }       
    }
    return true;    
}

//DFS
typedef struct TreeNode Node;
bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if(!p && !q)
        return true;
    if(!p || !q)
        return false;
    if(p->val != q->val)
        return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}