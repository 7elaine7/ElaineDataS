/*
给定一个大小为 n 的数组，找到其中的多数元素。多数元素是指在数组中出现次数大于 ⌊ n/2 ⌋ 的元素。

你可以假设数组是非空的，并且给定的数组总是存在多数元素。

 

示例 1:

输入: [3,2,3]
输出: 3
示例 2:

输入: [2,2,1,1,1,2,2]
输出: 2
*/

int majorityElement(int* nums, int numsSize){
    //摩尔投票算法
    int m;
    int count = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(0 == count)
        {
            m = nums[i];
            count++;
        }
        else if(nums[i] == m)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    return m;
}

//2
int majorityElement(int* nums, int numsSize){
    //摩尔投票算法
    int m = nums[0];
    int count = 1;
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] == m)
        {
            count++;
        }
        else
        {
            count--;
            if(0 == count)
            {
                m = nums[i];
                count++;
            }
        }
    }
    return m;
}