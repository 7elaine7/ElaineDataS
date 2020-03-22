/*
16. 最接近的三数之和
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target 最接近。
返回这三个数的和。假定每组输入只存在唯一答案。
例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
*/

//快排
void swap(int *array, int m, int n)
{
    int tmp = array[m];
    array[m] = array[n];
    array[n] = tmp;
}
int get_q(int *array, int start, int end)
{
    int i, j;
    i = j = start;
    while(j < end)
    {
        if(array[j] < array[end])
        {
            swap(array, i, j);
            ++i;
        }
        ++j;
    }
    swap(array, i, end);
    return i;
}
void quik_sort(int *array, int start, int end)
{
    if(start >= end)
        return;
    int q = get_q(array, start, end);
    quik_sort(array, start, q-1);
    quik_sort(array, q+1, end);    
}
int threeSumClosest(int* nums, int numsSize, int target){
    if(numsSize < 3)
        return 0;
    quik_sort(nums, 0, numsSize - 1);
    int result = nums[0] + nums[1] + nums[2];
    for(int i = 0; i < numsSize - 2; ++i)
    {
        int left = i + 1;
        int right = numsSize - 1;
        while(left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];
            if(abs(sum - target) < abs(result - target))
            {
                result = sum;
            }
            if(sum == target)
                return target;
            else if(sum > target)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
    }
    return result;
}