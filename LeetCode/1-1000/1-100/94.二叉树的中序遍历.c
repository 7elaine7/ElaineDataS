/*
94. 二叉树的中序遍历
给定一个二叉树的根节点 root ，返回它的 中序 遍历。
示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]
示例 2：
输入：root = []
输出：[]
示例 3：
输入：root = [1]
输出：[1]
示例 4：
输入：root = [1,2]
输出：[2,1]
示例 5：
输入：root = [1,null,2]
输出：[1,2]
提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
进阶: 递归算法很简单，你可以通过迭代算法完成吗？
*/

//function 1, 递归
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
#define NUM 100
typedef struct TreeNode Node;
void search(Node* root, int* count, int* array)
{
    if(!root)
        return;
    search(root->left, count, array);
    array[(*count)++] = root->val;
    search(root->right, count, array);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int count = 0;
    int* array = (int*)malloc(sizeof(int) * NUM);
    search(root, &count, array);
    int* res = (int*)malloc(sizeof(int) * count);
    for(int i = 0; i < count; ++i)
    {
        res[i] = array[i];
    }
    free(array);
    *returnSize = count;
    return res;
}


//function 2, 栈，迭代
#define NUM 100
typedef struct TreeNode Node;
int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * NUM);
    *returnSize = 0;
    if(!root)
        return NULL;
    Node** stack = (Node**)malloc(sizeof(Node*) * NUM);
    int top = 0;
    stack[top] = root;
    while(top >= 0)
    {
        if(stack[top]->left)
        {
            stack[top+1] = stack[top]->left;
            stack[top]->left = NULL;
            top++;
        }
        else
        {
            res[(*returnSize)++] = stack[top]->val;
            if(stack[top]->right)
            {
                Node* tmp = stack[top];
                stack[top] = stack[top]->right;                
                tmp->right = NULL;
            }
            else
            {
                top--;
            }
        }  
    }

    return res;
}
