/*
46. 全排列
给定一个 没有重复 数字的序列，返回其所有可能的全排列。
示例:
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/
//回溯算法，挨个填数字，每一个当前位都把此时剩下的数字挨个填一遍
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void swap(int*nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
void dfs(int* nums, int *count, int first, int size, int** array)
{
    if(first == size)
    {
        for(int i = 0; i < size; ++i)
        {
            array[*count][i] = nums[i];
        }
        (*count)++;
        return;
    }
    for(int i = first; i < size; ++i)
    {
        swap(nums, i, first);
        dfs(nums, count, first + 1, size, array);
        swap(nums, i, first);
    }
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    //一共有n！种排列组合
    *returnSize = 1;
    for(int i = 1; i <= numsSize; ++i)
    {
        *returnSize = (*returnSize) * i;
    }
    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    int** array = (int**)malloc(sizeof(int*) * (*returnSize));
    for(int i = 0; i < (*returnSize); ++i)
    {
        array[i] = (int*)malloc(sizeof(int) * numsSize);
        (*returnColumnSizes)[i] = numsSize;
    }
    int count = 0;
    dfs(nums, &count, 0, numsSize, array);
    return array;
}