/*
面试题 08.04. 幂集
幂集。编写一种方法，返回某集合的所有子集。集合中不包含重复的元素。
说明：解集不能包含重复的子集。
示例:
 输入： nums = [1,2,3]
 输出：
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//nums中从第一个元素开始，增加包含当前元素的子集，为之前的所有子集，每一个都加上当前元素
//如1之前为[], 1所得为[1], 2之前为[],[1], 2所得为[2][1,2], 3之前为[],[1],[2],[1,2], 3所得为[3],[1,3],[2,3],[1,2,3]
//总子集为：[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]
//计算n个数的子集数（2的n次方个）
int get_subset(int n)
{
    if(n == 0)
        return 0;
    int sum = 1;
    for(int i = 1; i <= n; ++i)
    {
        sum = sum * 2;
    }
    return sum;
}
int** subsets(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if(nums == NULL || numsSize == 0)
    {
        *returnSize = 0;
        *returnColumnSizes = 0;
        return NULL;
    }

    int size = get_subset(numsSize);
    *returnSize = size;
    *returnColumnSizes = (int*)malloc(sizeof(int) * size);
    //分配存储数组
    int** array = (int**)malloc(sizeof(int*) * size);
    for(int i = 0; i < size; ++i)
    {
        array[i] = (int*)malloc(sizeof(int) * numsSize);
    }

    array[0] = NULL;
    (*returnColumnSizes)[0] = 0;
    array[1][0] = nums[0];
    (*returnColumnSizes)[1] = 1;
    int count = 2;
    for(int i = 1; i < numsSize; ++i)
    {
        int tmp = count;
        for(int m = 0; m < tmp; m++)
        {
            int size = (*returnColumnSizes)[m];
            for(int j = 0; j < size; j++)
            {
                array[count][j] = array[m][j];
            }
            array[count][size] = nums[i];
            (*returnColumnSizes)[count++] = size + 1;
        }
    }
    return array;
}