/*
59. 螺旋矩阵 II
给定一个正整数 n，生成一个包含 1 到 n2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
示例:
输入: 3
输出:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int** array = (int**)malloc(sizeof(int*) * n);
    *returnColumnSizes = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; ++i)
    {
        array[i] = (int*)malloc(sizeof(int) * n);
        *(*returnColumnSizes+i)=n;
    }
    int s_row = 0;
    int e_row = n - 1;
    int s_col = 0;
    int e_col = n - 1;
    int i;
    int count = 1;
    while(s_row <= e_row && s_col <= e_col)
    {
        //向右
        for(i = s_col; i <= e_col; ++i)
        {
            array[s_row][i] = count;
            count++;
        }
        //向下
        for(i = s_row + 1; i <= e_row; ++i)
        {
            array[i][e_col] = count;
            count++;
        }
        //向左
        for(i = e_col - 1; (i >= s_col) && (s_row < e_row); --i)
        {
            array[e_row][i] = count;
            count++;
        }
        //向上
        for(i = e_row - 1; (i > s_row) && (s_col < e_col); --i)
        {
            array[i][s_col] = count;
            count++;
        }
        s_row++;
        e_row--;
        s_col++;
        e_col--;
    }
    * returnSize = n;
    return array;
}