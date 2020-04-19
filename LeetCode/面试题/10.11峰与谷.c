/*
面试题 10.11. 峰与谷
在一个整数数组中，“峰”是大于或等于相邻整数的元素，相应地，“谷”是小于或等于相邻整数的元素。例如，在数组{5, 8, 6, 2, 3, 4, 6}中，{8, 6}是峰， {5, 2}是谷。
现在给定一个整数数组，将该数组按峰与谷的交替顺序排序。
示例:
输入: [5, 3, 1, 2, 3]
输出: [5, 1, 3, 2, 3]
提示：
nums.length <= 10000
*/

//function 1  超出时间限制。。。。。。。。。。。。。。
//先排序小到大，再12换，34换，56换。。。
void swap(int* nums, int m, int n)
{
    int tmp = nums[m];
    nums[m] = nums[n];
    nums[n] = tmp;
}
int get_q(int* nums, int start, int end)
{
    int i = start;
    int j = start;
    for(; j < end; j++)
    {
        if(nums[j] < nums[end])
        {
            swap(nums, i, j);
            i++;
        }
    }
    swap(nums, i, end);
    return i;
}
void quik_sort(int* nums, int start, int end)
{
    if(start >= end)
        return;
    int q = get_q(nums, start, end);
    quik_sort(nums, 0, q-1);
    quik_sort(nums, q+1, end);
}
void wiggleSort(int* nums, int numsSize){
    if(NULL == nums || 0 == numsSize)
        return nums;
    quik_sort(nums, 0, numsSize - 1);
    for(int i = 0; i < numsSize - 1; i = i + 2)
    {
        swap(nums, i, i+1);
    }
}

//答案是按谷峰顺序的，偶数位小，奇数位大
//所以如果是偶数位且比前一个大，交换，奇数位比前一个小，交换
void wiggleSort(int* nums, int numsSize){
    if(NULL == nums || 0 == numsSize)
        return nums;

    for(int i = 1; i < numsSize; i++)
    {
        if((0 == i % 2 && nums[i] > nums[i-1]) || (1 == i % 2 && nums[i] < nums[i-1]))
        {
            int tmp = nums[i];
            nums[i] = nums[i-1];
            nums[i-1] = tmp;
        }
    }
}