/*
剑指 Offer II 112. 最长递增路径
给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
对于每个单元格，你可以往上，下，左，右四个方向移动。 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
示例 1：
输入：matrix = [[9,9,4],[6,6,8],[2,1,1]]
输出：4 
解释：最长递增路径为 [1, 2, 6, 9]。
示例 2：
输入：matrix = [[3,4,5],[3,2,6],[2,2,1]]
输出：4 
解释：最长递增路径是 [3, 4, 5, 6]。注意不允许在对角线方向上移动。
示例 3：
输入：matrix = [[1]]
输出：1
提示：
m == matrix.length
n == matrix[i].length
1 <= m, n <= 200
0 <= matrix[i][j] <= 231 - 1
*/
const int delta_x[4] = {-1, 0, 0, 1};
const int delta_y[4] = {0, -1, 1, 0};
int DFS(int** matrix, int** res, int x, int y, int row, int col)
{
    int tmp = 1;
    int max = tmp;
    for(int i = 0; i < 4; ++i)
    {
        int tmp_x = x + delta_x[i];
        int tmp_y = y + delta_y[i];
        if((tmp_x >= 0) && (tmp_x < row) && (tmp_y >= 0) && (tmp_y < col) && (matrix[x][y] < matrix[tmp_x][tmp_y]))
        {
            int m;
            if(res[tmp_x][tmp_y] > 0)
            {
                m = tmp + res[tmp_x][tmp_y];
            }
            else
            {
                m = tmp + DFS(matrix, res, tmp_x, tmp_y, row, col);
            }
            max = m > max ? m : max;
        }
    }
    res[x][y] = max;
    return max;
}
int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    int max = 0;
    int** res = (int**)malloc(sizeof(int*) * matrixSize);
    for(int i = 0; i < matrixSize; ++i)
    {
        res[i] = (int*)malloc(sizeof(int) * (*matrixColSize));
        memset(res[i], 0, sizeof(int) * (*matrixColSize));
    }
    for(int i = 0; i < matrixSize; ++i)
    {
        for(int j = 0; j < *matrixColSize; ++j)
        {
            if(res[i][j] == 0)
            {
                int tmp = DFS(matrix, res, i, j, matrixSize, *matrixColSize);
                max = tmp > max ? tmp : max;
            }
        }
    }
    return max;
}