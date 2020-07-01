/*
120. 三角形最小路径和
给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
例如，给定三角形：
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
说明：
如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
*/
#define min(x, y) (x < y ? x : y)
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    if(!triangle || triangleSize == 0)
        return 0;
    int* dp = (int*)malloc(sizeof(int) * triangleSize);
    dp[0] = triangle[0][0];

    //p存dp[i - 1][j - 1], c存dp[i - 1][j]
    int p = 0, c;
    for(int i = 1; i < triangleSize; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            c = dp[j];
            if(j == 0)
            {
                //最左端
                dp[j] = c + triangle[i][j];
            }
            else if(j == i)
            {
                //最右端
                dp[j] = p + triangle[i][j];
            }
            else
            {
                dp[j] = min(p, c) + triangle[i][j];
            }
            p = c;
        }
    }
    int res = INT_MAX;
    //dp最后一行记录最小值
    for(int i = 0; i < triangleSize; ++i)
    {
        res = min(res, dp[i]);
    }
    return res;
}