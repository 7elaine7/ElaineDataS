/*
108. 将有序数组转换为二叉搜索树
将一个按照升序排列的有序数组，转换为一棵高度平衡二叉搜索树。
本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
示例:
给定有序数组: [-10,-3,0,5,9],
一个可能的答案是：[0,-3,9,-10,null,5]，它可以表示下面这个高度平衡二叉搜索树：

      0
     / \
   -3   9
   /   /
 -10  5
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;
Node* b_search(int* nums, int l, int r)
{
    if(l > r)
        return NULL;
    //总是选择左边的
    int mid = l + (r - l) / 2;
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = nums[mid];
    new->left = b_search(nums, l, mid - 1);
    new->right = b_search(nums, mid + 1, r);
    return new;
}
struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    return b_search(nums, 0, numsSize - 1);
}