/*
137. 只出现一次的数字 II
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？
示例 1:
输入: [2,2,3,2]
输出: 3
示例 2:
输入: [0,1,0,1,0,1,99]
输出: 99
*/
int singleNumber(int* nums, int numsSize){
    int count;
    long mask;
    int result = 0;
    for(int m = 0; m < 32; ++m)
    {
        mask = 1;   //1 int不能直接左移32位
        count = 0;
        mask = mask << m;
        for(int n = 0; n < numsSize; ++n)
        {
            if(mask & nums[n])
                count++;
        }
        if(count % 3)
        {
            result = result | mask;
        }
    }
    return result;
}