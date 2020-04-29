/*
面试题 04.06. 后继者
设计一个算法，找出二叉搜索树中指定节点的“下一个”节点（也即中序后继）。
如果指定节点没有对应的“下一个”节点，则返回null。
示例 1:
输入: root = [2,1,3], p = 1

  2
 / \
1   3
输出: 2
示例 2:
输入: root = [5,3,6,2,4,null,null,1], p = 6

      5
     / \
    3   6
   / \
  2   4
 /   
1
输出: null
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

//中序遍历
typedef struct TreeNode Node;
void search(Node* root, Node* p, Node** result, int* flag)
{
    if(root == NULL)
        return;
    search(root->left, p, result, flag);
    if(1 == *flag)
    {
        *result = root;
        *flag = 0;
        return;
    }
    if(root == p && 0 == *flag)
        *flag = 1;
    search(root->right, p, result, flag);      
}

struct TreeNode* inorderSuccessor(struct TreeNode* root, struct TreeNode* p){
    if(NULL == root || NULL == p)
        return NULL;
    int flag = 0;
    Node* result = NULL;
    search(root, p, &result, &flag);
    return result;
}