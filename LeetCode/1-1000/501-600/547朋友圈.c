/*
547. 朋友圈
班上有 N 名学生。其中有些人是朋友，有些则不是。他们的友谊具有是传递性。
如果已知 A 是 B 的朋友，B 是 C 的朋友，那么我们可以认为 A 也是 C 的朋友。
所谓的朋友圈，是指所有朋友的集合。
给定一个 N * N 的矩阵 M，表示班级中学生之间的朋友关系。
如果M[i][j] = 1，表示已知第 i 个和 j 个学生互为朋友关系，否则为不知道。
你必须输出所有学生中的已知的朋友圈总数。
示例 1:
输入: 
[[1,1,0],
 [1,1,0],
 [0,0,1]]
输出: 2 
说明：已知学生0和学生1互为朋友，他们在一个朋友圈。
第2个学生自己在一个朋友圈。所以返回2。
示例 2:
输入: 
[[1,1,0],
 [1,1,1],
 [0,1,1]]
输出: 1
说明：已知学生0和学生1互为朋友，学生1和学生2互为朋友，所以学生0和学生2也是朋友，所以他们三个在一个朋友圈，返回1。
注意：
N 在[1,200]的范围内。
对于所有学生，有M[i][i] = 1。
如果有M[i][j] = 1，则有M[j][i] = 1。
*/
//function 1, 暴力解法，非常慢，内存消耗大
typedef struct node
{
    int x;
    int y;
}Node;
void bfs(int** M, int row, int col, int x, int y)
{
    Node* queue = (Node*)malloc(sizeof(Node) * row * col);
    int head = 0;
    int tail = 0;
    M[x][y] = 0;
    queue[tail].x = x;
    queue[tail++].y = y;

    while(head < tail)
    {
        int tmp_x = queue[head].x;
        int tmp_y = queue[head].y;
        for(int i = 0; i < row; ++i)
        {
            if(tmp_x >= 0 && tmp_x < col && M[i][tmp_x] == 1)
            {
                M[i][tmp_x] = 0;
                queue[tail].x = i;
                queue[tail++].y = tmp_x;
            }
            if(tmp_y >= 0 && tmp_y < col && M[i][tmp_y] == 1)
            {
                M[i][tmp_y] = 0;
                queue[tail].x = i;
                queue[tail++].y = tmp_y;
            }
        }
        for(int i = 0; i < col; ++i)
        {
            if(tmp_x >= 0 && tmp_x < row && M[tmp_x][i] == 1)
            {
                M[tmp_x][i] = 0;
                queue[tail].x = tmp_x;
                queue[tail++].y = i;
            }
            if(tmp_y >= 0 && tmp_y < row && M[tmp_y][i] == 1)
            {
                M[tmp_y][i] = 0;
                queue[tail].x = tmp_y;
                queue[tail++].y = i;
            }
        }
        head++;
    }
}
int findCircleNum(int** M, int MSize, int* MColSize){
    int count = 0;
    for(int i = 0; i < MSize; ++i)
    {
        for(int j = 0; j < *MColSize; ++j)
        {
            if(M[i][j] == 1)
            {
                bfs(M, MSize, *MColSize, i, j);
                count++;
            }
        }
    }
    return count;
}

//function 2, 无向图，扁平化dfs
//实际上，横纵坐标可化为一维处理，因为必然有 M[i][j] == M[j][i]
void dfs(int** M, int MSize, int* visited, int i)
{
    for(int j = 0; j < MSize; ++j)
    {
        if(M[i][j] == 1 && visited[j] == 0)
        {
            visited[j] = 1;
            dfs(M, MSize, visited, j);
        }
    }
}
int findCircleNum(int** M, int MSize, int* MColSize){
    //扁平化，无向图
    int* visited = (int*)malloc(sizeof(int) * MSize);
    memset(visited, 0, sizeof(int) * MSize);
    int count = 0;
    for(int i = 0; i < MSize; ++i)
    {
        //所有的M[i][i]必然是1
        //将所有与M[i][i]相联通的点全部找出来，设置为已访问
        if(visited[i] == 0)
        {
            dfs(M, MSize, visited, i);
            count++;
        }
    }
    return count;
}

//function 3, 无向图，扁平化bfs
//实际上，横纵坐标可化为一维处理，因为必然有 M[i][j] == M[j][i]
void bfs(int** M, int MSize, int* visited, int i)
{
    int* queue = (int*)malloc(sizeof(int) * MSize * MSize);
    int head = 0;
    int tail = 0;

    queue[tail++] = i;
    while(head < tail)
    {
        visited[queue[head]] = 1;
        for(int j = 0; j < MSize; ++j)
        {
            if(M[queue[head]][j] == 1 && visited[j] == 0)
            {
                queue[tail++] = j;
            }
        }
        head++;
    }
}
int findCircleNum(int** M, int MSize, int* MColSize){
    //扁平化，无向图
    int* visited = (int*)malloc(sizeof(int) * MSize);
    memset(visited, 0, sizeof(int) * MSize);

    int count = 0;
    for(int i = 0; i < MSize; ++i)
    {
        //所有的M[i][i]必然是1
        //将所有与M[i][i]相联通的点全部找出来，设置为已访问
        if(visited[i] == 0)
        {
            bfs(M, MSize, visited, i);
            count++;
        }
    }
    return count;
}

//function 4, 改进bfs
int findCircleNum(int** M, int MSize, int* MColSize){
    //扁平化，无向图
    int* visited = (int*)malloc(sizeof(int) * MSize);
    memset(visited, 0, sizeof(int) * MSize);
    int* queue = (int*)malloc(sizeof(int) * MSize * MSize);
    int head = 0;
    int tail = 0;

    int count = 0;
    for(int i = 0; i < MSize; ++i)
    {
        //所有的M[i][i]必然是1
        //将所有与M[i][i]相联通的点全部找出来，设置为已访问
        if(visited[i] == 0)
        {
            queue[tail++] = i;
            while(head < tail)
            {
                visited[queue[head]] = 1;
                for(int j = 0; j < MSize; ++j)
                {
                    if(M[queue[head]][j] == 1 && visited[j] == 0)
                    {
                        queue[tail++] = j;
                    }
                }
                head++;
            }
            head = 0;
            tail = 0;
            count++;
        }
    }
    return count;
}

//function 5, 使用并查集
int find(int x, int* parent)
{
    //查找x所在树的根结点
    while(parent[x] != x)
    {
        //压缩树的层树
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void make_connect(int p, int q, int* parent, int* size, int* count)
{
    int rootp = find(p, parent);
    int rootq = find(q, parent);
    if(rootp == rootq)
        return;
    //调整平衡，比较小的树挂到比较大的树下面
    if(size[rootp] < size[rootq])
    {
        parent[rootp] = rootq;
        size[rootq] += size[rootp];
    }
    else
    {
        parent[rootq] = rootp;
        size[rootp] += size[rootq];
    }
    (*count)--;
}
int findCircleNum(int** M, int MSize, int* MColSize){
    //初始化每个点的parent都是自己
    int* parent = (int*)malloc(sizeof(int) * MSize);
    //存储每个树的重量
    int* size = (int*)malloc(sizeof(int) * MSize);
    int count = MSize;
    for(int i = 0; i < MSize; ++i)
    {
        parent[i] = i;
        size[i] = 1;
    }
    for(int i = 0; i < MSize; ++i)
    {
        for(int j = 0; j < *MColSize; ++j)
        {
            if(M[i][j] == 1)
            {
                make_connect(i, j, parent, size, &count);
            }
        }
    }
    return count;
}
