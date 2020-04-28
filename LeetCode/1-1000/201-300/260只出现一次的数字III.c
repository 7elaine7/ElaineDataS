/*
260. 只出现一次的数字 III
给定一个整数数组 nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。 找出只出现一次的那两个元素。
示例 :
输入: [1,2,1,3,2,5]
输出: [3,5]
注意：
结果输出的顺序并不重要，对于上面的例子， [5, 3] 也是正确答案。
你的算法应该具有线性时间复杂度。你能否仅使用常数空间复杂度来实现？
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    int result = 0;
    for(int i = 0; i < numsSize; ++i)
        result = result ^ nums[i];
    int mask = 1;
    while((result & mask) == 0)
        mask = mask << 1;
    *returnSize = 2;
    int* array = (int*)malloc(sizeof(int) * 2);
    array[0] = 0;
    array[1] = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if((nums[i] & mask) == 0)
            array[0] = array[0] ^ nums[i];
        else
            array[1] = array[1] ^ nums[i];
    }
    return array;
}