/*
56. 合并区间
给出一个区间的集合，请合并所有重叠的区间。
示例 1:
输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:
输入: [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
//function 1, 快排非原地排序，需要注意[[1,4],[1,5]]的情况
void swap(int** intervals, int m, int n)
{
    for(int i = 0; i < 2; ++i)
    {
        int tmp = intervals[m][i];
        intervals[m][i] = intervals[n][i];
        intervals[n][i] = tmp;
    }
}
int get_q(int** intervals, int start, int end)
{
    int i = start;
    int j = i;
    for(; j < end; ++j)
    {
        if(intervals[j][0] < intervals[end][0])
        {
            swap(intervals, i, j);
            ++i;
        }
    }
    swap(intervals, i, end);
    return i;
}
void quik_sort(int** intervals, int start, int end)
{
    if(start >= end)
        return;
    int q = get_q(intervals, start, end);
    quik_sort(intervals, start, q-1);
    quik_sort(intervals, q+1, end);
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    * returnColumnSizes=intervalsColSize;
    if(NULL == intervals || 0 == intervalsSize || 0 == *intervalsColSize)
    {
        *returnSize = 0;
        return intervals;
    }
    int** array = (int**)malloc(sizeof(int*) * intervalsSize);
    for(int i = 0; i < intervalsSize; ++i)
    {
        array[i] = (int*)malloc(sizeof(int) * 2);
    }
    quik_sort(intervals, 0, intervalsSize - 1);

    //构建临时栈
    int* tmp_stack = (int*)malloc(sizeof(int) * 2 * intervalsSize);
    tmp_stack[0] = intervals[0][0];
    tmp_stack[1] = intervals[0][1];
    int top = 1;    //指向栈定元素
    for(int i = 1; i < intervalsSize; ++i)
    {
        //快排非原地排序
        if(tmp_stack[top - 1] == intervals[i][0])
        {
            if(tmp_stack[top] < intervals[i][1])
            {
                tmp_stack[top] = intervals[i][1];
            }
            continue;
        }
        if(tmp_stack[top] >= intervals[i][0] && (tmp_stack[top] < intervals[i][1]))
        {
            tmp_stack[top] = intervals[i][1];
        }
        else if(tmp_stack[top] < intervals[i][0])
        {
            tmp_stack[++top] = intervals[i][0];
            tmp_stack[++top] = intervals[i][1];
        }
    }
    int count = 0;
    int i = 0;
    while(i <= top)
    {
        array[count][0] = tmp_stack[i];
        array[count++][1] = tmp_stack[++i];
        i++;
    }
    *returnSize = count;
    return array;  
}

//function 2, 插入排序，原地算法，很慢
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
void insert_sort(int** intervals, int size)
{
    int i, j;
    for(i = 1; i < size; ++i)
    {
        int value0 = intervals[i][0];
        int value1 = intervals[i][1];
        for(j = i - 1; j >= 0; --j)
        {
            if(intervals[j][0] > value0)
            {
                intervals[j+1][0] = intervals[j][0];
                intervals[j+1][1] = intervals[j][1];
            }
            else
                break;
        }
        intervals[j+1][0] = value0;
        intervals[j+1][1] = value1;
    }
}
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    * returnColumnSizes=intervalsColSize;
    if(NULL == intervals || 0 == intervalsSize || 0 == *intervalsColSize)
    {
        *returnSize = 0;
        return intervals;
    }
    int** array = (int**)malloc(sizeof(int*) * intervalsSize);
    for(int i = 0; i < intervalsSize; ++i)
    {
        array[i] = (int*)malloc(sizeof(int) * 2);
    }
    insert_sort(intervals, intervalsSize);

    //构建临时栈
    int* tmp_stack = (int*)malloc(sizeof(int) * 2 * intervalsSize);
    tmp_stack[0] = intervals[0][0];
    tmp_stack[1] = intervals[0][1];
    int top = 1;    //指向栈定元素
    for(int i = 1; i < intervalsSize; ++i)
    {
        if(tmp_stack[top] >= intervals[i][0] && (tmp_stack[top] < intervals[i][1]))
        {
            tmp_stack[top] = intervals[i][1];
        }
        else if(tmp_stack[top] < intervals[i][0])
        {
            tmp_stack[++top] = intervals[i][0];
            tmp_stack[++top] = intervals[i][1];
        }
    }
    int count = 0;
    int i = 0;
    while(i <= top)
    {
        array[count][0] = tmp_stack[i];
        array[count++][1] = tmp_stack[++i];
        i++;
    }
    *returnSize = count;
    return array;  
}
