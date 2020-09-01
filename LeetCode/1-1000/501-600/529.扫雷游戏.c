/*
529. 扫雷游戏
让我们一起来玩扫雷游戏！
给定一个代表游戏板的二维字符矩阵。 'M' 代表一个未挖出的地雷，'E' 代表一个未挖出的空方块，'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的已挖出的空白方块，数字（'1' 到 '8'）表示有多少地雷与这块已挖出的方块相邻，'X' 则表示一个已挖出的地雷。
现在给出在所有未挖出的方块中（'M'或者'E'）的下一个点击位置（行和列索引），根据以下规则，返回相应位置被点击后对应的面板：
如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X'。
如果一个没有相邻地雷的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的未挖出方块都应该被递归地揭露。
如果一个至少与一个地雷相邻的空方块（'E'）被挖出，修改它为数字（'1'到'8'），表示相邻地雷的数量。
如果在此次点击中，若无更多方块可被揭露，则返回面板。
 
示例 1：

输入: 

[['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'M', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E'],
 ['E', 'E', 'E', 'E', 'E']]

Click : [3,0]

输出: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]


示例 2：

输入: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'M', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

Click : [1,2]

输出: 

[['B', '1', 'E', '1', 'B'],
 ['B', '1', 'X', '1', 'B'],
 ['B', '1', '1', '1', 'B'],
 ['B', 'B', 'B', 'B', 'B']]

注意：
输入矩阵的宽和高的范围为 [1,50]。
点击的位置只能是未被挖出的方块 ('M' 或者 'E')，这也意味着面板至少包含一个可点击的方块。
输入面板不会是游戏结束的状态（即有地雷已被挖出）。
简单起见，未提及的规则在这个问题中可被忽略。例如，当游戏结束时你不需要挖出所有地雷，考虑所有你可能赢得游戏或标记方块的情况。
*/

//function 1
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//BFS
typedef struct node{
    int x;
    int y;
}Node;
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    int row = boardSize;
    int col = boardColSize[0];
    *returnSize = row;
    *returnColumnSizes = (int*)malloc(sizeof(int) * row);
    for(int i = 0; i < row; ++i)
    {
        (*returnColumnSizes)[i] = col;
    }

    //待揭露队列
    Node* queue = (Node*)malloc(sizeof(Node) * row * col);
    int tail = -1;
    int head = 0;
    queue[0].x = click[0];
    queue[0].y = click[1];

    //已访问队列, 未访问0， 已访问1
    int visited[row][col];
    memset(visited, 0, sizeof(visited));
    visited[click[0]][click[1]] = 1;

    //方向
    int delt_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int delt_y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while(tail < head)
    {
        int nx = queue[++tail].x;
        int ny = queue[tail].y;
        if(board[nx][ny] == 'M')
        {
            board[nx][ny] = 'X';
                return board;
        }
        else if(board[nx][ny] != 'E')
            continue;
        int count = 0;  //记录地雷数
        //查找周围是否有地雷
        for(int i = 0; i < 8; ++i)
        {
            int tmp_x = nx + delt_x[i];
            int tmp_y = ny + delt_y[i];
            if(tmp_x >= 0 && tmp_x < row && tmp_y >= 0 && tmp_y < col && board[tmp_x][tmp_y] == 'M')
                count++;
        }
        if(count == 0)
        {
            board[nx][ny] = 'B';
            for(int i = 0; i < 8; ++i)
            {
                int tmp_x = nx + delt_x[i];
                int tmp_y = ny + delt_y[i];
                //与其相邻的未挖出方块入队待揭露
                if(tmp_x >= 0 && tmp_x < row && tmp_y >= 0 && tmp_y < col && board[tmp_x][tmp_y] == 'E' && visited[tmp_x][tmp_y] == 0)
                {
                    queue[++head].x = tmp_x;
                    queue[head].y = tmp_y;
                    visited[tmp_x][tmp_y] = 1;
                }
            }
        }
        else
            board[nx][ny] = count + '0';
    }

    return board;
}

//funtion 2
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//DFS
//方向
int delt_x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int delt_y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
void dfs(char** board, int** visited, int x, int y, int row, int col)
{
    if(board[x][y] == 'M')
    {
        board[x][y] = 'X';
        return;
    }
    if(board[x][y] != 'E')
        return;
    int count = 0;  //记录地雷数
    //查找周围是否有地雷
    for(int i = 0; i < 8; ++i)
    {
        int tmp_x = x + delt_x[i];
        int tmp_y = y + delt_y[i];
        if(tmp_x >= 0 && tmp_x < row && tmp_y >= 0 && tmp_y < col && board[tmp_x][tmp_y] == 'M')
            count++;
    }
    if(count != 0)
    {
        board[x][y] = count + '0';
    }
    else
    {
        board[x][y] = 'B';
        for(int i = 0; i < 8; ++i)
        {
            int tmp_x = x + delt_x[i];
            int tmp_y = y + delt_y[i];
            //与其相邻的未挖出方块入队待揭露
            if(tmp_x >= 0 && tmp_x < row && tmp_y >= 0 && tmp_y < col && board[tmp_x][tmp_y] == 'E' && visited[tmp_x][tmp_y] == 0)
            {
                visited[tmp_x][tmp_y] = 1;
                dfs(board, visited, tmp_x, tmp_y, row, col);             
            }
        }
    }
}
char** updateBoard(char** board, int boardSize, int* boardColSize, int* click, int clickSize, int* returnSize, int** returnColumnSizes){
    int row = boardSize;
    int col = boardColSize[0];
    *returnSize = row;
    *returnColumnSizes = (int*)malloc(sizeof(int) * row);
    for(int i = 0; i < row; ++i)
    {
        (*returnColumnSizes)[i] = col;
    }

    //已访问队列, 未访问0， 已访问1
    int** visited = (int**)malloc(sizeof(int*) * row);
    for(int i = 0; i < row; ++i)
    {
        visited[i] = (int*)malloc(sizeof(int) * col);
        memset(visited[i], 0, sizeof(int) * col);
    }    
    visited[click[0]][click[1]] = 1;

    dfs(board, visited, click[0], click[1], row, col);
    
    return board;
}