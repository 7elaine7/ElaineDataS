/*
15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有满足条件且不重复的三元组。
注意：答案中不可以包含重复的三元组。
示例：
给定数组 nums = [-1, 0, 1, 2, -1, -4]，
满足要求的三元组集合为：
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//快排
void swap(int *array, int a, int b)
{
    int tmp;
    tmp = array[a];
    array[a] = array[b];
    array[b] = tmp;
}

int q_get(int *array, int start, int end)
{
    int i,j;
    i = j = start;
    while(j < end)
    {
        if(array[j] < array[end])
        {
            swap(array, i, j);
            i++;
        }
        j++;    
    }
    swap(array, i, end);
    return i;
}

void quik_sort(int *array, int start, int end)
{
    if(start >= end)
        return;
    int q = q_get(array, start, end);
    quik_sort(array, start, q-1);
    quik_sort(array, q+1, end);
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    quik_sort(nums, 0, numsSize-1);
    printf("numsize = %d\n", numsSize);
    int maxSize = numsSize * 6; //Cn3会溢出
    int** array = (int**)malloc(sizeof(int*) * maxSize);
    if(NULL == array)
        return NULL;

    int count = 0;
    int n = 0;
    while(n <= numsSize - 3)
    {
        int i = n + 1;
        int j = numsSize - 1;
        while(i < j)
        {
            if(nums[i]+nums[j] < -nums[n])
                ++i;
            else if(nums[i]+nums[j] > -nums[n])
                --j;
            else
            {
                array[count] = (int*)malloc(sizeof(int) * 3);
                array[count][0] = nums[n];
                array[count][1] = nums[i];
                array[count][2] = nums[j];
                ++i;
                --j;
                ++count;
                while((i < j) && (nums[i] == nums[i-1]) && (nums[j] == nums[j+1]))
                {
                    ++i;
                    --j;
                }
            }
        }
        ++n;
        while((n <= numsSize - 3) && nums[n] == nums[n-1])
        {
            ++n;
        }
    }

    *returnSize = count;
    *returnColumnSizes = (int*)malloc(sizeof(int) * maxSize);
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return array;
}

