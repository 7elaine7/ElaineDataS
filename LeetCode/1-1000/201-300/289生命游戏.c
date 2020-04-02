/*
function 1, 将每个要改变的点坐标以及要改变的值存入状态数组
*/
//需要改变的点，结构体存状态
typedef struct node{
    int index_row;  //需要改变值的行坐标
    int index_col;  //需要改变值的列坐标
    int value;      //需要变成的新值
}NODE;
void gameOfLife(int** board, int boardSize, int* boardColSize){
    if(NULL == board || 0 == boardSize || NULL == boardColSize)
        return;
    int colSize = *boardColSize;
    NODE* node = (NODE*)malloc(sizeof(NODE) * boardSize * colSize);
    int count = 0;
    //当前点的八个方向
    int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i = 0; i < boardSize; ++i)
    {
        for(int j = 0; j < colSize; ++j)
        {
            int num = 0; 
            int live = 0;   //周围活细胞计数
            while(num < 8)
            {
                int tmp_x = i + x[num];
                int tmp_y = j + y[num];
                if(tmp_x >= 0 && tmp_x < boardSize && tmp_y >= 0 && tmp_y < colSize)
                {
                    if(1 == board[tmp_x][tmp_y])
                        live++;
                }
                num++;
            }
            if(0 == board[i][j])
            {
                //如果死细胞周围正好有三个活细胞，则该位置死细胞复活
                if(3 == live)
                {
                    node[count].index_row = i;
                    node[count].index_col = j;
                    node[count].value = 1;
                    count++;
                }
            }
            else if(1 == board[i][j])
            {
                //如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡
                //如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活
                //如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡
                if(live < 2)
                {
                    node[count].index_row = i;
                    node[count].index_col = j;
                    node[count].value = 0;
                    count++;
                }
                else if(live > 3)
                {
                    node[count].index_row = i;
                    node[count].index_col = j;
                    node[count].value = 0;
                    count++;
                }           
            }
        }
    }
    for(int i = 0; i < count; ++i)
    {
        board[node[i].index_row][node[i].index_col] = node[i].value;
    }
}
/*
function 2, 用-1代表从死变到活0-1，-2代表从活变到死1-0
*/

/*
执行用时 : 0 ms, 在所有 C 提交中击败了100.00%的用户
内存消耗 : 5.7 MB, 在所有 C 提交中击败了100.00%的用户
*/
void gameOfLife(int** board, int boardSize, int* boardColSize){
    if(NULL == board || 0 == boardSize || NULL == boardColSize)
        return;
    int colSize = *boardColSize;
    //当前点的八个方向
    int x[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int y[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for(int i = 0; i < boardSize; ++i)
    {
        for(int j = 0; j < colSize; ++j)
        {
            int num = 0; 
            int live = 0;   //周围活细胞计数
            while(num < 8)
            {
                int tmp_x = i + x[num];
                int tmp_y = j + y[num];
                if(tmp_x >= 0 && tmp_x < boardSize && tmp_y >= 0 && tmp_y < colSize)
                {
                    if(1 == board[tmp_x][tmp_y] || -2 == board[tmp_x][tmp_y])
                        live++;
                }
                num++;
            }
            //-1代表从死变到活0-1，-2代表从活变到死1-0
            if(0 == board[i][j])
            {
                //如果死细胞周围正好有三个活细胞，则该位置死细胞复活
                if(3 == live)
                {
                    board[i][j] = -1;
                }
            }
            else if(1 == board[i][j])
            {
                //如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡
                //如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活
                //如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡
                if(live < 2)
                {
                    board[i][j] = -2;
                }
                else if(live > 3)
                {
                    board[i][j] = -2;
                }           
            }
        }
    }
    for(int i = 0; i < boardSize; ++i)
    {
        for(int j = 0; j < colSize; ++j)
        {
            if(-1 == board[i][j])
                board[i][j] = 1;
            else if(-2 == board[i][j])
                board[i][j] = 0;
        }
    }
}