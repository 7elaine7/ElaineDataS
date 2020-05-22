/*
105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。
注意:
你可以假设树中没有重复的元素。
例如，给出
前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
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

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize){
    if(preorderSize <= 0 || inorderSize <= 0)
        return NULL;
    Node* p = (Node*)malloc(sizeof(Node));
    p->val = *preorder;
    p->left = NULL;
    p->right = NULL;
    int pos = 0;
    for(; pos < inorderSize; ++pos)
    {
        if(*preorder == inorder[pos])
            break;
    }
    p->left = buildTree(preorder + 1, pos, inorder, pos);
    p->right = buildTree(preorder + pos + 1, inorderSize - pos - 1, inorder + pos + 1, inorderSize - pos - 1);
    return p;
}