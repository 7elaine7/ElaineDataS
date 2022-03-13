/*
111. 二叉树的最小深度
给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：2
示例 2：
输入：root = [2,null,3,null,4,null,5,null,6]
输出：5
提示：
树中节点数的范围在 [0, 105] 内
-1000 <= Node.val <= 1000
*/
//function 1, DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;
int minDepth(struct TreeNode* root){
    if(!root)
        return 0;
    if(!root->left)
        return minDepth(root->right) + 1;
    if(!root->right)
        return minDepth(root->left) + 1;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    return (left < right ? left : right) + 1;
}

//funtion 2, DFS
typedef struct TreeNode Node;
int minDepth(struct TreeNode* root){
    if(!root)
        return 0;
    if(!root->left && !root->right)
        return 1;
    int left = INT_MAX;
    int right = INT_MAX;
    if(root->left)
    {
        left = minDepth(root->left);
    }
    if(root->right)
    {
        right = minDepth(root->right);
    }
    return (left < right ? left : right) + 1;
}



