/*
695. 岛屿的最大面积
给定一个包含了一些 0 和 1 的非空二维数组 grid 。
一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。
你可以假设 grid 的四个边缘都被 0（代表水）包围着。
找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)
示例 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
示例 2:
[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。
*/
typedef struct node{
    int x;
    int y;
}Node;
void bfs(int** grid, int row, int col, int x, int y, int* max)
{
    Node* queue = (Node*)malloc(sizeof(Node) * row * col);
    int head = 0;
    int tail = 0;
    int delt_x[4] = {0, 0, 1, -1};
    int delt_y[4] = {1, -1, 0, 0};
    queue[tail].x = x;
    queue[tail++].y = y;
    grid[x][y] = 0;
    while(head < tail)
    {
        for(int i = 0; i < 4; ++i)
        {
            int tmp_x = queue[head].x + delt_x[i];
            int tmp_y = queue[head].y + delt_y[i];
            if(tmp_x >= 0 && tmp_x < row && tmp_y >= 0 && tmp_y < col && grid[tmp_x][tmp_y] == 1)
            {
                queue[tail].x = tmp_x;
                queue[tail++].y = tmp_y;
                grid[tmp_x][tmp_y] = 0;
            }
        }
        head++;
    }
    if(tail > *max)
        *max = tail;
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int tail = 0;
    int max = 0;
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < *gridColSize; ++j)
        {
            if(grid[i][j] == 1)
            {
                bfs(grid, gridSize, *gridColSize, i, j, &max);
            }
        }
    }
    return max;
}