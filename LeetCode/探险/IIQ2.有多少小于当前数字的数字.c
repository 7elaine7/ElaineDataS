/*
**************************************************************
    Author：Elsun
    Date：2026-1-21
    Note: Leetcode arrayII Q2
**************************************************************
Q2. 有多少小于当前数字的数字
给你一个数组 nums，对于其中每个元素 nums[i]，请你统计数组中比它小的所有数字的数目。
换而言之，对于每个 nums[i] 你必须计算出有效的 j 的数量，其中 j 满足 j != i 且 nums[j] < nums[i] 。
以数组形式返回答案。
示例 1：
输入：nums = [8,1,2,2,3]
输出：[4,0,1,1,3]
解释： 
对于 nums[0]=8 存在四个比它小的数字：（1，2，2 和 3）。 
对于 nums[1]=1 不存在比它小的数字。
对于 nums[2]=2 存在一个比它小的数字：（1）。 
对于 nums[3]=2 存在一个比它小的数字：（1）。 
对于 nums[4]=3 存在三个比它小的数字：（1，2 和 2）。
示例 2：
输入：nums = [6,5,4,8]
输出：[2,1,0,3]
示例 3：
输入：nums = [7,7,7,7]
输出：[0,0,0,0]
提示：
2 <= nums.length <= 500
0 <= nums[i] <= 100
*/
//function 1, 排序后去重
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node
{
    int index;
    int value;
}Node;

int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    if(!result)
        return NULL;
    memset(result, 0, sizeof(int) * numsSize);

    Node* array = (Node*)malloc(sizeof(Node) * numsSize);
    if(!array)
        return NULL;
    for(int i = 0; i < numsSize; i++)
    {
        array[i].index = i;
        array[i].value = nums[i];
    }

    //insert sort
    for(int j = 1; j < numsSize; j++)
    {
        Node tmp = array[j];
        int i = j - 1;
        for(; i >= 0; i--)
        {
            if(array[i].value >= tmp.value)
            {
                array[i + 1] = array[i];
            }
            else
                break;
        }
        array[i + 1] = tmp;
    }
    for(int i = 0; i < numsSize; i++)
    {
        printf("array[%d].index = %d, value = %d\n", i, array[i].index, array[i].value);
    }
    int pre = -1;
    for(int c = 0; c < numsSize; c++)
    {
        if(pre == -1 || array[c].value != array[c - 1].value)
            pre = c;
        result[array[c].index] = pre;
    }
    return result;
}
//function 2，计数排序
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* smallerNumbersThanCurrent(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int* result = (int*)malloc(sizeof(int) * numsSize);
    if(!result)
        return NULL;
    memset(result, 0, sizeof(int) * numsSize);

    int count[101] = {0};
    for(int i = 0; i < numsSize; i++)
    {
        count[nums[i]]++;
    }
    for(int i = 1; i < 101; i++)
    {
        count[i] = count[i - 1] + count[i];
    }
    for(int i = 0; i < numsSize; i++)
    {
        result[i] = nums[i] == 0 ? 0 : count[nums[i] - 1];
    }

    return result;
}