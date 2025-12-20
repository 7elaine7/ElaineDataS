/*
**************************************************************
    Author：Elsun
    Date：2025-12-20
    Note: Leetcode 414
**************************************************************
414. 第三大的数
给你一个非空数组，返回此数组中 第三大的数 。如果不存在，则返回数组中最大的数。
示例 1：
输入：[3, 2, 1]
输出：1
解释：第三大的数是 1 。
示例 2：
输入：[1, 2]
输出：2
解释：第三大的数不存在, 所以返回最大的数 2 。
示例 3：
输入：[2, 2, 3, 1]
输出：1
解释：注意，要求返回第三大的数，是指在所有不同数字中排第三大的数。
此例中存在两个值为 2 的数，它们都排第二。在所有不同数字中排第三大的数为 1 。
提示：
1 <= nums.length <= 104
-231 <= nums[i] <= 231 - 1
进阶：你能设计一个时间复杂度 O(n) 的解决方案吗？
*/
void swap(int* nums, int n1, int n2)
{
    int tmp = nums[n1];
    nums[n1] = nums[n2];
    nums[n2] = tmp;
}
int slelectQ(int* nums, int n1, int n2)
{
    int i = n1;
    int j = n1;
      
    for(; j < n2; j++)
    {
        if(nums[j] >= nums[n2])
        {
            if(i != j)
                swap(nums, i, j);
            i++;
        }
    }
    swap(nums, i, n2);

    return i;
}
void quickSort(int* nums, int n1, int n2)
{
    if(n1 >= n2)
        return;
    int q = slelectQ(nums, n1, n2);
    quickSort(nums, n1, q - 1);
    quickSort(nums, q + 1, n2);
}
int thirdMax(int* nums, int numsSize) {
    quickSort(nums, 0, numsSize - 1);

    if(numsSize < 3)
        return nums[0];
    int count = 1;
    int result = nums[0];
    for(int i = 1; i < numsSize; i++)
    {
        if(nums[i] < result)
        {
            result = nums[i];
            count++;
            if(count == 3)
                return result;
        }
    }
    return nums[0];
}