/*
1014. 最佳观光组合
给定正整数数组 A，A[i] 表示第 i 个观光景点的评分，并且两个景点 i 和 j 之间的距离为 j - i。
一对景点（i < j）组成的观光组合的得分为（A[i] + A[j] + i - j）：景点的评分之和减去它们两者之间的距离。
返回一对观光景点能取得的最高分。
示例：
输入：[8,1,5,2,6]
输出：11
解释：i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
提示：
2 <= A.length <= 50000
1 <= A[i] <= 1000
*/
//function 1, 暴力， 超时
int maxScoreSightseeingPair(int* A, int ASize){
    int max = INT_MIN;
    for(int i = 0; i < ASize - 1; ++i)
    {
        for(int j = i + 1; j < ASize; ++j)
        {
            int sum = A[i] + A[j] + i - j;
            max = sum > max ? sum : max;
        }
    }
    return max;
}

//function 2, 优化
//求A[i] + i + A[j] - j最大
int maxScoreSightseeingPair(int* A, int ASize){
    int max = A[0] + 0;
    int res = INT_MIN;
    for(int j = 1; j < ASize; ++j)
    {
        int sum = max + A[j] - j;
        res = sum > res ? sum : res;
        max = A[j] + j > max ? A[j] + j : max;
    }
    return res;
}