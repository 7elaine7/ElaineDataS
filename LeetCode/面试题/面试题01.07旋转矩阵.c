/*
面试题 01.07. 旋转矩阵
给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
不占用额外内存空间能否做到？
示例 1:
给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
示例 2:
给定 matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 
原地旋转输入矩阵，使其变为:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
*/

/*
此题是用一圈一圈旋转做法
也可以用先对角线翻遮
再左右翻折的做法
*/
void rotate(int** matrix, int matrixSize, int* matrixColSize){
    int row = matrixSize;
    int col = *matrixColSize;
    int r_start = 0;
    int r_end = row - 1;
    int c_start = 0;
    int c_end = col - 1;
    for(int m = 0; m < row / 2; ++m)
    {
        for(int n = 0; n < c_end - c_start; ++n)
        {
            int tmp1,tmp2;
            //[r_start][c_start + n] -> [r_start + n][c_end]
            tmp1 = matrix[r_start + n][c_end];
            matrix[r_start + n][c_end] = matrix[r_start][c_start + n];
            //[r_start + n][c_end] -> [r_end][c_end - n]
            tmp2 = matrix[r_end][c_end - n];
            matrix[r_end][c_end - n] = tmp1;
            //[r_end][c_end - n] -> [r_end - n][c_start]
            tmp1 = matrix[r_end - n][c_start];
            matrix[r_end - n][c_start] = tmp2;
            //[r_end - n][c_start] -> [r_start][c_start + n]
            matrix[r_start][c_start + n] = tmp1;
        }
        r_start++;
        c_start++;
        r_end--;
        c_end--;
    }
}