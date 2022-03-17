/*
剑指 Offer 32 - II. 从上到下打印二叉树 II
从上到下按层打印二叉树，同一层的节点按从左到右的顺序打印，每一层打印到一行。
例如:
给定二叉树: [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回其层次遍历结果：

[
  [3],
  [9,20],
  [15,7]
]
提示：
节点总数 <= 1000
注意：本题与主站 102 题相同：https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
*/

//function 1, BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define NUM 1001
typedef struct TreeNode Node;
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** res = (int**)malloc(sizeof(int*) * NUM);
    *returnColumnSizes = (int*)malloc(sizeof(int) * NUM);
    *returnSize = 0;
    if(!root)
        return res;
    int** queue = (int**)malloc(sizeof(int*) * 2 * NUM);
    int head = 0;
    int tail = 1;
    queue[0] = root;
    while(head < tail)
    {
        int len = tail - head;
        res[*returnSize] = (int*)malloc(sizeof(int) * len);
        (*returnColumnSizes)[*returnSize] = len;
        for(int i = 0; i < len; ++i)
        {
            Node* tmp = queue[head++];
            res[*returnSize][i] = tmp->val;
            if(tmp->left)
            {
                queue[tail++] = tmp->left;
            }
            if(tmp->right)
            {
                queue[tail++] = tmp->right;
            }
        }
        (*returnSize)++;
    }
    return res;
}