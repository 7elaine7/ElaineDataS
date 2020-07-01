/*
718. 最长重复子数组
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
示例 1:
输入:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出: 3
解释: 
长度最长的公共子数组是 [3, 2, 1]。
说明:
1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100
*/
//function 1, 暴力解法，超时
int findLength(int* A, int ASize, int* B, int BSize){
    int max = 0;
    for(int i = 0; i < ASize; ++i)
    {
        for(int j = 0; j < BSize; ++j)
        {
            int delt = 0;
            while(i + delt < ASize && j + delt < BSize && A[i + delt] == B[j + delt])
            {
                ++delt;
            }
            max = delt > max ? delt : max;
        }
    }
    return max;
}
//funtion 2，动态规划
/*
dp[i][j]：长度为i，以A[i-1]为末尾的序列，和长度为j，以B[j-1]为末尾的序列，二者的最大公共后缀序列长度（该公共序列以A[i-1]B[j-1]为末尾项）
如果 A[i-1] != B[j-1] ， dp[i][j] = 0
如果 A[i-1] == B[j-1] ， dp[i][j] = dp[i-1][j-1] + 1

*/
int findLength(int* A, int ASize, int* B, int BSize){
    int dp[ASize + 1][BSize + 1];
    memset(dp, 0, sizeof(dp));
    int max = 0;
    for(int i = 1; i <= ASize; ++i)
    {
        for(int j = 1; j <= BSize; ++j)
        {
            if(A[i - 1] == B[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }               
            else
            {
                dp[i][j] = 0;
            }
            max = dp[i][j] > max ? dp[i][j] : max;
        }
    }
    return max;
}

//function 3，滑窗
#define min(x, y) (x < y ? x : y)
int max_len(int* A, int* B, int a, int b, int len)
{
    int count = 0;
    int n = 0;
    for(int i = 0; i < len; ++i)
    {
        if(A[a + i] == B[b + i])
            n++;
        else
            n = 0;
        count = n > count ? n : count;
    }
    return count;
}
int findLength(int* A, int ASize, int* B, int BSize){
    int max = 0;
    for(int i = 0; i < ASize; ++i)
    {
        int len = min(ASize - i, BSize);
        int maxlen = max_len(A, B, i, 0, len);
        max = maxlen > max ? maxlen : max;
    }
    for(int i = 0; i < BSize; ++i)
    {
        int len = min(BSize - i, ASize);
        int maxlen = max_len(A, B, 0, i, len);
        max = maxlen > max ? maxlen : max;
    }
    return max;
}