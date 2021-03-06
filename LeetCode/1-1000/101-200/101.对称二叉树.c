/*
101. 对称二叉树
给定一个二叉树，检查它是否是镜像对称的。
例如，二叉树 [1,2,2,3,4,4,3] 是对称的。

    1
   / \
  2   2
 / \ / \
3  4 4  3
 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:

    1
   / \
  2   2
   \   \
   3    3
 

进阶：
你可以运用递归和迭代两种方法解决这个问题吗？
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//function 1, 递归
typedef struct TreeNode Node;
bool check(Node* left, Node* right)
{
    if(left == NULL && right == NULL)
        return true;
    if(left == NULL || right == NULL || left->val != right->val)
    {
        return false;
    }

    return check(left->left, right->right) && check(left->right, right->left);
}
bool isSymmetric(struct TreeNode* root){
    return check(root, root);
}