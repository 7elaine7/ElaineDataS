/*
238. 除自身以外数组的乘积
给你一个长度为 n 的整数数组 nums，其中 n > 1，返回输出数组 output ，
其中 output[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积。
示例:
输入: [1,2,3,4]
输出: [24,12,8,6]
提示：题目数据保证数组之中任意元素的全部前缀元素和后缀（甚至是整个数组）的乘积都在 32 位整数范围内。
说明: 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
进阶：
你可以在常数空间复杂度内完成这个题目吗？（ 出于对空间复杂度分析的目的，输出数组不被视为额外空间。）
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int *array = (int*)malloc(sizeof(int) * numsSize);
    array[0] = 1;
    int n;
    //从左侧开始，数组中存储当前数字左侧乘积
    for(n = 1; n < numsSize; ++n)
    {
        array[n] = array[n-1] * nums[n-1];
    }
    //从右侧开始，当前数字右侧乘积
    int right = 1;
    for(n = numsSize-2; n >= 0; --n)
    {
        right = right * nums[n+1];
        array[n] = right * array[n];        
    }
    *returnSize = numsSize;
    return array;
}

//优化，添加 [] 的情况
int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * numsSize);
    *returnSize = numsSize;
    if(0 == numsSize || NULL == nums)
        return res;
    //当前值的左边乘积
    res[0] = 1;
    for(int i = 1; i < numsSize; ++i)
    {
        res[i] = res[i - 1] * nums[i - 1];
    }
    //乘当前值右边乘积
    int right = 1;
    for(int i = numsSize - 2; i >= 0; --i)
    {
        right *= nums[i + 1];
        res[i] = res[i] * right;
    }
    return res;
}