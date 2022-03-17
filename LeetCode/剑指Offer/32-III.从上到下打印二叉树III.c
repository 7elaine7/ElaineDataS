/*
剑指 Offer 32 - III. 从上到下打印二叉树 III
请实现一个函数按照之字形顺序打印二叉树，即第一行按照从左到右的顺序打印，第二层按照从右到左的顺序打印，第三行再按照从左到右的顺序打印，其他行以此类推。
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
  [20,9],
  [15,7]
]
提示：
节点总数 <= 1000
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
#define NUM 1001
typedef struct TreeNode Node;
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * NUM);
    int** res = (int**)malloc(sizeof(int*) * NUM);
    if(!root)
        return res;
    Node** queue = (Node**)malloc(sizeof(Node*) * 2 * NUM);
    int head = 0;
    int tail = 1;
    queue[0] = root;
    while(head < tail)
    {
        int len = tail - head;
        (*returnColumnSizes)[*returnSize] = len;
        res[*returnSize] = (int*)malloc(sizeof(int) * len);

        if((*returnSize) % 2 == 0)  //偶数正序，奇数倒序
        {
            int tmp = head;
            for(int i = 0; i < len; ++i)
            {
                res[*returnSize][i] = queue[tmp++]->val;
            }
        }
        else
        {
            int tmp = tail - 1;
            for(int i = 0; i < len; ++i)
            {
                res[*returnSize][i] = queue[tmp--]->val;
            }
        }
        (*returnSize)++;
        for(int i = 0; i < len; ++i)
        {
            Node* tmp = queue[head++];
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

    free(queue);
    return res;
}