/*
**************************************************************
    Author：Elsun
    Date：2025-12-18
    Note: Leetcode 217
**************************************************************
217. 存在重复元素
给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
示例 1：
输入：nums = [1,2,3,1]
输出：true
解释：
元素 1 在下标 0 和 3 出现。
示例 2
输入：nums = [1,2,3,4]
输出：false
解释：
所有元素都不同。
示例 3：
输入：nums = [1,1,1,3,3,4,3,2,4,2]
输出：true
提示：
1 <= nums.length <= 105
-109 <= nums[i] <= 109
*/
//冒泡排序
bool containsDuplicate(int* nums, int numsSize) {
    bool result = false;
    if(numsSize <= 1)
        return result;
    for(int i = 0; i < numsSize; ++i)
    {
        bool flag = false;
        for(int j = 0; j < numsSize - i - 1; ++j)
        {
            if(nums[j] == nums[j + 1])
                return true;
            else if(nums[j] > nums[j + 1])
            {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
                flag = true;
            }
        }
        if(!flag)
            break;
    }
    return result;
}