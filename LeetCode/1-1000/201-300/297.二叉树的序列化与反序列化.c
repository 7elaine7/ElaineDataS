/*
297. 二叉树的序列化与反序列化
序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
示例: 
你可以将以下二叉树：

    1
   / \
  2   3
     / \
    4   5

序列化为 "[1,2,3,null,null,4,5]"
提示: 这与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
说明: 不要使用类的成员 / 全局 / 静态变量来存储状态，你的序列化和反序列化算法应该是无状态的。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
#define SIZE 77777
typedef struct TreeNode Node;
/** Encodes a tree to a single string. */
void enSerialize(Node* root, char* res)
{
    if(!root)
    {
        //char *strcat(char *dest, const char *src) 把 src 所指向的字符串追加到 dest 所指向的字符串的结尾。
        strcat(res, "null,");
        return;
    }
    char* tmp = (char*)malloc(sizeof(char) * 6);
    memset(tmp, 0, sizeof(char) * 6);
    //格式化输出到字符串tmp，结尾自动加\0
    sprintf(tmp, "%d,", root->val);
    strcat(res, tmp);
    enSerialize(root->left, res);
    enSerialize(root->right, res);
}
char* serialize(struct TreeNode* root) {
    if(!root)
        return "null";
    char* res = (char*)malloc(sizeof(char) * SIZE);
    memset(res, 0, sizeof(char) * SIZE);
    enSerialize(root, res);
    return res;
}

/** Decodes your encoded data to tree. */
Node* des(char* data)
{
    //strtok将data分解，返回分隔符分开的第一个字符串
    //第一次传入字符串指针，之后每次都是null
    char* tmp = strtok(data, ",");
    if(!strcmp(tmp, "null"))
        return NULL;
    //建立新节点存储分割出的字符串节点
    Node* new = (Node*)malloc(sizeof(Node));
    //atoi将字符串转换成整数
    new->val = atoi(tmp);

    //strtok下一次传的时候用null
    new->left = des(NULL);
    new->right = des(NULL);
    return new;
}
struct TreeNode* deserialize(char* data) {
    if(!strcmp(data, "null"))
        return NULL;
    return des(data);
}

// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);