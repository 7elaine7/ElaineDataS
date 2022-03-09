/*
面试题 16.19. 水域大小
你有一个用于表示一片土地的整数矩阵land，该矩阵中每个点的值代表对应地点的海拔高度。若值为0则表示水域。由垂直、水平或对角连接的水域为池塘。池塘的大小是指相连接的水域的个数。编写一个方法来计算矩阵中所有池塘的大小，返回值需要从小到大排序。
示例：
输入：
[
  [0,2,1,0],
  [0,1,0,1],
  [1,1,0,1],
  [0,1,0,1]
]
输出： [1,2,4]
提示：
0 < len(land) <= 1000
0 < len(land[i]) <= 1000
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int comfunc(const void * a, const void * b)
{
    return *(int*)a < *(int*)b ? -1 : *(int*)a > *(int*)b;
}
int find_parent(int* parent, int x)
{
    //压缩优化
    while(parent[x] != x)
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void Union(int* parent, int* size, int x, int y, int* count)
{
    int root_x = find_parent(parent, x);
    int root_y = find_parent(parent, y);
    if(root_x == root_y)
        return;
    //池塘数量少的挂在数量多的上面
    if(size[root_x] > size[root_y])
    {
        parent[root_y] = root_x;
        size[root_x] += size[root_y];
    }
    else
    {
        parent[root_x] = root_y;
        size[root_y] += size[root_x];
    }
    (*count) -= 1;
}
void make_connect(int** land, int x, int y, int* parent, int* size, int row, int col, int* count)
{
    int dir[4][2] = {{1, -1}, {1, 0}, {1, 1}, {0,1}};
    for(int i = 0; i < 4; ++i)
    {
        int tmp_x = x + dir[i][0];
        int tmp_y = y + dir[i][1];

        if(tmp_x >= 0 && tmp_x < row && tmp_y >= 0 && tmp_y < col && land[tmp_x][tmp_y] == 0)
        {
            Union(parent, size, x * col + y, tmp_x * col + tmp_y, count);
        }
    }
}
int* pondSizes(int** land, int landSize, int* landColSize, int* returnSize){
    int num = landSize * (*landColSize);
    int* parent = (int*)malloc(sizeof(int) * num);
    int* size = (int*)malloc(sizeof(int) * num);
    int count = 0;

    for(int i = 0; i < num; ++i)
    {
        parent[i] = -1;  //每个点默认父节点是-1
        size[i] = 0;    //每个点默认为0个池塘
    }
    for(int i = 0; i < landSize; ++i)
    {
        for(int j = 0; j < *landColSize; ++j)
        {
            if(land[i][j] == 0)
            {
                count++;
                int tmp = i * (*landColSize) + j;
                size[tmp] = 1;      //每个池塘点默认池塘数为1
                parent[tmp] = tmp;  //每个池塘点默认父节点是自己
            }
        }
    }

    for(int i = 0; i < landSize; ++i)
    {
        for(int j = 0; j < *landColSize; ++j)
        {
            if(land[i][j] == 0)
            {
                make_connect(land, i, j, parent, size, landSize, *landColSize, &count);
            }
        }
    }

    *returnSize = count;
    int* res = (int*)malloc(sizeof(int) * count);

    int n = 0;
    for(int i = 0; i < num && n < count; ++i)
    {
        if(parent[i] == i)
        {
            res[n++] = size[i];
        }
    }
    qsort(res, count, sizeof(int), comfunc);

    return res;
}