/*
**************************************************************
    Author：Elsun
    Date：2025-12-23
    Note: Leetcode Q3
**************************************************************
Q3. 最大连续 1 的个数
给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。
示例 1：
输入：nums = [1,1,0,1,1,1]
输出：3
解释：开头的两位和最后的三位都是连续 1 ，所以最大连续 1 的个数是 3.
示例 2:
输入：nums = [1,0,1,1,0,1]
输出：2
提示：
1 <= nums.length <= 105
nums[i] 不是 0 就是 1
*/
//function 1，复杂了
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    if(numsSize == 1)
        return nums[0];
    int left = 0, right = 1;
    int count = 0;
    for(; right < numsSize; right++)
    {
        if((nums[right] == 0) && (nums[right - 1] == 1))
        {
            count = (right - left) > count ? (right - left) : count;
        }
        if(nums[right] != 1)
            continue;
        if((nums[right] == 1) && (nums[right - 1] == 0))
            left = right;
    }
    if(nums[numsSize - 1] == 1)
        return count = (right - left) > count ? (right - left) : count;
    
    return count;
}
//function 2, 简单的
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int count = 0;
    int max = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == 1)
            count++;
        else
        {
            max = count > max ? count : max;
            count = 0; 
        }
    }
    return count > max ? count : max;
}