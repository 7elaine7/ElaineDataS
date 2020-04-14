/*
面试题66. 构建乘积数组
给定一个数组 A[0,1,…,n-1]，
请构建一个数组 B[0,1,…,n-1]，其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。
不能使用除法。 
示例:
输入: [1,2,3,4,5]
输出: [120,60,40,30,24] 
提示：
所有元素乘积之和不会溢出 32 位整数
a.length <= 100000
*/
//the same with  238. 除自身以外数组的乘积
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* constructArr(int* a, int aSize, int* returnSize){
    *returnSize = aSize;
    if(NULL == a || aSize == 0)
        return a;
    int* array = (int*)malloc(sizeof(int) * aSize);
    array[0] = 1;
    for(int i = 1; i < aSize; ++i)
    {
        array[i] = array[i-1] * a[i-1];
    }
    int sum = a[aSize - 1];
    for(int i = aSize - 2; i >= 0; --i)
    {
        array[i] = array[i] * sum;
        sum = sum * a[i];
    }
    return array;
}