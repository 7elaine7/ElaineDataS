/*
102. 二叉树的层序遍历
给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。
示例：
二叉树：[3,9,20,null,null,15,7],

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
#define SIZE 800
typedef struct TreeNode Node;
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** res = (int**)malloc(sizeof(int*) * SIZE);
    *returnSize = 0;
    if(NULL == root)
        return res;
    Node* queue = (Node*)malloc(sizeof(Node) * SIZE * 2);
    int head = -1;
    int tail = 0;
    queue[tail] = *root;
    int level = -1;
    int* tmp = (int*)malloc(sizeof(int) * SIZE);

    while(head < tail)
    {
        int len = tail - head;
        res[++level] = (int*)malloc(sizeof(int) * len);
        tmp[level] = len;
        int count = 0;
        while(len > 0)
        {
            ++head;
            if(count < tmp[level])
            {
                res[level][count++] = queue[head].val;
            }
            if(queue[head].left)
            {
                queue[++tail] = *(queue[head].left);
            }
            if(queue[head].right)
            {
                queue[++tail] = *(queue[head].right);
            }
            len--;
        }
    }
    *returnSize = level + 1;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i)
    {
        (*returnColumnSizes)[i] = tmp[i];
    }
    return res;
}

//function 2, DFS
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
#define SIZE 800
typedef struct TreeNode Node;
void dfs(int** res, Node* root, int level, int* returnSize, int* tmp)
{
    if(NULL == root)
        return;
    if(level == *returnSize)
    {
        res[level] = (int*)malloc(sizeof(int) * SIZE);
        (*returnSize)++;
    }
    res[level][tmp[level]] = root->val;
    tmp[level] += 1;
    if(root->left)
        dfs(res, root->left, level + 1, returnSize, tmp);
    if(root->right)
        dfs(res, root->right, level + 1, returnSize, tmp);
}
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** res = (int**)malloc(sizeof(int*) * SIZE);
    *returnSize = 0;
    int level = 0;
    //记录每一层的个数
    int* tmp = (int*)malloc(sizeof(int) * SIZE);
    memset(tmp, 0, sizeof(int) * SIZE);
    dfs(res, root, level, returnSize, tmp);
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i)
    {
        (*returnColumnSizes)[i] = tmp[i];
    }
    return res;
}