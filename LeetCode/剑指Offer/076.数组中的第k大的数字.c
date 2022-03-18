/*
剑指 Offer II 076. 数组中的第 k 大的数字
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
提示：
1 <= k <= nums.length <= 104
-104 <= nums[i] <= 104
*/
void swap(int* heap, int a, int b)
{
    int tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
}
void heapify(int* heap, int a, int n)
{
    while(true)
    {
        int min = a;
        if((2 * a + 1 <= n) && (heap[2 * a + 1] < heap[min]))
            min = 2 * a + 1;
        if((2 * a + 2 <= n) && (heap[2 * a + 2] < heap[min]))
            min = 2 * a + 2;
        if(min == a)
            return;
        swap(heap, min, a);
        a = min;
    }
}
void build_heap(int* heap, int n)
{
    for(int i = (n - 1) / 2; i >= 0; --i)
    {
        heapify(heap, i, n);
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    int n = numsSize - 1;
    build_heap(nums, n);

    while(n > 0)
    {
        swap(nums, 0, n);
        n--;
        //build_heap(nums, n);
        heapify(nums, 0, n);
    }
    return nums[k - 1];
}
