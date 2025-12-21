/*
**************************************************************
    Author：Elsun
    Date：2025-12-21
    Note: Leetcode 594
**************************************************************
594. 最长和谐子序列
尝试过
简单
相关标签
premium lock icon
相关企业
和谐数组是指一个数组里元素的最大值和最小值之间的差别 正好是 1 。
给你一个整数数组 nums ，请你在所有可能的 子序列 中找到最长的和谐子序列的长度。
数组的 子序列 是一个由数组派生出来的序列，它可以通过删除一些元素或不删除元素、且不改变其余元素的顺序而得到。
示例 1：
输入：nums = [1,3,2,2,5,2,3,7]
输出：5
解释：
最长和谐子序列是 [3,2,2,2,3]。
示例 2：
输入：nums = [1,2,3,4]
输出：2
解释：
最长和谐子序列是 [1,2]，[2,3] 和 [3,4]，长度都为 2。
示例 3：
输入：nums = [1,1,1,1]
输出：0
解释：
不存在和谐子序列。
提示：
1 <= nums.length <= 2 * 104
-109 <= nums[i] <= 109
*/
//function 1, 超时
void swap(int* nums, int n1, int n2)
{
    int tmp = nums[n1];
    nums[n1] = nums[n2];
    nums[n2] = tmp;
}
int selectQ(int* nums, int n1, int n2)
{
    int i = n1, j = n1;
    for(; j < n2; j++)
    {
        if(nums[j] < nums[n2])
        {
            swap(nums, i, j);
            i++;
        }
    }
    swap(nums, i, n2);
    return i;
}
void Sort(int* nums, int n1, int n2)
{
    if(n1 >= n2)
        return;
    int q = selectQ(nums, n1, n2);
    Sort(nums, n1, q - 1);
    Sort(nums, q + 1, n2);
}
int findLHS(int* nums, int numsSize) {
    int count = 0;
    Sort(nums, 0, numsSize - 1);

    for(int i = 0; i < numsSize - 1; i++)
    {
        int sum = 1;
        bool flag = false;
        for(int j = i + 1; j < numsSize; j++)
        {
            if(nums[j] == (nums[i] + 1))
            {
                flag = true;
                sum++;
            }
            else if(nums[j] == nums[i])
                sum++;
        }

        if(flag)
            count = (count >= sum) ? count : sum;
    }
    return count;
}

//function 2 滑动窗口
void swap(int* nums, int n1, int n2)
{
    int tmp = nums[n1];
    nums[n1] = nums[n2];
    nums[n2] = tmp;
}
int selectQ(int* nums, int n1, int n2)
{
    int i = n1, j = n1;
    for(; j < n2; j++)
    {
        if(nums[j] < nums[n2])
        {
            swap(nums, i, j);
            i++;
        }
    }
    swap(nums, i, n2);
    return i;
}
void Sort(int* nums, int n1, int n2)
{
    if(n1 >= n2)
        return;
    int q = selectQ(nums, n1, n2);
    Sort(nums, n1, q - 1);
    Sort(nums, q + 1, n2);
}
int findLHS(int* nums, int numsSize) {
    int count = 0;
    Sort(nums, 0, numsSize - 1);

    int left = 0;
    for(int right = 0; right < numsSize; right++)
    {
        while(nums[right] - nums[left] > 1)
            left++;

        if(nums[right] == nums[left] + 1)
            count = count > (right - left + 1) ? count : (right - left + 1);
    }
      
    return count;
}
