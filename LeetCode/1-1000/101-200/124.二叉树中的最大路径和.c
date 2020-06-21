/*
124. 二叉树中的最大路径和
给定一个非空二叉树，返回其最大路径和。
本题中，路径被定义为一条从树中任意节点出发，达到任意节点的序列。该路径至少包含一个节点，且不一定经过根节点。
示例 1:
输入: [1,2,3]

       1
      / \
     2   3
输出: 6
示例 2:
输入: [-10,9,20,null,null,15,7]

   -10
   / \
  9  20
    /  \
   15   7
输出: 42
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(x, y) (x > y ? x : y)
typedef struct TreeNode Node;
int dfs(Node* root, int* max)
{
    if(!root)
        return 0;
    int left = dfs(root->left, max);
    int right = dfs(root->right, max);

    //到此root点为止的最大值
    *max = MAX(*max, root->val + MAX(0, left) + MAX(0, right));
    //此点能够提供给上面的最大值
    return root->val + MAX(0, MAX(left, right));
}
int maxPathSum(struct TreeNode* root){
    int max = INT_MIN;
    int res = dfs(root, &max);

    return max;
}