/*
5. 最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。
示例 2：
输入: "cbbd"
输出: "bb"
*/
//动态规划
char * longestPalindrome(char * s){
    int size = strlen(s);
    if(0 == size)
        return s;
    //dp[i][j], i到j范围字符串，是回文为1，不是为0
    int dp[size][size];
    char* res = (char*)malloc(sizeof(char) * (size + 1));
    int count = 0;
    //l是子串长度-1，i是起始位置，i+l是结束位置
    for(int l = 0; l < size; ++l)
    {
        for(int i = 0; i + l < size; ++i)
        {
            int j = i + l;
            //只有一个字符为true
            if(l == 0)
            {
                dp[i][j] = 1;
            }
            //两个字符看一下是否相同
            else if(l == 1)
            {
                dp[i][j] = (s[i] == s[j]);
            }
            else
            {
                dp[i][j] = dp[i + 1][j - 1] && (s[i] == s[j]);
            }
            if(dp[i][j] && l + 1 > count)
            {
                memcpy(res, &s[i], sizeof(char) * (l + 1));
                count = l + 1;
            }
        }
    }
    res[count] = '\0';
    return res;
}