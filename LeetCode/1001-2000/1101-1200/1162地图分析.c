/*
1162. 地图分析
你现在手里有一份大小为 N x N 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。
其中 0 代表海洋，1 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
如果我们的地图上只有陆地或者海洋，请返回 -1。
示例 1：
    1  0  1
    0  0  0
    1  0  1
输入：[[1,0,1],[0,0,0],[1,0,1]]
输出：2
解释： 
海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
示例 2：
    1  0  0
    0  0  0
    0  0  0
输入：[[1,0,0],[0,0,0],[0,0,0]]
输出：4
解释： 
海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
提示：
1 <= grid.length == grid[0].length <= 100
grid[i][j] 不是 0 就是 1
*/

#define MAX(a, b)   (a > b) ? a : b

typedef struct node
{
    int x;          //横坐标
    int y;          //纵坐标
    int level;      //层数
}Node;

int maxDistance(int** grid, int gridSize, int* gridColSize){
    int row = gridSize;
    int column = *gridColSize;
    if(row != column)
        return -1;
    //建造当前结点访问过但是相邻节点还没有访问的队列
    Node* queue = (Node*)malloc(sizeof(Node) * row * column);
    if(NULL == queue)
        return -1;
    memset(queue, 0, sizeof(Node) * row * column);
    int head = 0;
    int tail = 0;
    int max = 0;
    //将所有的陆地入队 level为0
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < column; ++j)
        {
            if(1 == grid[i][j])
            {
                queue[tail].x = i;
                queue[tail].y = j;
                queue[tail++].level = 0;    //先赋值tail，之后再+1
            }
        }
    }

    //全是陆地或者海洋
    if(0 == tail || (row * column) == tail)
        return -1;

    int x[4] = {-1, 0, 1, 0};   //行坐标向上，向右，向下，向左
    int y[4] = {0, 1, 0, -1};   //列坐标向上，向右，向下，向左

    while(head < tail)
    {
        max = MAX(max, queue[head].level);

        for(int c = 0; c < 4; ++c)
        {
            int gx = queue[head].x + x[c];
            int gy = queue[head].y + y[c];
            //向左向右扩散一层，遇到1就跳过，否则将此点加入队列，此点设置成1，标为已访问过
            if(gx < 0 || gx >= row || gy < 0 || gy >= column || 1 == grid[gx][gy])
                continue;
            else
            {
                queue[tail].x = gx;
                queue[tail].y = gy;
                queue[tail++].level = queue[head].level + 1;
                grid[gx][gy] = 1;
            }    
        } 
        head++;     
    }
    return max;
}