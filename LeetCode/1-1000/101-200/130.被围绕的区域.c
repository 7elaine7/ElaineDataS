/*
130. 被围绕的区域
给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
示例 1：
输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
示例 2：
输入：board = [["X"]]
输出：[["X"]]
提示：
m == board.length
n == board[i].length
1 <= m, n <= 200
board[i][j] 为 'X' 或 'O'
*/
//funtion 1, BFS
typedef struct node{
    int x;
    int y;
}Node;
void BFS(char** board, int** map, int x, int y, int row, int col)
{
    int delta_x[4] = {-1, 0, 0, 1};
    int delta_y[4] = {0, -1, 1, 0};
    Node* queue = (Node*)malloc(sizeof(Node) * row * col);
    int head = 0;
    int tail = 1;
    queue[0].x = x;
    queue[0].y = y;
    while(head < tail)
    {
        for(int i = 0; i < 4; ++i)
        {
            int tmp_x = queue[head].x + delta_x[i];
            int tmp_y = queue[head].y + delta_y[i];
            if((tmp_x >= 0) && (tmp_x < row) && (tmp_y >= 0) && (tmp_y < col) && (board[tmp_x][tmp_y] == 'O') && (map[tmp_x][tmp_y] == 0) )
            {
                queue[tail].x = tmp_x;
                queue[tail++].y = tmp_y;
                map[tmp_x][tmp_y] = 1;
            }
        }
        head++;
    }
    free(queue);
}
void solve(char** board, int boardSize, int* boardColSize){
    int** map = (int**)malloc(sizeof(int*) * boardSize);
    for(int i = 0; i < boardSize; ++i)
    {
        map[i] = (int*)malloc(sizeof(int) * (*boardColSize));
        //0代表未访问，1代表已访问
        memset(map[i], 0, sizeof(int) * (*boardColSize));
    }
    int Ax[2] = {0, boardSize - 1};
    int Ay[2] = {0, *boardColSize - 1};
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < *boardColSize; ++j)
        {
            int tmpx = Ax[i];
            if((board[tmpx][j] == 'O') && (map[tmpx][j] == 0))
            {
                map[tmpx][j] = 1;
                BFS(board, map, tmpx, j, boardSize, *boardColSize);
            }
        }
    }
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < boardSize; ++j)
        {
            int tmpy = Ay[i];
            if((board[j][tmpy] == 'O') && (map[j][tmpy] == 0))
            {
                map[j][tmpy] = 1;
                BFS(board, map, j, tmpy, boardSize, *boardColSize);
            }
        }
    }
    for(int i = 0; i < boardSize; ++i)
    {
        for(int j = 0; j < *boardColSize; ++j)
        {
            if((board[i][j] == 'O') && (map[i][j] == 0))
            {
                board[i][j] = 'X';
            }
        }
    }
}

//function 2，改进BFS
typedef struct node{
    int x;
    int y;
}Node;
void BFS(char** board, int x, int y, int row, int col)
{
    int delta_x[4] = {-1, 0, 0, 1};
    int delta_y[4] = {0, -1, 1, 0};
    Node* queue = (Node*)malloc(sizeof(Node) * row * col);
    int head = 0;
    int tail = 1;
    queue[0].x = x;
    queue[0].y = y;
    while(head < tail)
    {
        for(int i = 0; i < 4; ++i)
        {
            int tmp_x = queue[head].x + delta_x[i];
            int tmp_y = queue[head].y + delta_y[i];
            if((tmp_x >= 0) && (tmp_x < row) && (tmp_y >= 0) && (tmp_y < col) && (board[tmp_x][tmp_y] == 'O'))
            {
                queue[tail].x = tmp_x;
                queue[tail++].y = tmp_y;
                board[tmp_x][tmp_y] = 'A';
            }
        }
        head++;
    }
    free(queue);
}
void solve(char** board, int boardSize, int* boardColSize){

    int Ax[2] = {0, boardSize - 1};
    int Ay[2] = {0, *boardColSize - 1};
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < *boardColSize; ++j)
        {
            int tmpx = Ax[i];
            if(board[tmpx][j] == 'O')
            {
                board[tmpx][j] = 'A';   //标记被访问过
                BFS(board, tmpx, j, boardSize, *boardColSize);
            }
        }
    }
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < boardSize; ++j)
        {
            int tmpy = Ay[i];
            if(board[j][tmpy] == 'O')
            {
                board[j][tmpy] = 'A';
                BFS(board, j, tmpy, boardSize, *boardColSize);
            }
        }
    }
    for(int i = 0; i < boardSize; ++i)
    {
        for(int j = 0; j < *boardColSize; ++j)
        {
            if(board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
            else if(board[i][j] == 'A')
            {
                board[i][j] = 'O';
            }
        }
    }
}

//funtion 3, DFS
void DFS(char** board, int x, int y, int row, int col)
{
    int delta_x[4] = {-1, 0, 0, 1};
    int delta_y[4] = {0, -1, 1, 0};

    for(int i = 0; i < 4; ++i)
    {
        int tmp_x = x + delta_x[i];
        int tmp_y = y + delta_y[i];
        if((tmp_x >= 0) && (tmp_x < row) && (tmp_y >= 0) && (tmp_y < col) && (board[tmp_x][tmp_y] == 'O'))
        {
            board[tmp_x][tmp_y] = 'A';
            DFS(board, tmp_x, tmp_y, row, col);
        }
    }
}
void solve(char** board, int boardSize, int* boardColSize){

    int Ax[2] = {0, boardSize - 1};
    int Ay[2] = {0, *boardColSize - 1};
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < *boardColSize; ++j)
        {
            int tmpx = Ax[i];
            if(board[tmpx][j] == 'O')
            {
                board[tmpx][j] = 'A';   //标记被访问过
                DFS(board, tmpx, j, boardSize, *boardColSize);
            }
        }
    }
    for(int i = 0; i < 2; ++i)
    {
        for(int j = 0; j < boardSize; ++j)
        {
            int tmpy = Ay[i];
            if(board[j][tmpy] == 'O')
            {
                board[j][tmpy] = 'A';
                DFS(board, j, tmpy, boardSize, *boardColSize);
            }
        }
    }
    for(int i = 0; i < boardSize; ++i)
    {
        for(int j = 0; j < *boardColSize; ++j)
        {
            if(board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
            else if(board[i][j] == 'A')
            {
                board[i][j] = 'O';
            }
        }
    }
}