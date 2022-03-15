/*
404. 左叶子之和
给定二叉树的根节点 root ，返回所有左叶子之和。
示例 1：
输入: root = [3,9,20,null,null,15,7] 
输出: 24 
解释: 在这个二叉树中，有两个左叶子，分别是 9 和 15，所以返回 24
示例 2:
输入: root = [1]
输出: 0
提示:
节点数在 [1, 1000] 范围内
-1000 <= Node.val <= 1000
*/

//function 1, DFs
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
typedef struct TreeNode Node;
int dfs(Node* root)
{
    int count = 0;
    if(root->left)
    {
        if(!root->left->left && !root->left->right)
            count += root->left->val;
        else
            count += dfs(root->left);
    }
    if(root->right)
    {
        count += dfs(root->right);
    }
    return count;
}
int sumOfLeftLeaves(struct TreeNode* root){
    return dfs(root);
}