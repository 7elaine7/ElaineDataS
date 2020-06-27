/*
41. 缺失的第一个正数
给你一个未排序的整数数组，请你找出其中没有出现的最小的正整数。
示例 1:
输入: [1,2,0]
输出: 3
示例 2:
输入: [3,4,-1,1]
输出: 2
示例 3:
输入: [7,8,9,11,12]
输出: 1
提示：
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的额外空间。
*/

//funtion 1
int firstMissingPositive(int* nums, int numsSize){
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] <= 0)
            nums[i] = numsSize + 1;
    }
    for(int i = 0; i < numsSize; ++i)
    {
        int tmp = abs(nums[i]);
        if(tmp <= numsSize)
        {
            nums[tmp - 1] = -abs(nums[tmp - 1]);
        }
    }
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] > 0)
            return i + 1;
    }
    return numsSize + 1;
}

//function 2
void swap(int* nums, int x, int y)
{
    int tmp = nums[x];
    nums[x] = nums[y];
    nums[y] = tmp;
}
int firstMissingPositive(int* nums, int numsSize){
    for(int i = 0; i < numsSize; ++i)
    {
        //不停的把[0, numsSize]的数放在正确的位置
        while(nums[i] > 0 && nums[i] <= numsSize && nums[i] != nums[nums[i] - 1])
        {
            swap(nums, i, nums[i] - 1);
        }
    }
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] != i + 1)
            return i + 1;
    }
    return numsSize + 1;
}