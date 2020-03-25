/*
892. 三维形体的表面积
在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
请你返回最终形体的表面积。
示例 1：
输入：[[2]]
输出：10
示例 2：
输入：[[1,2],[3,4]]
输出：34
示例 3：
输入：[[1,0],[0,2]]
输出：16
示例 4：
输入：[[1,1,1],[1,0,1],[1,1,1]]
输出：32
示例 5：
输入：[[2,2,2],[2,1,2],[2,2,2]]
输出：46 

提示：
1 <= N <= 50
0 <= grid[i][j] <= 50
*/

int surfaceArea(int** grid, int gridSize, int* gridColSize){
    int sum = 0;
    for(int i = 0; i < gridSize; ++i)
    {
        for(int j = 0; j < *gridColSize; ++j)
        {
            int tmp = grid[i][j];
            int result;
            //第一面
            if(i < 1)
                result = tmp;        
            else
                result = tmp - grid[i-1][j];           
            if(result >= 0)
                sum = sum + result;
            //第二面
            if(j+1 >= *gridColSize)
                result = tmp;
            else
                result = tmp - grid[i][j+1];
            if(result >= 0)
                sum = sum + result;       
            //第三面
            if(i+1 >= gridSize)
                result = tmp;
            else
                result = tmp - grid[i+1][j];
            if(result >= 0)
                sum = sum + result;
            //第四面
            if(j < 1)
                result = tmp;
            else
                result = tmp - grid[i][j-1];
            if(result >= 0)
                sum = sum + result;
            if(0 != tmp)
                sum = sum + 2;           
        }
    }
    return sum;
}