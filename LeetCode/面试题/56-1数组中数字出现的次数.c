/*
先对所有数字进行一次异或，得到两个出现一次的数字的异或值。
在异或结果中找到任意为1的位。此题我们找最低为1的位
根据这一位对所有的数字进行分组。两个只出现一次的数字必然在两个不同的组中
在每个组内进行异或操作，得到两个数字。
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumbers(int* nums, int numsSize, int* returnSize){
    int tmp = 0;
    for(int i = 0; i < numsSize; ++i)
        tmp = tmp ^ nums[i];

    int bit = 1;
    while((tmp & bit) == 0) //==优先级高于按位与
        bit = bit << 1;
    
    *returnSize = 2;
    int* array = (int*)malloc(sizeof(int) * 2);
    array[0] = 0;
    array[1] = 0;

    for(int i = 0; i < numsSize; ++i)
    {
        if((nums[i] & bit) == 0)
            array[0] = array[0] ^ nums[i];
        else
            array[1] = array[1] ^ nums[i];
    }
    return array;
}