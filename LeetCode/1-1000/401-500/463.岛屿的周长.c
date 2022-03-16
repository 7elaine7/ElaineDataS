/*
463. 岛屿的周长
给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。
网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。
岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。
示例 1：
输入：grid = [[0,1,0,0],[1,1,1,0],[0,1,0,0],[1,1,0,0]]
输出：16
解释：它的周长是上面图片中的 16 个黄色的边
示例 2：
输入：grid = [[1]]
输出：4
示例 3：
输入：grid = [[1,0]]
输出：4
提示：
row == grid.length
col == grid[i].length
1 <= row, col <= 100
grid[i][j] 为 0 或 1
*/
//function 1, BFS
#define NUM 10000
typedef struct node{
    int x;
    int y;
}Node;
//0:水域，1:陆地，2:已访问，
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int count = 0;
    Node* queue = (Node*)malloc(sizeof(Node) * NUM);
    int head = 0;
    int tail = 0;
    //寻找第一个陆地
    bool flag = false;
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < *gridColSize; ++j)
        {
            if(grid[i][j] == 1)
            {
                flag = true;
                grid[i][j] = 2;
                queue[head].x = i;
                queue[head].y = j;
                tail++;
                break;
            }
        }
        if(flag)
            break;
    }
    if(!flag)
        return count;
    
    int delta_x[4] = {-1, 0, 1, 0};
    int delta_y[4] = {0, -1, 0, 1};

    while(head < tail)
    {
        for(int i = 0; i < 4; ++i)
        {
            int tmpx = queue[head].x + delta_x[i];
            int tmpy = queue[head].y + delta_y[i];
            if(tmpx < 0 || tmpx >= gridSize || tmpy < 0 || tmpy >= *gridColSize || grid[tmpx][tmpy] == 0)
            {
                count++;
            }
            else if(grid[tmpx][tmpy] == 1)
            {
                queue[tail].x = tmpx;
                queue[tail++].y = tmpy;
                grid[tmpx][tmpy] = 2;
            }
        }
        head++;
    }
    return count; 
}

//function 2, DFS
//0:水域，1:陆地，2:已访问
void DFS(int** grid, int x, int y, int row, int col, int* count)
{
    int delta_x[4] = {-1, 0, 1, 0};
    int delta_y[4] = {0, -1, 0, 1};
    for(int i = 0; i < 4; ++i)
    {
        int tmpx = x + delta_x[i];
        int tmpy = y + delta_y[i];
        if(tmpx < 0 || tmpx >= row || tmpy < 0 || tmpy >= col || grid[tmpx][tmpy] == 0)
        {
            (*count)++;
        }
        else if(grid[tmpx][tmpy] == 1)
        {
            grid[tmpx][tmpy] = 2;
            DFS(grid, tmpx, tmpy, row, col, count);
        }
    }
}
int islandPerimeter(int** grid, int gridSize, int* gridColSize){
    int count = 0;
    //寻找第一个陆地

    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < *gridColSize; ++j)
        {
            if(grid[i][j] == 1)
            {
                grid[i][j] = 2;
                DFS(grid, i, j, gridSize, *gridColSize, &count);
                return count;
            }
        }
    }
 
    return count; 
}
