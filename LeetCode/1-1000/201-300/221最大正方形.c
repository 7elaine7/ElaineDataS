/*
221. 最大正方形
在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
示例:
输入: 
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
输出: 4
*/
#define min(x, y) (x > y ? y : x)
int maximalSquare(char** matrix, int matrixSize, int* matrixColSize){
    if(0 == matrixSize)
        return 0;
    int max = matrix[0][0];
    for(int i = 0; i < matrixSize; ++i)
    {
        for(int j = 0; j < *matrixColSize; ++j)
        {
            if(matrix[i][j] == '1' && i > 0 && j > 0)
            {
                matrix[i][j] = min(matrix[i - 1][j], matrix[i][j - 1]);
                matrix[i][j] = min(matrix[i - 1][j - 1], matrix[i][j]) + 1;
            }
            if(matrix[i][j] > max)
                max = matrix[i][j];
        }
    }
    return (max - '0') * (max - '0');
}