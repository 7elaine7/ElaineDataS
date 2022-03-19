/*
面试题 17.14. 最小K个数
设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。
示例：
输入： arr = [1,3,5,7,2,4,6,8], k = 4
输出： [1,2,3,4]
提示：
0 <= len(arr) <= 100000
0 <= k <= min(100000, len(arr))
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
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
        int max = a;
        if((2 * a + 1 <= n) && (heap[2 * a + 1] > heap[max]))
            max = 2 * a + 1;
        if((2 * a + 2 <= n) && (heap[2 * a + 2] > heap[max]))
            max = 2 * a + 2;
        if(max == a)
            return;
        swap(heap, max, a);
        a = max;
    }
}
void build_heap(int* heap, int n)
{
    for(int i = (n - 1) / 2; i >= 0; --i)
    {
        heapify(heap, i, n);
    }
}
int* smallestK(int* arr, int arrSize, int k, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * k);
    *returnSize = k;
    if(k == 0)
        return res;
    for(int i = 0; i < k; ++i)
    {
        res[i] = arr[i];
    }
    build_heap(res, k - 1);
    for(int i = k; i < arrSize; ++i)
    {
        if(arr[i] < res[0])
        {
            res[0] = arr[i];
            heapify(res, 0, k - 1);
        }        
    }
    return res;

}