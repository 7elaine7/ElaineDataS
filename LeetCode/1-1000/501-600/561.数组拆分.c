/*
**************************************************************
    Author：Elsun
    Date：2025-12-21
    Note: Leetcode 561
**************************************************************
561.数组拆分
给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。
返回该 最大总和 。
示例 1：
输入：nums = [1,4,3,2]
输出：4
解释：所有可能的分法（忽略元素顺序）为：
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
所以最大总和为 4
示例 2：
输入：nums = [6,2,6,5,1,2]
输出：9
解释：最优的分法为 (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9
提示：
1 <= n <= 104
nums.length == 2 * n
-104 <= nums[i] <= 104
*/
void swap(int *nums, int n1, int n2)
{
    int tmp = nums[n1];
    nums[n1] = nums[n2];
    nums[n2] = tmp;
}
int selectQ(int *nums, int n1, int n2)
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
void Sort(int *nums, int n1, int n2)
{
    if(n1 >= n2)
        return;
    int q = selectQ(nums, n1, n2);
    Sort(nums, n1, q - 1);
    Sort(nums, q + 1, n2);
}
int arrayPairSum(int* nums, int numsSize) {
    Sort(nums, 0, numsSize - 1);
    int sum = 0;
    for(int i = 0; i <= numsSize - 2; i = i + 2)
    {
        sum = sum + nums[i];
    }
    return sum;
}