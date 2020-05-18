/*
152. 乘积最大子数组
给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。
示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
*/

//function 1，暴力解法, 非常慢
int maxProduct(int* nums, int numsSize){
    int max = nums[0];
    for(int i = 0; i < numsSize; ++i)
    {
        int sum = 1;
        for(int j = i; j < numsSize; ++j)
        {
            sum = sum * nums[j];
            max = sum > max ? sum : max;
        }
    }
    return max;
}

//动态规划
//以i位置元素作为组合中的最末端元素，求最优解
#define max(x, y) (x > y ? x : y)
#define min(x, y) (x < y ? x : y)
int maxProduct(int* nums, int numsSize){
    int premax = nums[0];
    int premin = nums[0];
    int res = nums[0];
    for(int i = 1; i < numsSize; ++i)
    {
        int tmpmax = premax;
        int tmpmin = premin;
        premax = max(tmpmax * nums[i], max(tmpmin * nums[i], nums[i]));
        premin = min(tmpmax * nums[i], min(tmpmin * nums[i], nums[i]));
        res = max(premax, res);
    }               
    return res;
}