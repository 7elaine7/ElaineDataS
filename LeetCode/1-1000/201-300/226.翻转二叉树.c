/*
226. 翻转二叉树
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
示例 1：
输入：root = [4,2,7,1,3,6,9]
输出：[4,7,2,9,6,3,1]
示例 2：
输入：root = [2,1,3]
输出：[2,3,1]
示例 3：
输入：root = []
输出：[]
提示：
树中节点数目范围在 [0, 100] 内
-100 <= Node.val <= 100
*/
//funtion 1, BFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#define NUM 101
typedef struct TreeNode Node;
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return root;
    Node** queue = (Node**)malloc(sizeof(Node*) * NUM);
    int head = 0;
    int tail = 1;
    queue[head] = root;
    while(head < tail)
    {
        
        if(queue[head]->left)
        {
            queue[tail++] = queue[head]->left;
        }
        if(queue[head]->right)
        {
            queue[tail++] = queue[head]->right;
        }
        Node* tmp = queue[head]->left;
        queue[head]->left = queue[head]->right;
        queue[head++]->right = tmp; 
    }
    return root;
}

//function 2, DFS
typedef struct TreeNode Node;
struct TreeNode* invertTree(struct TreeNode* root){
    if(!root)
        return root;
    Node* left = invertTree(root->left);
    Node* right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}