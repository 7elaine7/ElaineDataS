/*
**************************************************************
    Author：Elsun
    Date：2025-12-19
    Note: Leetcode 268
**************************************************************
268. 丢失的数字
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。
示例 1：
输入：nums = [3,0,1]
输出：2
解释：n = 3，因为有 3 个数字，所以所有的数字都在范围 [0,3] 内。2 是丢失的数字，因为它没有出现在 nums 中。
示例 2：
输入：nums = [0,1]
输出：2
解释：n = 2，因为有 2 个数字，所以所有的数字都在范围 [0,2] 内。2 是丢失的数字，因为它没有出现在 nums 中。
示例 3：
输入：nums = [9,6,4,2,3,5,7,0,1]
输出：8
解释：n = 9，因为有 9 个数字，所以所有的数字都在范围 [0,9] 内。8 是丢失的数字，因为它没有出现在 nums 中。
提示：
n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
nums 中的所有数字都 独一无二
进阶：你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?
*/
//function 1:快排
int missingNumber(int* nums, int numsSize) {
    if(numsSize == 1)
    {
        if(nums[0] == 0)
            return 1;
        else
            return 0;
    }
    //select sort
    for(int i = 0; i < numsSize - 1; i++)
    {
        int min = i;
        for(int j = i + 1;j < numsSize; j++)
        {
            if(nums[j] < nums[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            int tmp = nums[i];
            nums[i] = nums[min];
            nums[min] = tmp;
        }
        if(i != nums[i])
            return i;           
    }

    if(nums[numsSize - 1] != numsSize)
        return numsSize;
    return numsSize - 1;
}
//function 2:n个数求和 减去数组中的数，剩下的就是丢失的数字，牛逼
int missingNumber(int* nums, int numsSize) {
    int sum = ((0 + numsSize) * (numsSize + 1)) / 2;
    for(int i = 0; i < numsSize; i++)
    {
        sum = sum - nums[i];
    }
    return sum;
}
