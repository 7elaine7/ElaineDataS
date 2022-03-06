/*
剑指 Offer II 116. 省份数量
有 n 个城市，其中一些彼此相连，另一些没有相连。如果城市 a 与城市 b 直接相连，且城市 b 与城市 c 直接相连，那么城市 a 与城市 c 间接相连。
省份 是一组直接或间接相连的城市，组内不含其他没有相连的城市。
给你一个 n x n 的矩阵 isConnected ，其中 isConnected[i][j] = 1 表示第 i 个城市和第 j 个城市直接相连，而 isConnected[i][j] = 0 表示二者不直接相连。
返回矩阵中 省份 的数量。

示例 1：
输入：isConnected = [[1,1,0],[1,1,0],[0,0,1]]
输出：2

示例 2：
输入：isConnected = [[1,0,0],[0,1,0],[0,0,1]]
输出：3

提示：
1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] 为 1 或 0
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/
int find_parent(int* parent, int x)
{
    //压缩优化树的层数
    while(x != parent[x])
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void make_connect(int* parent, int* weight, int x, int y, int* count)
{
    int root_x = find_parent(parent, x);
    int root_y = find_parent(parent, y);
    if(root_x == root_y)
        return;
    if(weight[root_x] < weight[root_y])
    {
        parent[root_x] = root_y;
    }
    else if(weight[root_y] < weight[root_x])
    {
        parent[root_y] = root_x;
    }
    else
    {
        parent[root_x] = root_y;
        weight[root_y] += 1;
    }
    (*count) -= 1;
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int* parent = (int*)malloc(sizeof(int) * isConnectedSize);
    int* weight = (int*)malloc(sizeof(int) * isConnectedSize);
    for(int i = 0; i < isConnectedSize; ++i)
    {
        parent[i] = i;
        weight[i] = 1; 
    }
    int count = isConnectedSize;

    for(int i = 0; i < isConnectedSize; ++i)
    {
        for(int j = 0; j < *isConnectedColSize; ++j)
        {
            if(isConnected[i][j] == 1)
            {
                make_connect(parent, weight, i, j, &count);
            }
        }
    }
    free(parent);
    free(weight);
    return count;
}
