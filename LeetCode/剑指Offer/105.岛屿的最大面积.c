/*
剑指 Offer II 105. 岛屿的最大面积
给定一个由 0 和 1 组成的非空二维数组 grid ，用来表示海洋岛屿地图。
一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。
找到给定的二维数组中最大的岛屿面积。如果没有岛屿，则返回面积为 0 。
示例 1:
输入: grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0,0,1,1,0,0,0,0]]
输出: 6
解释: 对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。
示例 2:
输入: grid = [[0,0,0,0,0,0,0,0]]
输出: 0
提示：
m == grid.length
n == grid[i].length
1 <= m, n <= 50
grid[i][j] is either 0 or 1
注意：本题与主站 695 题相同： https://leetcode-cn.com/problems/max-area-of-island/
*/

//function 1, BFS
typedef struct node{
    int x;
    int y;
}Node;
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max = 0;
    Node* queue = (Node*)malloc(sizeof(Node) * gridSize * (*gridColSize));
    int head = 0;
    int tail = 0;
    int delta_x[4] = {-1, 0, 0, 1};
    int delta_y[4] = {0, -1, 1, 0};
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < *gridColSize; ++j)
        {
            if(grid[i][j] == 1)
            {
                queue[tail].x = i;
                queue[tail++].y = j;
                grid[i][j] = 2;
                int count = 1;
                while(head < tail)
                {
                    for(int m = 0; m < 4; ++m)
                    {
                        int tmp_x = queue[head].x + delta_x[m];
                        int tmp_y = queue[head].y + delta_y[m];
                        if((tmp_x >= 0) && (tmp_x < gridSize) && (tmp_y >= 0) && (tmp_y < *gridColSize) && (grid[tmp_x][tmp_y] == 1))
                        {
                            count++;
                            grid[tmp_x][tmp_y] = 2;
                            queue[tail].x = tmp_x;
                            queue[tail++].y = tmp_y;
                        }
                    }
                    head++;
                }
                max = count > max ? count : max;
            }
        }
    }
    return max;
}

//function 2, DFS
typedef struct node{
    int x;
    int y;
}Node;
const int delta_x[4] = {-1, 0, 0, 1};
const int delta_y[4] = {0, -1, 1, 0};
void DFS(int** grid, int x, int y, int row, int col, int* count)
{
    for(int i = 0; i < 4; ++i)
    {
        int tmp_x = x + delta_x[i];
        int tmp_y = y + delta_y[i];
        if((tmp_x >= 0) && (tmp_x < row) && (tmp_y >= 0) && (tmp_y < col) && (grid[tmp_x][tmp_y] == 1))
        {
            (*count)++;
            grid[tmp_x][tmp_y] = 2;
            DFS(grid, tmp_x, tmp_y, row, col, count);
        }
    }
}
int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    int max = 0;
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < *gridColSize; ++j)
        {
            if(grid[i][j] == 1)
            {
                grid[i][j] = 2;
                int count = 1;
                DFS(grid, i, j, gridSize, *gridColSize, &count);
                max = count > max ? count : max;
            }
        }
    }
    return max;
}