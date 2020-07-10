/*
309. 最佳买卖股票时机含冷冻期
给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
示例:
输入: [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]
*/
/*
f[i]表示第i天结束之后的累计最大收益
f[i][0]：手上持有股票的最大收益
f[i][1]：手上不持有股票，i天结束后处于冷冻期的最大收益
f[i][2]：手上不持有股票，i天结束后不处于冷冻期的最大收益
*/
#define max(x, y) (x > y ? x : y)
int maxProfit(int* prices, int pricesSize){
    if(!prices || pricesSize == 0)
        return 0;
    int dp[pricesSize][3];
    dp[0][0] = -prices[0];  //第0天买了股票
    dp[0][1] = 0;
    dp[0][2] = 0;
    for(int i = 1; i < pricesSize; ++i)
    {
        //第i-1天已经买了股票，第i天什么都没做持有股票；股票是第i天买的
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
        //第i天一定是把股票卖了
        dp[i][1] = dp[i - 1][0] + prices[i];
        //第i-1天一定是不持有股票的
        dp[i][2] = max(dp[i - 1][1], dp[i - 1][2]);
    }
    //最后一天一定是不持有股票才有意义
    return max(dp[pricesSize - 1][1], dp[pricesSize - 1][2]);
}