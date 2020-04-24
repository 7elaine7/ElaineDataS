/*
面试题51. 数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
示例 1:
输入: [7,5,6,4]
输出: 5 
限制：
0 <= 数组长度 <= 50000
*/

//归并排序的合并过程中，计算逆序对
void merge_sort(int* nums, int start, int end, int* count)
{
    if(start >= end)
        return;
    int mid = start - (start - end) / 2;
    merge_sort(nums, start, mid, count);
    merge_sort(nums, mid + 1, end, count);
    //merge
    int* tmp = (int*)malloc(sizeof(int) * (end - start + 1));
    int n1 = start;
    int n2 = mid + 1;
    int index = 0;
    while(true)
    {
        if(n1 > mid || n2 > end)
            break;
        if(nums[n2] < nums[n1])
        {
            //如果取的是后半部分的值，证明此时前半部分当前未合并的值全部大于后半部分的值，为为逆序对的对数
            *count = *count + mid - n1 + 1;
            tmp[index++] = nums[n2++];
        }
        else
        {
            tmp[index++] = nums[n1++];
        }
    }
    if(n1 > mid && n2 <= end)
    {
        memcpy(&(nums[start]), tmp, sizeof(int) * index);
    }
    else if(n2 > end && n1 <= mid)
    {
        memcpy(&(tmp[index]), &(nums[n1]), sizeof(int) * (mid - n1 + 1));
        memcpy(&(nums[start]), tmp, sizeof(int) * (end - start + 1));
    }
}
int reversePairs(int* nums, int numsSize){
    int count = 0;
    merge_sort(nums, 0, numsSize - 1, &count);
    return count;    
}