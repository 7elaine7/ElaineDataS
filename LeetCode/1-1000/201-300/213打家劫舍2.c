/*
213. 打家劫舍 II
你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
示例 1:
输入: [2,3,2]
输出: 3
解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
示例 2:
输入: [1,2,3,1]
输出: 4
解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。
*/

/*
动态规划：偷了头不能偷尾，偷了尾不能偷头
dp(i) = max(dp(i - 1), dp(i - 2) + nums[i])
求两次，第一次从nums[0]...nums[size - 2]，第二次从nums[1]...nums[size - 1]
*/
#define MAX(a, b) ((a > b) ? a : b)
int dp(int* nums, int start, int end)
{
    int n1; //到n-1为止的最大值
    int n2; //到n-2为止的最大值
    n1 = n2 = 0;
    for(int i = start; i <= end; ++i)
    {
        int tmp = n2;
        n2 = n1;
        n1 = MAX(tmp+nums[i], n1);
    }
    return n1;
}
int rob(int* nums, int numsSize){
    if(1 == numsSize)
        return nums[0];
    int result1 = dp(nums, 0, numsSize - 2);
    int result2 = dp(nums, 1, numsSize - 1);
    
    return MAX(result1, result2);
}
