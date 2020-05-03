/*
53. 最大子序和
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例:
输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:
如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/

//function 1, 贪心
int maxSubArray(int* nums, int numsSize){  
    if((NULL == nums) || (0 == numsSize))
        return INT_MIN;
    
    int sum = 0;
    int len = nums[0];
    for(int n = 0; n < numsSize; n++)
    {
        if(sum > 0)
            sum = sum + nums[n];
        else
            sum = nums[n];
        if(sum > len)
            len = sum;
    }
    return len;
}

//function 2， 动态规划
#define max(x, y) (x > y ? x : y)
int maxSubArray(int* nums, int numsSize){  
    int res = INT_MIN;
    if(NULL == nums || 0 == numsSize)
        return res;    
    int* dp = (int*)malloc(sizeof(int) * numsSize);
    dp[0] = nums[0];
    res = nums[0];
    for(int n = 1; n < numsSize; ++n)
    {
        dp[n] = max(dp[n - 1] + nums[n], nums[n]);
        res = max(res, dp[n]);
    }
    return res;
}