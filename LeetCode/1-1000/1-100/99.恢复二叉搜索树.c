/*
99. 恢复二叉搜索树
二叉搜索树中的两个节点被错误地交换。
请在不改变其结构的情况下，恢复这棵树。
示例 1:

输入: [1,3,null,null,2]

   1
  /
 3
  \
   2

输出: [3,1,null,null,2]

   3
  /
 1
  \
   2
示例 2:

输入: [3,1,4,null,null,2]

  3
 / \
1   4
   /
  2

输出: [2,1,4,null,null,3]

  2
 / \
1   4
   /
  3
进阶:
使用 O(n) 空间复杂度的解法很容易实现。
你能想出一个只使用常数空间的解决方案吗？
*/


//function 1
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//int len, max_size;
int len;
#define SIZE 1000
typedef struct TreeNode Node;
void swap(Node* a, Node* b)
{
    int tmp = a->val;
    a->val = b->val;
    b->val = tmp;
}
//将tree中序遍历之后存入数组中
void inorder(Node* root, Node** array)
{
    if(root == NULL)
    {
        return;
    }
    inorder(root->left, array);
    array[len++] = root;
    /*
    if(len == max_size)
    {
        max_size = max_size * 2;
        printf("size = %d\n", max_size);
        array = (Node**)realloc(array, sizeof(Node*) * max_size);
    }*/
    inorder(root->right, array);
}
//查找数组中序列出问题的点，一个或者两个点出问题
int* find(Node** array)
{
    int* index = (int*)malloc(sizeof(int) * 2);
    index[0] = -1;
    index[1] = -1;
    for(int i = 0; i < len - 1; ++i)
    {
        if(array[i]->val > array[i + 1]->val)
        {
            //如果是两个点出问题，后面点的i+1项和前面点的i项交换
            //例如：1，6，3，4，5，2，出问题的6，3和5，2，需要6和2交换
            index[1] = i + 1;
            if(index[0] == -1)
            {
                index[0] = i;
            }
            else
                break;
        }
    }
    return index;
}
void recoverTree(struct TreeNode* root){
    len = 0;
//    max_size = 1;

    Node** array = (Node**)malloc(sizeof(Node*) * SIZE);
    //中序遍历，存入数组
    inorder(root, array);
    
    //找到出问题的逆序点
    int* index = find(array);
    swap(array[index[0]], array[index[1]]);
}

//function 2
//Morris遍历算法
typedef struct TreeNode Node;
void recoverTree(struct TreeNode* root){
    Node* x = NULL;
    Node* y = NULL;
    Node* pre = NULL;
    Node* predecessor = NULL;

    while(root)
    {
        //predecessor最右节点，当前节点向左走一步，之后一直向右走
        if(root->left)
        {
            predecessor = root->left;
            while(predecessor->right && predecessor->right != root)
            {
                predecessor = predecessor->right;
            }
            //将找到的predecessor右指针指向root，然后继续遍历左子树
            if(predecessor->right == NULL)
            {
                predecessor->right = root;
                root = root->left;
            }
            //如果predecessor右指针已经与root有链接，证明左子树已经遍历完
            else
            {
                if(pre && root->val < pre->val)
                {
                    y = root;
                    if(!x)
                        x = pre;
                }
                pre = root;
                //断开连接
                predecessor->right = NULL;
                root = root->right;
            }
            
        }
        else
        {
            if(pre && root->val < pre->val)
            {
                y = root;
                if(!x)
                    x = pre;
            }
            pre = root;
            root = root->right;
        }
    }
    int tmp = x->val;
    x->val = y->val;
    y->val = tmp;
}