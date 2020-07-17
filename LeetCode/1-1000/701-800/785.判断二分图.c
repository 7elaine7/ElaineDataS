/*
785. 判断二分图
给定一个无向图graph，当这个图为二分图时返回true。
如果我们能将一个图的节点集合分割成两个独立的子集A和B，并使图中的每一条边的两个节点一个来自A集合，一个来自B集合，我们就将这个图称为二分图。
graph将会以邻接表方式给出，graph[i]表示图中与节点i相连的所有节点。每个节点都是一个在0到graph.length-1之间的整数。这图中没有自环和平行边： graph[i] 中不存在i，并且graph[i]中没有重复的值。

示例 1:
输入: [[1,3], [0,2], [1,3], [0,2]]
输出: true
解释: 
无向图如下:
0----1
|    |
|    |
3----2
我们可以将节点分成两组: {0, 2} 和 {1, 3}。

示例 2:
输入: [[1,2,3], [0,2], [0,1,3], [0,2]]
输出: false
解释: 
无向图如下:
0----1
| \  |
|  \ |
3----2
我们不能将节点分割成两个独立的子集。
注意:
graph 的长度范围为 [1, 100]。
graph[i] 中的元素的范围为 [0, graph.length - 1]。
graph[i] 不会包含 i 或者有重复的值。
图是无向的: 如果j 在 graph[i]里边, 那么 i 也会在 graph[j]里边。
*/

//function 1, BFS
bool isBipartite(int** graph, int graphSize, int* graphColSize){
    //0代表初始值，1代表A，2代表B
    int* visited = (int*)malloc(sizeof(int) * graphSize);
    memset(visited, 0, sizeof(int) * graphSize);

    int* queue = (int*)malloc(sizeof(int) * graphSize);
    for(int i = 0; i < graphSize; ++i)
    {
        if(visited[i] == 0)
        {
            int head = 0, tail = -1;
            queue[head] = i;
            visited[i] = 1;
            while(tail < head)
            {
                int node = queue[++tail];
                int color = visited[node] == 1 ? 2 : 1;
                for(int j = 0; j < graphColSize[node]; ++j)
                {
                    int tmp = graph[node][j];
                    if(visited[tmp] == 0)
                    {
                        queue[++head] = tmp;
                        visited[tmp] = color;
                    }
                    else if(visited[tmp] != color)
                        return false;
                }
                
            }
        }
    }
    return true;
}

//function 2, DFS
bool DFS(int** graph, int* visited, int node, int* graphColSize)
{
    if(visited[node] == 0)
        visited[node] = 1;
    for(int i = 0; i < graphColSize[node]; ++i)
    {
        int color = (visited[node] == 1 ? 2 : 1);
        int tmp = graph[node][i];
        if(visited[tmp] == 0)
        {
            visited[tmp] = color;
            if(!DFS(graph, visited, tmp, graphColSize))
                return false;
        }
        else if(visited[tmp] != color)
            return false;
    }
    return true;
}
bool isBipartite(int** graph, int graphSize, int* graphColSize){
    //0代表初始值，1代表A，2代表B
    int* visited = (int*)malloc(sizeof(int) * graphSize);
    memset(visited, 0, sizeof(int) * graphSize);

    for(int i = 0; i < graphSize; ++i)
    {
        if(!DFS(graph, visited, i, graphColSize))
            return false;       
    }
    return true;
}

//function 3, 优化DFS
bool DFS(int** graph, int* visited, int node, int* graphColSize)
{
    int color = (visited[node] == 1 ? 2 : 1);
    for(int i = 0; i < graphColSize[node]; ++i)
    {        
        int tmp = graph[node][i];
        if(visited[tmp] == 0)
        {
            visited[tmp] = color;
            if(!DFS(graph, visited, tmp, graphColSize))
                return false;
        }
        else if(visited[tmp] != color)
            return false;
    }
    return true;
}
bool isBipartite(int** graph, int graphSize, int* graphColSize){
    //0代表初始值，1代表A，2代表B
    int* visited = (int*)malloc(sizeof(int) * graphSize);
    memset(visited, 0, sizeof(int) * graphSize);

    for(int i = 0; i < graphSize; ++i)
    {
        if(visited[i] == 0)
        {
            visited[i] = 1;
            if(!DFS(graph, visited, i, graphColSize))
                return false;   
        }    
    }
    return true;
}