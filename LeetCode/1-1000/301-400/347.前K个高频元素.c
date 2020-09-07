/*
347. 前 K 个高频元素
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:
输入: nums = [1], k = 1
输出: [1]

提示：
你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。
*/
//function 1, 快排，待改进，参数类型不确定两种函数需合并优化
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//快排
typedef struct node
{
    int value;
    int num;
}Node;
//quik1
void swap(int* nums, int x, int y)
{
    int tmp = nums[x];
    nums[x] = nums[y];
    nums[y] = tmp;
}
int select_q(int* nums, int start, int end)
{
    int i = start;
    for(int j = start; j < end; ++j)
    {
        if(nums[j] > nums[end])
        {
            swap(nums, i, j);
            ++i;
        }
    }
    swap(nums, i, end);
    return i;
}
void quick(int* nums, int start, int end)
{
    if(start >= end)
        return;
    int q = select_q(nums, start, end);
    quick(nums, start, q - 1);
    quick(nums, q + 1, end);
}
//quik2
void swap_s(Node* queue, int x, int y)
{
    Node tmp = queue[x];
    queue[x] = queue[y];
    queue[y] = tmp;
}
int select_q_s(Node* queue, int start, int end)
{
    int i = start;
    for(int j = start; j < end; ++j)
    {
        if(queue[j].num > queue[end].num)
        {
            swap_s(queue, i, j);
            ++i;
        }
    }
    swap_s(queue, i, end);
    return i;
}
void quick_s(Node* queue, int start, int end)
{
    if(start >= end)
        return;
    int q = select_q_s(queue, start, end);
    quick_s(queue, start, q - 1);
    quick_s(queue, q + 1, end);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * k);
    *returnSize = 0;

    quick(nums, 0, numsSize - 1);

    //统计重复个数
    Node* q = (Node*)malloc(sizeof(Node) * numsSize);
    int count = 1;
    int tmp = nums[0];
    int n = 0;
    for(int i = 1; i <= numsSize; ++i)
    {
        if(i == numsSize)
        {
            q[n].value = tmp;
            q[n++].num = count;
            break;
        }
        if(nums[i] == tmp)
        {
            count++;
        }
        else
        {
            q[n].value = tmp;
            q[n++].num = count;
            tmp = nums[i];
            count = 1;
        }
    }

    //次数排序
    quick_s(q, 0, n - 1);

    for(int i = 0; i < k; ++i)
    {
        res[i] = q[i].value;
    }
    *returnSize = k;    

    return res;
}