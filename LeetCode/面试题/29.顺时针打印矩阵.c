/*
面试题29. 顺时针打印矩阵
输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。
示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]
示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
限制：
0 <= matrix.length <= 100
0 <= matrix[i].length <= 100
注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize){
    if(NULL == matrix || 0 == matrixSize || 0 == *matrixColSize)
    {
        *returnSize = 0;
        return NULL;
    }
    int row = matrixSize;
    int col = *matrixColSize;
    int size = row * col;
    *returnSize = size;
    int* res = (int*)malloc(sizeof(int) * size);
    int count = 0;
    for(int i = 0; count < size; ++i)
    {
        //向右
        for(int s_c = i; s_c < col - i; ++s_c)
        {
            res[count++] = matrix[i][s_c];
        }
        //向下
        for(int s_r = i + 1; s_r < row - i && col - i - 1 >= 0; ++s_r)
        {
            res[count++] = matrix[s_r][col - i - 1];
        }
        //向左
        for(int s_c = col - i - 2; s_c >= i && row - i - 1 > i; --s_c)
        {
            res[count++] = matrix[row - i - 1][s_c];
        }
        //向上
        for(int s_r = row - i - 2; s_r >= i + 1 && i < col - i - 1; --s_r)
        {
            res[count++] = matrix[s_r][i];
        }
    }
    return res;
}
