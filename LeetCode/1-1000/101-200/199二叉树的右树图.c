/*
199. 二叉树的右视图
给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
示例:
输入: [1,2,3,null,5,null,4]
输出: [1, 3, 4]
解释:

   1            <---
 /   \
2     3         <---
 \     \
  5     4       <---
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
 * Note: The returned array must be malloced, assume caller calls free().
 */
//找每一层的最右节点
//function q: DFS
#define SIZE 1000
void dfs(struct TreeNode* root, int level, int* size, int* array)
{
    if(root == NULL)
        return;
    //本层的最右节点已经加到队列中
    if(*size == level)
    {
        array[level] = root->val;
        (*size)++;
    }
    //遍历先右后左
    dfs(root->right, level + 1, size, array);
    dfs(root->left, level + 1, size, array);
}
int* rightSideView(struct TreeNode* root, int* returnSize){
    int* array = (int*)malloc(sizeof(int) * SIZE);
    *returnSize = 0;
    dfs(root, 0, returnSize, array);
    return array;
}

//function 2: BFS 每一层的最右结点
#define SIZE 1000
int* rightSideView(struct TreeNode* root, int* returnSize){
    int* array = (int*)malloc(sizeof(int) * SIZE);
    *returnSize = 0;
    if(NULL == root)
        return array;
    struct TreeNode* queue = (struct TreeNode*)malloc(sizeof(struct TreeNode) * SIZE);
    int head = -1;
    int tail = 0;
    int count = 0;
    queue[tail] = *root;
    while(head < tail)
    {
        int len = tail - head;
        while(len > 0)
        {
            ++head;
            //这一层剩最后一个，放入array
            if(1 == len)
            {
                array[count++] = queue[head].val;
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
    *returnSize = count;
    return array;
}