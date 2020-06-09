/*
103. 二叉树的锯齿形层次遍历
给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层次遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
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


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#define SIZE 1000
typedef struct TreeNode Node;
void DFS(Node* root, int** res, int level, int* returnSize, int* count)
{
    if(!root)
        return;
    if(!res[level])
    {
        int size = (int)pow(2, level);
        res[level] = (int*)malloc(sizeof(int) * size);
        (*returnSize)++;
    }
    
    res[level][count[level]] = root->val;
    count[level] += 1;

    if(root->left)
        DFS(root->left, res, level + 1, returnSize, count);
    if(root->right)
        DFS(root->right, res, level + 1, returnSize, count);
}
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** res = (int**)malloc(sizeof(int*) * SIZE);
    for(int i = 0; i < SIZE; ++i)
    {
        res[i] = NULL;
    }
    *returnSize = 0;
    int level = 0;

    //记录每一层已经记录的个数
    int* count = (int*)malloc(sizeof(int) * SIZE);
    memset(count, 0, sizeof(int) * SIZE);

    DFS(root, res, level, returnSize, count);

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i)
    {
        (*returnColumnSizes)[i] = count[i];
    }

    //奇数层需要倒叙
    for(int i = 0; i < *returnSize; ++i)
    {
        if(i % 2 == 1)
        {
            int* tmp = (int*)malloc(sizeof(int) * count[i]);
            for(int n = count[i] - 1; n >= 0; --n)
            {
                tmp[count[i] - 1 - n] = res[i][n];
            }
            res[i] = tmp;
        }
    }
    return res;
}

//functin 2, BFS
#define SIZE 800
typedef struct TreeNode Node;
int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    int** res = (int**)malloc(sizeof(int*) * SIZE);
    *returnSize = 0;
    if(NULL == root)
        return res;
    Node* queue = (Node*)malloc(sizeof(Node) * SIZE * 2);
    int head = -1;
    int tail = 0;
    queue[tail] = *root;
    int level = -1;

    //记录每一层已经记录的个数
    int* count = (int*)malloc(sizeof(int) * SIZE);
    memset(count, 0, sizeof(int) * SIZE);

    while(head < tail)
    {
        int len = tail - head;  //每层个数
        res[++level] = (int*)malloc(sizeof(int) * len);
        count[level] = len;
        //偶数层正序，奇数层倒叙
        if(level % 2 == 0)
        {
            int n = 0;
            for(int i = head + 1; i <= tail; ++i)
            {
                res[level][n++] = queue[i].val;
            }
        }
        else
        {
            int n = 0;
            for(int i = tail; i > head; --i)
            {
                res[level][n++] = queue[i].val;
            }
        }
        //每个点相关联点入队列
        while(len > 0)
        {
            ++head;
            if(queue[head].left)
                queue[++tail] = *(queue[head].left);
            if(queue[head].right)
                queue[++tail] = *(queue[head].right);
            len--;
        }
    }
    *returnSize = level + 1;
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for(int i = 0; i < *returnSize; ++i)
    {
        (*returnColumnSizes)[i] = count[i];
    }

    return res;
}