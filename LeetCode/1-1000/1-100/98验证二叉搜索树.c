/*
98. 验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:
输入:
    2
   / \
  1   3
输出: true
示例 2:
输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
*/

//function 1，递归
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;
bool search(Node* root, long left, long right)
{
    if(NULL == root)
        return true;
    if(root->left)
    {
        if(root->left->val >= root->val || root->left->val <= left)
            return false;
    }
    if(root->right)
    {
        if(root->right->val <= root->val || root->right->val >= right)
            return false;
    }
    return search(root->left, left, root->val) && search(root->right, root->val, right);
}
bool isValidBST(struct TreeNode* root){
    if(NULL == root)
        return true;
    return search(root, LONG_MIN, LONG_MAX);
}

//function 2， 中序遍历， 栈模拟
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;
#define SIZE 1000
bool isValidBST(struct TreeNode* root){
    if(NULL == root)
        return true;
    Node* stack[SIZE];
    int tail = 0;
    long pre = LONG_MIN;
    
    while(tail > 0 || root)
    {
        while(root)
        {
            stack[tail++] = root;
            root = root->left;
        }
        root = stack[--tail];
        if(root->val <= pre)
            return false;
        pre = root->val;
        root = root->right;
    }
    return true;
}