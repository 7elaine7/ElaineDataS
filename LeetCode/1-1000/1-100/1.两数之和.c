/*
1. 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

 

示例 1：

输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：

输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
提示：
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案
进阶：你可以想出一个时间复杂度小于 O(n2) 的算法吗？
*/
//function 1, 先排序，后滑动窗口
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct node
{
    int value;
    int index;
}Node;
void swap(Node* nums, int a, int b)
{
    Node tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
int select_q(Node* nums, int start, int end)
{
    int i = start;
    for(int j = start; j < end; ++j)
    {
        if(nums[j].value < nums[end].value)
        {
            swap(nums, j, i++);
        }
    }
    swap(nums, i, end);
    return i;
}
void quicksort(Node* nums, int start, int end)
{
    if(start >= end)
        return;
    int q = select_q(nums, start, end);
    quicksort(nums, start, q - 1);
    quicksort(nums, q + 1, end);
}
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    Node* array = (Node*)malloc(sizeof(Node) * numsSize);
    for(int i = 0; i < numsSize; ++i)
    {
        array[i].value = nums[i];
        array[i].index = i;
    }
    quicksort(array, 0, numsSize - 1);
    *returnSize = 2;
    int* res = (int*)malloc(sizeof(int) * 2);
    int left = 0;
    int right = numsSize - 1;
    while(left < right)
    {
        int tmp = array[left].value + array[right].value;
        if(target == tmp)
        {
            res[0] = array[left].index;
            res[1] = array[right].index;
            break;
        }
        else if(tmp < target)
            left++;
        else
            right--;
    }
    return res;
}

//function 2，用哈希，将target - x记录在哈希中，再遍历查找