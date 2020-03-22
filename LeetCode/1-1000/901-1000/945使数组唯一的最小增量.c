/*
945. 使数组唯一的最小增量
给定整数数组 A，每次 move 操作将会选择任意 A[i]，并将其递增 1。
返回使 A 中的每个值都是唯一的最少操作次数。
示例 1:
输入：[1,2,2]
输出：1
解释：经过一次 move 操作，数组将变为 [1, 2, 3]。
示例 2:
输入：[3,2,1,2,1,7]
输出：6
解释：经过 6 次 move 操作，数组将变为 [3, 4, 1, 2, 5, 7]。
可以看出 5 次或 5 次以下的 move 操作是不能让数组的每个值唯一的。
提示：
0 <= A.length <= 40000
0 <= A[i] < 40000
*/
//快排
void swap(int *array, int m, int n)
{
    int tmp;
    tmp = array[m];
    array[m] = array[n];
    array[n] = tmp;
}
int get_q(int *array, int start, int end)
{
    int i,j;
    i = j = start;
    for(; j < end; ++j)
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
void quik_sort(int *array, int start, int end)
{
    if(start >= end)
        return;

    int q = get_q(array, start, end);
    quik_sort(array, start, q-1);
    quik_sort(array, q+1, end);
}

int minIncrementForUnique(int* A, int ASize){
    if(NULL == A || ASize <= 1)
        return 0;
    quik_sort(A, 0, ASize-1);
    int i = 1;
    int count = 0;
    while(i < ASize)
    {
        if(A[i] <= A[i - 1])
        {
            count = count + A[i - 1] + 1 - A[i];
            A[i] = A[i - 1] + 1;
        }
        i++;
    }
    return count;
}
