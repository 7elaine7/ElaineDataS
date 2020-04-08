/*
面试题 08.10. 颜色填充
颜色填充。编写函数，实现许多图片编辑软件都支持的“颜色填充”功能。
给定一个屏幕（以二维数组表示，元素为颜色值）、一个点和一个新的颜色值，将新颜色值填入这个点的周围区域，直到原来的颜色值全都改变。
示例1:
 输入：
image = [[1,1,1],[1,1,0],[1,0,1]] 
sr = 1, sc = 1, newColor = 2
 输出：[[2,2,2],[2,2,0],[2,0,1]]
 解释: 
在图像的正中间，(坐标(sr,sc)=(1,1)),
在路径上所有符合条件的像素点的颜色都被更改成2。
注意，右下角的像素没有更改为2，
因为它不是在上下左右四个方向上与初始点相连的像素点。
说明：
image 和 image[0] 的长度在范围 [1, 50] 内。
给出的初始点将满足 0 <= sr < image.length 和 0 <= sc < image[0].length。
image[i][j] 和 newColor 表示的颜色值在范围 [0, 65535]内。
*/

//function1  广度优先搜索(Breadth-First-Search)
typedef struct node{
    int r;
    int c;
}Node;
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    *returnSize = imageSize;
    int row = imageSize;
    int col = *imageColSize;
    int tmp = image[sr][sc];
    Node* queue = (Node*)malloc(sizeof(Node) * row * col * 5);
    int visited[row][col];
    int head = -1;
    int tail = 0;
    queue[tail].r = sr;
    queue[tail].c = sc;
    while(head != tail)
    {
        head++;
        int tmp_r = queue[head].r;
        int tmp_c = queue[head].c;
        if(tmp_r < 0 || tmp_r == row || tmp_c < 0 || tmp_c == col || visited[tmp_r][tmp_c] == 1 || image[tmp_r][tmp_c] != tmp)
            continue;
        image[tmp_r][tmp_c] = newColor;
        visited[tmp_r][tmp_c] = 1;
        //上
        tail++;
        queue[tail].r = tmp_r - 1;
        queue[tail].c = tmp_c;
        //下
        tail++;
        queue[tail].r = tmp_r + 1;
        queue[tail].c = tmp_c;
        //左
        tail++;
        queue[tail].r = tmp_r;
        queue[tail].c = tmp_c - 1;
        //右
        tail++;
        queue[tail].r = tmp_r;
        queue[tail].c = tmp_c + 1;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = *imageColSize;
    }

    return image;
}

//function2  深度优先搜索(Depth-First-Search)

void dfs(int** image, int row, int col, int sr, int sc, int newColor, int oldColor)
{
    if(sr < 0 || sc < 0 || sr == row || sc == col || image[sr][sc] != oldColor)
        return;
    image[sr][sc] = newColor;
    int tmp[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
    for(int i = 0; i < 4; ++i)
    {
        dfs(image, row, col, sr + tmp[i][0], sc + tmp[i][1], newColor, oldColor);
    }
    return;
}
int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int newColor, int* returnSize, int** returnColumnSizes){
    *returnSize = imageSize;
    int row = imageSize;
    int col = *imageColSize;
    int oldColor = image[sr][sc];
    if(oldColor == newColor)
        return image;    
    dfs(image, row, col, sr, sc, newColor, oldColor);
    *returnColumnSizes = (int*)malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = *imageColSize;
    }

    return image;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */