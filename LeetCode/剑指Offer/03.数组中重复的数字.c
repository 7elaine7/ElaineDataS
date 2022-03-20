/*
剑指 Offer 03. 数组中重复的数字
找出数组中重复的数字。
在一个长度为 n 的数组 nums 里的所有数字都在 0～n-1 的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。
示例 1：
输入：
[2, 3, 1, 0, 2, 5, 3]
输出：2 或 3 
限制：
2 <= n <= 100000
*/
//function 1, qsort
int comfunc(const void * a, const void * b)
{
    return *(int*)a < *(int*)b ? -1 : *(int*)a > *(int*)b;
}
int findRepeatNumber(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), comfunc);
    for(int i = 0; i < numsSize - 1; ++i)
    {
        if(nums[i] == nums[i + 1])
            return nums[i];
    }
    return -1;
}

//function 2, 冒泡，超出时间限制
//冒泡
int findRepeatNumber(int* nums, int numsSize){
    for(int i = 0; i < numsSize; ++i)
    {
        bool flag = false;
        for(int j = 0; j < numsSize - i - 1; ++j)
        {
            if(nums[j] > nums[j + 1])
            {
                int tmp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = tmp;
                flag = true;
            }
        }
        if(!flag)
            break;
    }

    for(int i = 0; i < numsSize - 1; ++i)
    {
        if(nums[i] == nums[i + 1])
            return nums[i];
    }
    return -1;
}

//function 3, 插入排序
//插入
int findRepeatNumber(int* nums, int numsSize){
    
    for(int i = 1; i < numsSize; ++i)
    {
        int tmp = nums[i];
        int j;
        for(j = i - 1; j >= 0; --j)
        {
            if(nums[j] > tmp)
            {
                nums[j + 1] = nums[j];
            }
            else
                break;
        }
        nums[j + 1] = tmp;
    }

    for(int i = 0; i < numsSize - 1; ++i)
    {
        if(nums[i] == nums[i + 1])
            return nums[i];
    }
    return -1;
}

//function 4, 选择排序， 超时
//选择
int findRepeatNumber(int* nums, int numsSize){
    for(int i = 0; i < numsSize - 1; ++i)
    {
        int min = i;
        for(int j = i; j < numsSize; ++j)
        {
            if(nums[j] < nums[min])
            {
                min = j;
            }
        }
        int tmp = nums[i];
        nums[i] = nums[min];
        nums[min] = tmp;
    }
    for(int i = 0; i < numsSize; ++i)
    {
        printf("nums[%d] = %d\n", i, nums[i]);
    }

    for(int i = 0; i < numsSize - 1; ++i)
    {
        if(nums[i] == nums[i + 1])
            return nums[i];
    }
    return -1;
}

//function 4, 快排, 超出时间限制
void swap(int* nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
int select_q(int* nums, int a, int b)
{
    int i = a;
    int j = a;
    int value = nums[b];
    for(; j < b; ++j)
    {
        if(nums[j] <= value)
        {
            swap(nums, i, j);
            i++;
        }
    }

    swap(nums, i, b);
    return i;
}
void quick_sort(int* nums, int a, int b)
{
    if(a >= b)
        return;
    int q = select_q(nums, a, b);
    quick_sort(nums, a, q - 1);
    quick_sort(nums, q + 1, b);
}
int findRepeatNumber(int* nums, int numsSize){
    quick_sort(nums, 0, numsSize - 1);

    for(int i = 0; i < numsSize - 1; ++i)
    {
        if(nums[i] == nums[i + 1])
            return nums[i];
    }
    return -1;
}