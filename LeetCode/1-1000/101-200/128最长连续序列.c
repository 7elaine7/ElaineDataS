/*
128. 最长连续序列
给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。
示例:
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
*/

//function 1, 快排
void swap(int* nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
int get_q(int* nums, int start, int end)
{
    int i = start;
    for(int j = i; j < end; ++j)
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
    quik_sort(nums, start, q - 1);
    quik_sort(nums, q + 1, end);
}
int longestConsecutive(int* nums, int numsSize){
    if(NULL == nums || 0 == numsSize)
        return 0;
    quik_sort(nums, 0, numsSize - 1);
    int max = 1;
    int count = 1;
    for(int i = 0; i < numsSize - 1; ++i)
    {
        //相等的情况
        if(nums[i] == nums[i + 1])
        {
            continue;
        }
        else if(nums[i] + 1 == nums[i + 1])
        {
            count++;
        }
        else
        {
            max = max > count ? max : count;
            count = 1;
        }
    }
    //如果整个数组都是连续的情况
    max = max > count ? max : count;
    return max;
}

//function 2, 归并
//归并排序
void merge(int*nums, int start, int mid, int end)
{
    int* tmp = (int*)malloc(sizeof(int) * (end - start + 1));
    int n1 = start;
    int n2 = mid + 1;
    int n = 0;
    while((n1 <= mid) && (n2 <= end))
    {
        if(nums[n1] <= nums[n2])
        {
            tmp[n++] = nums[n1++];
        }
        else
        {
            tmp[n++] = nums[n2++];
        }
    }
    if(n1 <= mid)   //n1还有剩余
    {
        memcpy(&(tmp[n]), &(nums[n1]), sizeof(int) * (mid - n1 + 1));
        memcpy(&(nums[start]), tmp, sizeof(int) * (end - start + 1));
    }
    else if(n2 <= end)  //n2还有剩余, 直接把tmp复制给nums就好
    {
        memcpy(&(nums[start]), tmp, sizeof(int) * n);
    }
}
void merge_sort(int* nums, int start, int end)
{
    if(start >= end)
        return;
    int mid = start + (end - start) / 2;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, end);
    merge(nums, start, mid, end);
}
int longestConsecutive(int* nums, int numsSize){
    if(NULL == nums || 0 == numsSize)
        return 0;
    merge_sort(nums, 0, numsSize - 1);
    int max = 1;
    int count = 1;
    for(int i = 0; i < numsSize - 1; ++i)
    {
        if(nums[i] == nums[i + 1])
        {
            continue;
        }
        else if(nums[i] + 1 == nums[i + 1])
        {
            count++;
        }
        else
        {
            max = max > count ? max : count;
            count = 1;
        }
    }
    max = max > count ? max : count;
    return max;
}