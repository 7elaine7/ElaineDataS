/*
542. 01 矩阵
给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
两个相邻元素间的距离为 1 。
示例 1:
输入:
0 0 0
0 1 0
0 0 0
输出:
0 0 0
0 1 0
0 0 0
示例 2:
输入:
0 0 0
0 1 0
1 1 1
输出:
0 0 0
0 1 0
1 2 1
注意:
给定矩阵的元素个数不超过 10000。
给定矩阵中至少有一个元素是 0。
矩阵中的元素只在四个方向上相邻: 上、下、左、右。
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

//function 1 + visited 超时
typedef struct node{
    int r;
    int c;
    int level;
}Node;
int dfs(int** matrix, int rsize, int csize, int row, int col)
{
    if(0 == matrix[row][col])
        return 0;
    Node* queue = (Node*)malloc(sizeof(Node) * rsize * csize * 5);
    int** visited = (int**)malloc(sizeof(int*) * rsize);
    for(int i = 0; i < rsize; ++i)
    {
        visited[i] = (int*)malloc(sizeof(int) * csize);
        memset(visited[i], 0, sizeof(int) * csize);
    }
    int head = 0;
    int tail = 0;
    int delt_r[4] = {-1, 0, 1, 0};
    int delt_c[4] = {0, 1, 0, -1};
    queue[tail].level = 0;
    queue[tail].r = row;
    queue[tail++].c = col;
    visited[row][col] = 1;
    while(head != tail)
    {
        for(int i = 0; i < 4; ++i)
        {
            int tmp_r = queue[head].r + delt_r[i];
            int tmp_c = queue[head].c + delt_c[i];
            int tmp_l = queue[head].level + 1;
            if(tmp_r < 0 || tmp_r >= rsize || tmp_c < 0 || tmp_c >= csize || visited[tmp_r][tmp_c] == 1)
            {
                continue;
            }
            if(0 == matrix[tmp_r][tmp_c])
            {
                return tmp_l;
            }
            queue[tail].r = tmp_r;
            queue[tail].c = tmp_c;
            queue[tail++].level = tmp_l;
            visited[tmp_r][tmp_c] = 1;
        }
        head++;
    }
    return -1;
}
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int rsize = matrixSize;
    int csize = *matrixColSize;
    int** array = (int**)malloc(sizeof(int*) * rsize);
    for(int i = 0; i < rsize; ++i)
    {
        array[i] = (int*)malloc(sizeof(int) * csize);
        memset(array[i], 0, sizeof(int) * csize);
    }

    for(int i = 0; i < rsize; ++i)
    {
        for(int j = 0; j < csize; ++j)
        {
            array[i][j] = dfs(matrix, rsize, csize, i, j);
        }
    }
    *returnSize = rsize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * rsize);
    for (int i = 0; i < rsize; i++) {
        (*returnColumnSizes)[i] = csize;
    }
    return array;
}

//function 2，不加visited，超时，比function 1快一点
typedef struct node{
    int r;
    int c;
    int level;
}Node;
int dfs(int** matrix, int rsize, int csize, int row, int col)
{
    if(0 == matrix[row][col])
        return 0;
    Node* queue = (Node*)malloc(sizeof(Node) * rsize * csize * 5);
    int head = 0;
    int tail = 0;
    int delt_r[4] = {-1, 0, 1, 0};
    int delt_c[4] = {0, 1, 0, -1};
    queue[tail].level = 0;
    queue[tail].r = row;
    queue[tail++].c = col;
    while(head != tail)
    {
        for(int i = 0; i < 4; ++i)
        {
            int tmp_r = queue[head].r + delt_r[i];
            int tmp_c = queue[head].c + delt_c[i];
            int tmp_l = queue[head].level + 1;
            if(tmp_r < 0 || tmp_r >= rsize || tmp_c < 0 || tmp_c >= csize)
            {
                continue;
            }
            if(0 == matrix[tmp_r][tmp_c])
            {
                return tmp_l;
            }
            queue[tail].r = tmp_r;
            queue[tail].c = tmp_c;
            queue[tail++].level = tmp_l;
        }
        head++;
    }
    return -1;
}
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int rsize = matrixSize;
    int csize = *matrixColSize;
    int** array = (int**)malloc(sizeof(int*) * rsize);
    for(int i = 0; i < rsize; ++i)
    {
        array[i] = (int*)malloc(sizeof(int) * csize);
        memset(array[i], 0, sizeof(int) * csize);
    }

    for(int i = 0; i < rsize; ++i)
    {
        for(int j = 0; j < csize; ++j)
        {
            array[i][j] = dfs(matrix, rsize, csize, i, j);
        }
    }
    *returnSize = rsize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * rsize);
    for (int i = 0; i < rsize; i++) {
        (*returnColumnSizes)[i] = csize;
    }
    return array;
}

//function 3
/*
首先将0入处理队列，再依次寻找处理队列中点的四周为1的点，入队，level++，标记为已处理
*/
typedef struct node{
    int r;
    int c;
    int level;
}Node;
int** updateMatrix(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes){
    int rsize = matrixSize;
    int csize = *matrixColSize;
    int** array = (int**)malloc(sizeof(int*) * rsize);
    for(int i = 0; i < rsize; ++i)
    {
        array[i] = (int*)malloc(sizeof(int) * csize);
        memset(array[i], 0, sizeof(int) * csize);
    }

    //建造标记矩阵
    int** visited = (int**)malloc(sizeof(int*) * rsize);
    for(int i = 0; i < rsize; ++i)
    {
        visited[i] = (int*)malloc(sizeof(int) * csize);
        memset(visited[i], 0, sizeof(int) * csize);
    }
    //建造待处理队列
    Node* queue = (Node*)malloc(sizeof(Node) * rsize * csize * 5);
    int head = 0;
    int tail = 0;
    //为0的全部入队
    for(int i = 0; i < rsize; ++i)
    {
        for(int j = 0; j < csize; ++j)
        {
            if(0 == matrix[i][j])
            {
                queue[tail].r = i;
                queue[tail].c = j;
                queue[tail++].level = 0;
                visited[i][j] = 1;
                array[i][j] = 0;
            }
        }
    }
    //四个处理方向
    int delt_r[4] = {-1, 0, 1, 0};
    int delt_c[4] = {0, 1, 0, -1};
    //处理queue中结点的四周，遇到1结点入队，level++，标记为已访问1
    while(head < tail)
    {
        for(int i = 0; i < 4; ++i)
        {
            int tmp_r = queue[head].r + delt_r[i];
            int tmp_c = queue[head].c + delt_c[i];
            if(tmp_r < 0 || tmp_r >= rsize || tmp_c < 0 || tmp_c >= csize || visited[tmp_r][tmp_c] == 1)
            {
                continue;
            }
            if(1 == matrix[tmp_r][tmp_c])
            {
                int tmp_l = queue[head].level + 1;
                array[tmp_r][tmp_c] = tmp_l;
                queue[tail].r = tmp_r;
                queue[tail].c = tmp_c;
                queue[tail++].level = tmp_l;
                visited[tmp_r][tmp_c] = 1;
            }
        }
        head++; 
    }
    *returnSize = rsize;
    *returnColumnSizes = (int*)malloc(sizeof(int) * rsize);
    for (int i = 0; i < rsize; i++) {
        (*returnColumnSizes)[i] = csize;
    }
    return array;
}