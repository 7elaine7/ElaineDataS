/*
315. 计算右侧小于当前元素的个数
给定一个整数数组 nums，按要求返回一个新数组 counts。数组 counts 有该性质： counts[i] 的值是  nums[i] 右侧小于 nums[i] 的元素的数量。
示例:
输入: [5,2,6,1]
输出: [2,1,1,0] 
解释:
5 的右侧有 2 个更小的元素 (2 和 1).
2 的右侧仅有 1 个更小的元素 (1).
6 的右侧有 1 个更小的元素 (1).
1 的右侧有 0 个更小的元素.
*/
//function 1， 暴力解法， 超时
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize){
    if(!nums || numsSize == 0)
    {
        *returnSize = 0;
        return NULL;
    }
    int* res = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; ++i)
    {
        int count = 0;
        for(int j = i + 1; j < numsSize; ++j)
        {
            if(nums[i] > nums[j])
                count++;
        }
        res[i] = count;
    }
    *returnSize = numsSize;
    return res;
}

//function 2， 栈， 逆序遍历数组，有序插入到栈中，在栈中的当前位置就是比自己小的个数
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countSmaller(int* nums, int numsSize, int* returnSize){
    int* stack = (int*)malloc(sizeof(int) * numsSize);
    memset(stack, 0, sizeof(int) * numsSize);
    int top = 0;
    int* res = (int*)malloc(sizeof(int) * numsSize);
    memset(res, 0, sizeof(int) * numsSize);
    *returnSize = numsSize;
    for(int i = numsSize - 1; i >= 0; --i)
    {
        if(top > 0 && nums[i] <= stack[top - 1])
        {
            int tmp = top++;
            //将nums当前值插入到栈中，插入的位置下边就是比自己小的
            while(tmp > 0 && nums[i] <= stack[tmp - 1])
            {
                stack[tmp] = stack[tmp - 1];    //比自己大的往上挪
                tmp--;
            }
            stack[tmp] = nums[i];
            res[i] = tmp;
        }
        else
        {
            stack[top] = nums[i];
            res[i] = top++;
        }
    }

    return res;
}