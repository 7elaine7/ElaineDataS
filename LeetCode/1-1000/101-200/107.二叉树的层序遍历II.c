/*
107. 二叉树的层序遍历 II
给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[15,7],[9,20],[3]]
示例 2：
输入：root = [1]
输出：[[1]]
示例 3：
输入：root = []
输出：[]
提示：
树中节点数目在范围 [0, 2000] 内
-1000 <= Node.val <= 1000
*/
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
#define NUM 2001
typedef struct TreeNode Node;
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * NUM);
    int** res = (int**)malloc(sizeof(int*) * NUM);
    if(!root)
        return res;
    Node** queue = (Node**)malloc(sizeof(Node*) * NUM);
    int head = 0;
    int tail = 1;
    queue[head] = root;
    while(head < tail)
    {
        int count = tail - head;
        (*returnColumnSizes)[*returnSize] = count;
        int* array = (int*)malloc(sizeof(int) * count);
        res[(*returnSize)++] = array;
        for(int i = 0; i < count; ++i)
        {
            Node* tmp = queue[head++];
            array[i] = tmp->val;
            if(tmp->left)
            {
                queue[tail++] = tmp->left;
            }
            if(tmp->right)
            {
                queue[tail++] = tmp->right;
            }
        }
    }
    //上下置换
    for(int i = 0; 2 * i + 1 < *returnSize; ++i)
    {
        int tmp = (*returnColumnSizes)[i];
        int* number = res[i];
        int swap = *returnSize - i - 1;
        (*returnColumnSizes)[i] = (*returnColumnSizes)[swap];
        res[i] = res[swap];
        (*returnColumnSizes)[swap] = tmp;
        res[swap] = number;
    }

    return res;
}