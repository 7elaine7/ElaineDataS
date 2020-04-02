/*
给定一个整数数组 nums，将该数组升序排列。
示例 1：
输入：[5,2,3,1]
输出：[1,2,3,5]
示例 2：
输入：[5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
提示：
1 <= nums.length <= 10000
-50000 <= nums[i] <= 50000
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //冒泡排序     超时
 void swap(int *array, int m, int n)
 {
     int tmp = array[m];
     array[m] = array[n];
     array[n] = tmp;
 }
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if(numsSize <= 1)
        return nums;
    for(int i = 0; i < numsSize; ++i)
    {
        bool flag = false;
        for(int j = 0; j < numsSize - i - 1; ++j)
        {
            if(nums[j] > nums[j+1])
            {
                swap(nums, j, j+1);
                flag = true;
            }
        }
        if(false == flag)
            break;
    }
    return nums;
}

//插入排序      超时
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //插入排序     将未排序区数字依次插入到已排序区
 void swap(int *array, int m, int n)
 {
     int tmp = array[m];
     array[m] = array[n];
     array[n] = tmp;
 }
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if(numsSize <= 1)
        return nums;
    for(int i = 1; i < numsSize; ++i)
    {
        for(int j = i - 1; j >=0; --j)
        {
            if(nums[j] > nums[j + 1])
                swap(nums, j, j+1);
            else
                break;
        }
    }
    return nums;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //选择排序     将未排序区选出最小值，依次插入到已排序区最后
void swap(int *array, int m, int n)
{
    int tmp = array[m];
    array[m] = array[n];
    array[n] = tmp;
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if(numsSize <= 1)
        return nums;
    for(int i = 0; i < numsSize; ++i)
    {
        int min = i;
        for(int j = numsSize - 1; j >= i; --j)
        {
            if(nums[j] < nums[min])
                min = j;
        }
        swap(nums, i, min);
    }
    return nums;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 //快排     88ms
void swap(int *array, int m, int n)
{
    int tmp = array[m];
    array[m] = array[n];
    array[n] = tmp;
}
int get_q(int *array, int start, int end)
{
    int i = start;
    for(int j = start; j < end; ++j)
    {
        if(array[j] < array[end])
        {
            swap(array, i, j);
            ++i;
        }
    }
    swap(array, i, end);
    return i;
}
void quick_sort(int *array, int start, int end)
{
    if(start >= end)
        return;
    int q = get_q(array, start, end);
    quick_sort(array, start, q - 1);
    quick_sort(array, q + 1, end);
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if(numsSize <= 1)
        return nums;
    quick_sort(nums, 0, numsSize - 1);
    return nums;
}

/*
 计数排序
 执行用时 :72 ms, 在所有 C 提交中击败了95.37%的用户
 内存消耗 :14.9 MB, 在所有 C 提交中击败了100.00%的用户
 */
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if(numsSize <= 1)
        return nums;
    int min = nums[0];
    int max = nums[0];
    for(int i = 0; i < numsSize; ++i)
    {
        if(nums[i] < min)
            min = nums[i];
        else if(nums[i] > max)
            max = nums[i];
    }
    int count = max - min + 1;  //桶数  从min到max 对应数组从0到count
    int* array = (int*)malloc(sizeof(int) * count);
    memset(array, 0, sizeof(int) * count);
    //每个数均匀分配到每个桶
    for(int i = 0; i < numsSize; ++i)
    {
        array[nums[i] - min]++;
    }
    for(int i = 1; i < count; ++i)
    {
        array[i] = array[i] + array[i - 1];
    }

    int *tmp = (int*)malloc(sizeof(int) * numsSize);
    for(int i = numsSize - 1; i >= 0; --i)
    {
        int index = array[nums[i] - min] - 1;
        tmp[index] = nums[i];
        array[nums[i] - min]--;
    }
    return tmp;
}

/*
 堆排序,大顶堆，最后排序会从小到大
 超时
 */

void swap(int* nums, int m, int n)
{
    int tmp = nums[m];
    nums[m] = nums[n];
    nums[n] = tmp;
}
void heapify(int* nums, int parent, int size)
{
    int max;
    while(true)
    {
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;
        max = parent;
        if(left < size && nums[left] > nums[max])
            max = left;
        if(right < size && nums[right] > nums[max])
            max = right;
        if(max == parent)
            break;
        swap(nums, parent, max);
        parent = max;
    }
}
void build_heapify(int* nums, int size)
{
    for(int i = (size - 1 - 1) / 2; i >= 0; --i)
    {
        heapify(nums, i, size);
    }
}
void sort_heapify(int* nums, int size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        int count = size - i;
        build_heapify(nums, count);
        swap(nums, count - 1, 0);
    }
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if(numsSize <= 1)
        return nums;
    
    sort_heapify(nums, numsSize);
    return nums;
}