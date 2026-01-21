/*
**************************************************************
    Author：Elsun
    Date：2026-1-21
    Note: Leetcode arrayII Q2
**************************************************************
Q3. 找到所有数组中消失的数字
给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
示例 1：
输入：nums = [4,3,2,7,8,2,3,1]
输出：[5,6]
示例 2：
输入：nums = [1,1]
输出：[2]
提示：
n == nums.length
1 <= n <= 105
1 <= nums[i] <= n
进阶：你能在不使用额外空间且时间复杂度为 O(n) 的情况下解决这个问题吗? 你可以假定返回的数组不算在额外空间内。
*/
//function 1;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    int* count = (int*)malloc(sizeof(int) * (numsSize + 1));
    if(!count)
        return NULL;
    memset(count, 0, sizeof(int) * (numsSize + 1));
    for(int i = 0; i < numsSize; i++)
    {
        count[nums[i]]++;
    }
    int* result = (int*)malloc(sizeof(int) * numsSize);
    if(!result)
        return NULL;
    *returnSize = 0;
    for(int i = 1; i <= numsSize; i++)
    {
        if(!count[i])
        {
            result[*returnSize] = i;
            (*returnSize)++;
        }
    }
    int* p = (int*)realloc(result, sizeof(int) * (*returnSize));
    if(p)
        result = p;
    p = NULL;
    free(p);
    return result;
}
//funtion 2;
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    if(!result)
        return NULL;
    for(int i = 0; i < numsSize; i++)
    {
        int index = (nums[i] - 1) % numsSize;
        if(nums[index] <= numsSize)
            nums[index] += numsSize;
    }
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] <= numsSize)
        {
            result[(*returnSize)++] = i + 1;
        }
    }
    return result;
}