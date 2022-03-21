/*
653. 两数之和 IV - 输入 BST
给定一个二叉搜索树 root 和一个目标结果 k，如果 BST 中存在两个元素且它们的和等于给定的目标结果，则返回 true。

 

示例 1：


输入: root = [5,3,6,2,4,null,7], k = 9
输出: true
示例 2：


输入: root = [5,3,6,2,4,null,7], k = 28
输出: false
提示:
二叉树的节点个数的范围是  [1, 104].
-104 <= Node.val <= 104
root 为二叉搜索树
-105 <= k <= 105
*/
//function 1, 哈希 + DFS
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;
typedef struct{
    int key;
    UT_hash_handle hh;
}Hash;
bool find(Node* root, int k, Hash* hashtable)
{
    if(!root)
        return false;
    int key = k - root->val;
    Hash* s = NULL;
    HASH_FIND_INT(hashtable, &key, s);
    if(s)
        return true;
    s = (Hash*)malloc(sizeof(Hash));
    s->key = root->val;
    HASH_ADD_INT(hashtable, key, s);
    return find(root->left, k, hashtable) || find(root->right, k, hashtable);
}
bool findTarget(struct TreeNode* root, int k){
    Hash* hashtable;
    return find(root, k, hashtable);

}

//function 2, 中序遍历从小到大，查找
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define NUM 1e4
typedef struct TreeNode Node;
void Inorder(Node* root, int* array, int* pos)
{
    if(!root)
        return;
    Inorder(root->left, array, pos);
    array[(*pos)++] = root->val;
    Inorder(root->right, array, pos);
}
bool findTarget(struct TreeNode* root, int k){
    int* array = (int*)malloc(sizeof(int) * NUM);
    int pos = 0;
    Inorder(root, array, &pos);
    int left = 0;
    int right = pos - 1;
    while(left < right)
    {
        int sum = array[left] + array[right];
        if(sum == k)
            return true;
        else if(sum < k)
            left++;
        else
            right--;
    }
    return false;
}