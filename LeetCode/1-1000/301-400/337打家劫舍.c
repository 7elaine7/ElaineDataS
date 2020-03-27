/*
337. 打家劫舍 III
在上次打劫完一条街道之后和一圈房屋后，小偷又发现了一个新的可行窃的地区。
这个地区只有一个入口，我们称之为“根”。 除了“根”之外，每栋房子有且只有一个“父“房子与之相连。
一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 
如果两个直接相连的房子在同一天晚上被打劫，房屋将自动报警。
计算在不触动警报的情况下，小偷一晚能够盗取的最高金额。
示例 1:
输入: [3,2,3,null,3,null,1]

     3
    / \
   2   3
    \   \ 
     3   1

输出: 7 
解释: 小偷一晚能够盗取的最高金额 = 3 + 3 + 1 = 7.
示例 2:
输入: [3,4,5,1,3,null,1]

     3
    / \
   4   5
  / \   \ 
 1   3   1

输出: 9
解释: 小偷一晚能够盗取的最高金额 = 4 + 5 = 9.
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define MAX(a, b) (a > b ? a : b)
int* getMax(struct TreeNode *node)
{
    //sum[0]不取当前结点情况的最大值, sum[1]取当前结点情况的最大值
    int *sum = (int*)malloc(sizeof(int) * 2);
    memset(sum, 0, sizeof(int) * 2);
    if(!node)
    {
        return sum;
    }

    int* left = getMax(node->left);
    int* right = getMax(node->right);

    sum[0] = MAX(left[0], left[1]) + MAX(right[0], right[1]);
    sum[1] = node->val + left[0] + right[0];
    return sum;
}
int rob(struct TreeNode* root){
    int* sum = getMax(root);
    return MAX(sum[0], sum[1]);
}