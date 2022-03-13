/*
104. 二叉树的最大深度
给定一个二叉树，找出其最大深度。
二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
说明: 叶子节点是指没有子节点的节点。
示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
返回它的最大深度 3 。
*/

//DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;
int max;
void find(Node* tree, int deep)
{
    if(!tree)
    {
        max = deep > max ? deep : max;
    }
    else
    {
        find(tree->left, deep + 1);
        find(tree->right, deep + 1);
    }
}
int maxDepth(struct TreeNode* root){
    max = 0;
    find(root, 0);
    return max;
}

//优化 DFS
typedef struct TreeNode Node;
int maxDepth(struct TreeNode* root){
    if(!root)
        return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return (left > right ? left : right) + 1;
    //return (maxDepth(root->left) > maxDepth(root->right) ? maxDepth(root->left)  : maxDepth(root->right)) + 1;
    //return fmax(maxDepth(root->left), maxDepth(root->right)) + 1;
}
