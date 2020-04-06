/*
72. 编辑距离
给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符
示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')
示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
*/
int get_min(int a, int b, int c)
{
    int min = (a < b) ? a : b;
    min = (min < c) ? min : c;
    return min;
}
int minDistance(char * word1, char * word2){
    int m = strlen(word1);
    int n = strlen(word2);
    int dp[m+1][n+1];   //表示word1的前m个字母转换为word2的前n个字母所需要的最少操作

    for(int i = 0; i <= m; ++i)
    {
        dp[i][0] = i;
    }
    for(int i = 0; i <= n; ++i)
    {
        dp[0][i] = i;
    }
    //dp[i-1][j-1]      word1的前i-1和word2的前j-1相同 剩下一个替换操作
    //dp[i][j-1]        word1的前i和word2的前j-1相同 剩下一个插入操作
    //dp[i-1][j]        word1的前i-1和word2的前j相同 剩下一个删除操作
    for(int i = 1; i <= m; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(word1[i-1] == word2[j-1])    //第i个和第j个字母相同
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = get_min(dp[i-1][j-1], dp[i][j-1], dp[i-1][j]) + 1;
            }
        }
    }
    return dp[m][n];
}