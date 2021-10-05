/*
NC157 单调栈
描述
给定一个长度为 nn 的可能含有重复值的数组 arrarr ，找到每一个 ii 位置左边和右边离 ii 位置最近且值比  arr_iarr i小的位置。
请设计算法，返回一个二维数组，表示所有位置相应的信息。位置信息包括：两个数字 LL 和 RR，如果不存在，则值为 -1，下标从 0 开始。
数据范围：
1≤n≤10^5
-10^9 ≤arr[i]≤10^9
复杂度要求：O(n)
示例1
输入：
[3,4,1,5,6,2,7]
返回值：
[[-1,2],[0,2],[-1,-1],[2,5],[3,5],[2,-1],[5,-1]]
*/
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 
 * @param nums int一维数组 
 * @param numsLen int nums数组长度
 * @return int二维数组
 * @return int* returnSize 返回数组行数
 * @return int** returnColumnSizes 返回数组列数
 */
int** foundMonotoneStack(int* nums, int numsLen, int* returnSize, int** returnColumnSizes ) {
    // write code here
    *returnSize = numsLen;
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsLen);
    int** res = (int**)malloc(sizeof(int*) * numsLen);
    
    for(int i = 0; i < numsLen; ++i)
    {
        (*returnColumnSizes)[i] = 2;
        res[i] = (int*)malloc(sizeof(int) * 2);
        memset(res[i], -1, sizeof(int) * 2);
    }
    
    //单调递增栈，存储index
    int* stack = (int*)malloc(sizeof(int) * numsLen);
    int top = -1;
    
    //从左向右
    for(int i = 0; i < numsLen; ++i)
    {
        while(top >= 0 && nums[stack[top]] > nums[i])
        {
            res[stack[top--]][1] = i;
        }
        stack[++top] = i;
    }
    top = -1;    //clear the stack
    //从右向左
    for(int i = numsLen - 1; i >= 0; --i)
    {
        while(top >= 0 && nums[stack[top]] > nums[i])
        {
            res[stack[top--]][0] = i;
        }
        stack[++top] = i;
    }
    return res;
}