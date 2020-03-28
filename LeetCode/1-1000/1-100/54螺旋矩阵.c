/*
54. 螺旋矩阵
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
示例 1:
输入:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
  [1, 2, 3, 4],
  [5, 6, 7, 8],
  [9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

螺旋矩阵：
***********************
                      *
*****************     * 
*               *     * 
*               *     * 
*     *****     *     *
*     *         *     *
*     ***********     *
*                     * 
***********************
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
    int *array = (int*)malloc(sizeof(int) * matrixSize * (*matrixColSize));
    int count = 0;
    int i = 0;   
    //行
    int s_m = 0; 
    int e_m = matrixSize - 1;
    //列
    int s_n = 0;
    int e_n = *matrixColSize - 1;
    while(s_m <= e_m && s_n <= e_n)
    {
        //向右
        for(i = s_n; i <= e_n; ++i)
        {
            array[count] = matrix[s_m][i];
            count++;
        }
        //向下
        for(i = s_m + 1; i <= e_m; ++i)
        {
            array[count] = matrix[i][e_n];
            count++;
        }
        //向左
        for(i = e_n - 1; (i >= s_n) && (s_m < e_m); --i)
        {
            array[count] = matrix[e_m][i];
            count++;
        }
        //向上
        for(i = e_m - 1; (i > s_m) && (s_n < e_n); --i)
        {
            array[count] = matrix[i][s_n];
            count++;
        }
        s_m++;
        e_m--;
        s_n++;
        e_n--;
    }
    * returnSize = count;
    return array;
}