/*
面试题13. 机器人的运动范围
地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。
一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），
也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。
但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？ 
示例 1：
输入：m = 2, n = 3, k = 1
输出：3
示例 1：
输入：m = 3, n = 1, k = 0
输出：1
提示：
1 <= n,m <= 100
0 <= k <= 20
*/

//function1  广度优先搜索(Breadth-First-Search)
typedef struct node{
    int r;  //横坐标
    int c;  //纵坐标
}Node;
int movingCount(int m, int n, int k){
    //存储已经访问的结点
    int* visited = (int*)malloc(sizeof(int) * m * n);
    memset(visited, 0, sizeof(int) * m * n); 
    //存储已经被访问，但是相连还没有被访问的结点
    Node* queue = (Node*)malloc(sizeof(Node) * m * n * 3);
    int head = -1;
    int tail = 0;
    int count = 0;
    queue[0].r = 0;
    queue[0].c = 0;
    while(head != tail)     //queue里面有未被处理的点
    {
        head++;
        int row = queue[head].r;
        int col = queue[head].c;
        int index = row * n + col;
        //不符合条件的点不入待判断队列queue，退出此次循环
        if(row < 0 || col < 0 || row >= m || col >= n || (row/10 + row%10 + col/10 + col%10) > k || visited[index] == 1)
            continue;

        visited[index] = 1;
        count++;
        //相连结点进入待判断queue队列
        tail++;
        queue[tail].r = row;
        queue[tail].c = col + 1;
        tail++;
        queue[tail].r = row + 1;
        queue[tail].c = col;
    }
    return count;
}

//function2  深度优先搜索(Depth-First-Search)
//dfs
int dfs(int *visited, int r, int c, int m, int n, int k)
{
    if(r < 0 || c < 0 || r >= m || c >= n || visited[r * n + c] == 1 || (r/10 + r%10 + c/10 + c%10) > k)
        return 0;
    visited[r * n + c] = 1;
    return dfs(visited, r+1, c, m, n, k) + dfs(visited, r, c+1, m, n, k) + 1;
}
int movingCount(int m, int n, int k){
    //存储经判断可以被访问的结点
    int *visited = (int*)malloc(sizeof(int) * m * n);
    memset(visited, 0, sizeof(int) * m * n);
    return dfs(visited, 0, 0, m, n, k);
}