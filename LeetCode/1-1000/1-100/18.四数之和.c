/*
18. 四数之和
示例 1：
输入：nums = [1,0,-1,0,-2,2], target = 0
输出：[[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
示例 2：
输入：nums = [2,2,2,2,2], target = 8
输出：[[2,2,2,2]]
提示：
1 <= nums.length <= 200
-109 <= nums[i] <= 109
-109 <= target <= 109
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//function 1, 排序， qsort
#define NUM 1001
int comfunc(const void * a, const void * b)
{
    return *(int*)a < *(int*)b ? -1 : *(int*)a > *(int*)b;
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = (int*)malloc(sizeof(int) * NUM);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * NUM);
    qsort(nums, numsSize, sizeof(int), comfunc);

    if(numsSize < 4)
        return res;
    for(int i = 0; i <= numsSize - 4; ++i)
    {
        if((nums[i] > target) && (nums[i + 1] >= 0))
            return res;
        if((i > 0) && (nums[i] == nums[i - 1]))
            continue;
        //寻找三个数之和为target - nums[i]
        for(int j = i + 1; j <= numsSize - 3; ++j)
        {
            if((nums[j] > target - nums[i]) && (nums[j + 1] >= 0))
                break;
            if((j > i + 1) && (nums[j] == nums[j - 1]))
                continue; 
            //寻找三个数之和为target - nums[i] - nums[j]
            int left = j + 1;
            int right = numsSize - 1;
            while(left < right)
            {
                if((left > j + 1) && (nums[left] == nums[left - 1]))
                {
                    left++;
                    continue;
                }
                if((right < numsSize - 1) && (nums[right] == nums[right + 1]))
                {
                    right--;
                    continue;
                }
                int sum = nums[left] + nums[right];
                int tmp = target - nums[i] - nums[j];
                if(sum == tmp)
                {
                    res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[(*returnSize)++] = 4;
                    left++;
                    right--;
                }
                else if(sum < tmp)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return res;
}

//function 2， 冒泡
#define NUM 1001
void bubble_sort(int* nums, int numsSize)
{
    if(numsSize <= 1)
        return;
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
            return;
    }
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = (int*)malloc(sizeof(int) * NUM);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * NUM);

    if(numsSize < 4)
        return res;
    //sort
    bubble_sort(nums, numsSize);

    for(int i = 0; i <= numsSize - 4; ++i)
    {
        if((nums[i] > target) && (nums[i + 1] >= 0))
            return res;
        if((i > 0) && (nums[i] == nums[i - 1]))
            continue;
        //寻找三个数之和为target - nums[i]
        for(int j = i + 1; j <= numsSize - 3; ++j)
        {
            if((nums[j] > target - nums[i]) && (nums[j + 1] >= 0))
                break;
            if((j > i + 1) && (nums[j] == nums[j - 1]))
                continue; 
            //寻找三个数之和为target - nums[i] - nums[j]
            int left = j + 1;
            int right = numsSize - 1;
            while(left < right)
            {
                if((left > j + 1) && (nums[left] == nums[left - 1]))
                {
                    left++;
                    continue;
                }
                if((right < numsSize - 1) && (nums[right] == nums[right + 1]))
                {
                    right--;
                    continue;
                }
                int sum = nums[left] + nums[right];
                int tmp = target - nums[i] - nums[j];
                if(sum == tmp)
                {
                    res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[(*returnSize)++] = 4;
                    left++;
                    right--;
                }
                else if(sum < tmp)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return res;
}

//function 3， 插入排序
#define NUM 1001
void insert_sort(int* nums, int numsSize)
{
    if(numsSize <= 1)
        return;
    for(int i = 1; i < numsSize; ++i)
    {
        int tmp = nums[i];
        int j = i - 1;
        for(; j >= 0; --j)
        {
            if(nums[j] > tmp)
            {
                nums[j+1] = nums[j];
            }
            else
                break;
        }
        nums[j + 1] = tmp;
    }
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = (int*)malloc(sizeof(int) * NUM);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * NUM);

    if(numsSize < 4)
        return res;
    //sort
    insert_sort(nums, numsSize);

    for(int i = 0; i <= numsSize - 4; ++i)
    {
        if((nums[i] > target) && (nums[i + 1] >= 0))
            return res;
        if((i > 0) && (nums[i] == nums[i - 1]))
            continue;
        //寻找三个数之和为target - nums[i]
        for(int j = i + 1; j <= numsSize - 3; ++j)
        {
            if((nums[j] > target - nums[i]) && (nums[j + 1] >= 0))
                break;
            if((j > i + 1) && (nums[j] == nums[j - 1]))
                continue; 
            //寻找三个数之和为target - nums[i] - nums[j]
            int left = j + 1;
            int right = numsSize - 1;
            while(left < right)
            {
                if((left > j + 1) && (nums[left] == nums[left - 1]))
                {
                    left++;
                    continue;
                }
                if((right < numsSize - 1) && (nums[right] == nums[right + 1]))
                {
                    right--;
                    continue;
                }
                int sum = nums[left] + nums[right];
                int tmp = target - nums[i] - nums[j];
                if(sum == tmp)
                {
                    res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[(*returnSize)++] = 4;
                    left++;
                    right--;
                }
                else if(sum < tmp)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return res;
}

//function 4， 选择排序
#define NUM 1001
void swap(int* nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
void select_sort(int* nums, int numsSize)
{
    if(numsSize <= 1)
        return;
    for(int i = 0; i < numsSize - 1; ++i)
    {
        int min = i;
        for(int j = i + 1; j < numsSize; ++j)
        {
            if(nums[j] < nums[min])
            {
                min = j;
            }
        }
        swap(nums, min, i);
    }
}
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = (int*)malloc(sizeof(int) * NUM);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * NUM);

    if(numsSize < 4)
        return res;
    //sort
    select_sort(nums, numsSize);

    for(int i = 0; i <= numsSize - 4; ++i)
    {
        if((nums[i] > target) && (nums[i + 1] >= 0))
            return res;
        if((i > 0) && (nums[i] == nums[i - 1]))
            continue;
        //寻找三个数之和为target - nums[i]
        for(int j = i + 1; j <= numsSize - 3; ++j)
        {
            if((nums[j] > target - nums[i]) && (nums[j + 1] >= 0))
                break;
            if((j > i + 1) && (nums[j] == nums[j - 1]))
                continue; 
            //寻找三个数之和为target - nums[i] - nums[j]
            int left = j + 1;
            int right = numsSize - 1;
            while(left < right)
            {
                if((left > j + 1) && (nums[left] == nums[left - 1]))
                {
                    left++;
                    continue;
                }
                if((right < numsSize - 1) && (nums[right] == nums[right + 1]))
                {
                    right--;
                    continue;
                }
                int sum = nums[left] + nums[right];
                int tmp = target - nums[i] - nums[j];
                if(sum == tmp)
                {
                    res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[(*returnSize)++] = 4;
                    left++;
                    right--;
                }
                else if(sum < tmp)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return res;
}

//function 5， 快速排序
#define NUM 1001
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
    for(; j < b; ++j)
    {
        if(nums[j] < nums[b])
        {
            swap(nums, i++, j);
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
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = (int*)malloc(sizeof(int) * NUM);
    *returnSize = 0;
    int** res = (int**)malloc(sizeof(int*) * NUM);

    if(numsSize < 4)
        return res;
    //sort
    quick_sort(nums, 0, numsSize - 1);

    for(int i = 0; i <= numsSize - 4; ++i)
    {
        if((nums[i] > target) && (nums[i + 1] >= 0))
            return res;
        if((i > 0) && (nums[i] == nums[i - 1]))
            continue;
        //寻找三个数之和为target - nums[i]
        for(int j = i + 1; j <= numsSize - 3; ++j)
        {
            if((nums[j] > target - nums[i]) && (nums[j + 1] >= 0))
                break;
            if((j > i + 1) && (nums[j] == nums[j - 1]))
                continue; 
            //寻找三个数之和为target - nums[i] - nums[j]
            int left = j + 1;
            int right = numsSize - 1;
            while(left < right)
            {
                if((left > j + 1) && (nums[left] == nums[left - 1]))
                {
                    left++;
                    continue;
                }
                if((right < numsSize - 1) && (nums[right] == nums[right + 1]))
                {
                    right--;
                    continue;
                }
                int sum = nums[left] + nums[right];
                int tmp = target - nums[i] - nums[j];
                if(sum == tmp)
                {
                    res[*returnSize] = (int*)malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[(*returnSize)++] = 4;
                    left++;
                    right--;
                }
                else if(sum < tmp)
                {
                    left++;
                }
                else
                {
                    right--;
                }
            }
        }
    }
    return res;
}