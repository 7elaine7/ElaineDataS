/*
97. 交错字符串
给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
示例 1:
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
输出: true
示例 2:
输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
输出: false
*/
//function 1, 动态规划
bool isInterleave(char * s1, char * s2, char * s3){
    int size1 = strlen(s1), size2 = strlen(s2), size3 = strlen(s3);
    if(size1 + size2 != size3)
        return false;
    //dp[i][j]表示s1的前i个与s2的前j个能否组成s3的前i+j个
    int dp[size1 + 1][size2 + 1];
    memset(dp, 0, sizeof(dp));
    for(int i = 0; i <= size1; ++i)
    {
        for(int j = 0; j <= size2; ++j)
        {
            if(i == 0 && j == 0)
                dp[i][j] = 1;
            else if(i == 0)
            {
                if(dp[i][j - 1] == 1 && s2[j - 1] == s3[j - 1])
                    dp[i][j] = 1;
            }
            else if(j == 0)
            {
                if(dp[i - 1][j] == 1 && s1[i - 1] == s3[i - 1])
                    dp[i][j] = 1;
            }
            else
            {
                if((dp[i - 1][j] == 1 && s1[i - 1] == s3[i + j - 1]) || (dp[i][j - 1] == 1 && s2[j - 1] == s3[i + j - 1]))
                    dp[i][j] = 1;
            }
        }
    }
    return dp[size1][size2];
}

//function 2，优化dp
bool isInterleave(char * s1, char * s2, char * s3){
    int size1 = strlen(s1), size2 = strlen(s2), size3 = strlen(s3);
    if(size1 + size2 != size3)
        return false;
    //dp[i][j]表示s1的前i个与s2的前j个能否组成s3的前i+j个
    int dp[size1 + 1][size2 + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 0; i <= size1; ++i)
    {
        for(int j = 0; j <= size2; ++j)
        {
            if(j > 0)
                dp[i][j] |= dp[i][j - 1] == 1 && s2[j - 1] == s3[j + i - 1];
            if(i > 0)
                dp[i][j] |= dp[i - 1][j] == 1 && s1[i - 1] == s3[i + j - 1];
        }
    }
    return dp[size1][size2];
}