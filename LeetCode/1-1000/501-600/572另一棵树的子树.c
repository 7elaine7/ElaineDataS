/*
572. 另一个树的子树
给定两个非空二叉树 s 和 t，检验 s 中是否包含和 t 具有相同结构和节点值的子树。
s 的一个子树包括 s 的一个节点和这个节点的所有子孙。s 也可以看做它自身的一棵子树。
示例 1:
给定的树 s:

     3
    / \
   4   5
  / \
 1   2
给定的树 t：

   4 
  / \
 1   2
返回 true，因为 t 与 s 的一个子树拥有相同的结构和节点值。
示例 2:
给定的树 s：

     3
    / \
   4   5
  / \
 1   2
    /
   0
给定的树 t：

   4
  / \
 1   2
返回 false。
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
bool compare(Node* r1, Node* r2)
{
    if((r1 == NULL) && (r2 == NULL))
        return true;
    if(!r1 || !r2)
        return false;
    if(r1->val != r2->val)
        return false;
    //如果当前结点相同接下来比较下面的子树
    return compare(r1->left, r2->left) && compare(r1->right, r2->right);
}


bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    if(!s)
        return false;
    return compare(s,t) || isSubtree(s->left, t) || isSubtree(s->right, t);
}