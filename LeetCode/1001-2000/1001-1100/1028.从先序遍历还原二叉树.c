/*
1028. 从先序遍历还原二叉树
我们从二叉树的根节点 root 开始进行深度优先搜索。
在遍历中的每个节点处，我们输出 D 条短划线（其中 D 是该节点的深度），然后输出该节点的值。（如果节点的深度为 D，则其直接子节点的深度为 D + 1。根节点的深度为 0）。
如果节点只有一个子节点，那么保证该子节点为左子节点。
给出遍历输出 S，还原树并返回其根节点 root。
示例 1：
输入："1-2--3--4-5--6--7"
输出：[1,2,5,3,4,6,7]
示例 2：
输入："1-2--3---4-5--6---7"
输出：[1,2,5,3,null,6,null,4,null,7]
示例 3：
输入："1-401--349---90--88"
输出：[1,401,null,349,88,90]
提示：
原始树中的节点数介于 1 和 1000 之间。
每个节点的值介于 1 和 10 ^ 9 之间。
*/
//function 1， 递归， 比较慢
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct TreeNode Node;
//想用全局指针对s实时改变，但是并没有实现，所以用全局变量来记录s的变化
int g_index;
Node* deserialize(char* s, int level)
{
    if(g_index == strlen(s))
        return NULL;
    int p = g_index;
    int count = 0;
    while(p < strlen(s) && s[p] == '-')
    {
        p++;
        count++;
    }

    if(count != level)
        return NULL;
    //生成新节点
    Node* root = (Node*)malloc(sizeof(Node));
    char* tmp = (char*)malloc(sizeof(char) * 10);
    int i;
    for(i = 0; p < strlen(s) && s[p] != '-'; ++i)
    {
        tmp[i] = s[p++];
    }
    tmp[i] = '\0';
    root->val = atoi(tmp);
    g_index = p;
    root->left = deserialize(s, level + 1);
    root->right = deserialize(s, level + 1);
    return root;

}
struct TreeNode* recoverFromPreorder(char * S){
    g_index = 0;
    return deserialize(S, 0);
}

//function 2, 栈
//如果栈顶元素index 小于当前新元素level，那么栈定元素可以作为当前新元素父节点， 链接后当前新元素入栈
//否则站内元素出栈，直到栈定index小于当前新元素level
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define SIZE 30
typedef struct TreeNode Node;
Node* create_new(int data)
{
    Node* new = (Node*)malloc(sizeof(Node));
    new->val = data;
    new->left = NULL;
    new->right = NULL;
    return new;
}
struct TreeNode* recoverFromPreorder(char * S){
    Node** stack = (Node**)malloc(sizeof(Node*) * SIZE);
    int top = -1;
    int size = strlen(S);
    int count = 0;
    Node* head;
    while(count < size)
    {
        int level = 0;
        //求level
        while(count < size && S[count] == '-')
        {
            level++;
            count++;
        }
        //求值
        char* tmp = (char*)malloc(sizeof(char) * 10);
        int i = 0;
        while(count < size && S[count] != '-')
        {
            tmp[i++] = S[count++];
        }
        tmp[i] = '\0';
        int data = atoi(tmp);
        Node* new = create_new(data);
        if(top == -1)
        {
            head = new;
            stack[++top] = new;
            continue;
        }
        while(level <= top)
        {
            top--;
        }
        if(stack[top]->left == NULL)
            stack[top]->left = new;
        else if(stack[top]->right == NULL)
            stack[top]->right = new;
        stack[++top] = new;
    }
    return head;
}