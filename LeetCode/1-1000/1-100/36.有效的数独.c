/*
36. 有效的数独
请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

注意：
一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。

示例 1：
输入：board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：true

示例 2：
输入：board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：false
解释：除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。 但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。 

提示：
board.length == 9
board[i].length == 9
board[i][j] 是一位数字或者 '.'
*/

//function 1, 行，列，每 3*3 划定一个区域， 三个哈希
#define NUM 9
typedef struct hash_array
{
    int hash[10];   //0-9 hash
}Hash_array;
typedef struct hash_node
{
    Hash_array* p;
}Hash_node;
Hash_node* creat_hash_map(int num)
{
    //创建num个Hash_node型的数组，代表横，纵，3*3坐标
    Hash_node* array = (Hash_node*)malloc(sizeof(Hash_node) * num);
    for(int i = 0; i < num; ++i)    //0-8
    {
        array[i].p = (Hash_array*)malloc(sizeof(Hash_array));
        //每个array中的数组元素下挂一个数量10的整型数组，初始化为0, (hash0, 1-9)
        for(int c = 0; c < 10; ++c)     //0-9
        {
            array[i].p->hash[c] = 0;
        }
    }

    return array;
}
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    if(!board || !boardColSize || 9 != boardSize || 9 != *boardColSize)
        return false;
    Hash_node* X = creat_hash_map(NUM);     //row
    Hash_node* Y = creat_hash_map(NUM);     //column
    Hash_node* Z = creat_hash_map(NUM);     //3 * 3 区域

    for(int r = 0; r < boardSize; ++r)
    {
        for(int c = 0; c < *boardColSize; ++c)
        {
            char tmp = board[r][c];
            int tmp_i = tmp - '0';
            if(tmp == '.')
                continue;
            else if(tmp >= '1' && tmp <='9')
            {
                //数字 1-9 在每一行只能出现一次。
                if(X[r].p->hash[tmp_i] == 1)
                    return false;
                else
                    X[r].p->hash[tmp_i] = 1;

                //数字 1-9 在每一列只能出现一次。
                if(Y[c].p->hash[tmp_i] == 1)
                    return false;
                else
                    Y[c].p->hash[tmp_i] = 1;

                //数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
                int count = (r / 3) * 3 + c / 3;
                if(Z[count].p->hash[tmp_i] == 1)
                    return false;
                else
                    Z[count].p->hash[tmp_i] = 1;
            }
            else
                return false;
        }
    }
    return true;
}

//function 1，简单格式优化
#define NUM 9
typedef struct hash_array
{
    int hash[10];   //0-9 hash
}Hash_array;
typedef struct hash_node
{
    Hash_array* p;
}Hash_node;
Hash_node* creat_hash_map(int num)
{
    //创建num个Hash_node型的数组，代表横，纵，3*3坐标
    Hash_node* array = (Hash_node*)malloc(sizeof(Hash_node) * num);
    for(int i = 0; i < num; ++i)    //0-8
    {
        array[i].p = (Hash_array*)malloc(sizeof(Hash_array));
        //每个array中的数组元素下挂一个数量10的整型数组，初始化为0, (hash0, 1-9)
        for(int c = 0; c < 10; ++c)     //0-9
        {
            array[i].p->hash[c] = 0;
        }
    }

    return array;
}
bool isValidSudoku(char** board, int boardSize, int* boardColSize){
    if(!board || !boardColSize || 9 != boardSize || 9 != *boardColSize)
        return false;
    Hash_node* X = creat_hash_map(NUM);     //row
    Hash_node* Y = creat_hash_map(NUM);     //column
    Hash_node* Z = creat_hash_map(NUM);     //3 * 3 区域

    for(int r = 0; r < boardSize; ++r)
    {
        for(int c = 0; c < *boardColSize; ++c)
        {
            char tmp = board[r][c];
            int tmp_i = tmp - '0';
            if(tmp == '.')
                continue;
            else if(tmp >= '1' && tmp <='9')
            {
                int count = (r / 3) * 3 + c / 3;
                //数字 1-9 在每一行只能出现一次 || 数字 1-9 在每一列只能出现一次 || 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次
                if(X[r].p->hash[tmp_i] == 1 || Y[c].p->hash[tmp_i] == 1 || Z[count].p->hash[tmp_i] == 1)
                    return false;
                else
                {
                    X[r].p->hash[tmp_i] = 1;
                    Y[c].p->hash[tmp_i] = 1;
                    Z[count].p->hash[tmp_i] = 1;
                }   
            }
            else
                return false;
        }
    }
    return true;
}