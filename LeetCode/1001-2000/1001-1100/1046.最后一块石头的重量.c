/*
1046. 最后一块石头的重量
有一堆石头，每块石头的重量都是正整数。
每一回合，从中选出两块 最重的 石头，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y。那么粉碎的可能结果如下：
如果 x == y，那么两块石头都会被完全粉碎；
如果 x != y，那么重量为 x 的石头将会完全粉碎，而重量为 y 的石头新重量为 y-x。
最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。
示例：

输入：[2,7,4,1,8,1]
输出：1
解释：
先选出 7 和 8，得到 1，所以数组转换为 [2,4,1,1,1]，
再选出 2 和 4，得到 2，所以数组转换为 [2,1,1,1]，
接着是 2 和 1，得到 1，所以数组转换为 [1,1,1]，
最后选出 1 和 1，得到 0，最终数组转换为 [1]，这就是最后剩下那块石头的重量。
提示：
1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/
void swap(int* heap, int x, int y)
{
    int tmp = heap[x];
    heap[x] = heap[y];
    heap[y] = tmp;
}
//从0开始的大顶堆
void heapify(int* heap, int parent, int size)
{
    int max = parent;
    while(true)
    {
        int left = 2 * parent + 1;
        int right = 2 * parent + 2;
        if(left <= size && heap[max] < heap[left])
            max = left;
        if(right <= size && heap[max] < heap[right])
            max = right;
        if(parent == max)
            return;
        swap(heap, parent, max);
        parent = max;
    }          
}
void build_heap(int* heap, int size)
{
    int start = size - 1 / 2;
    for(int i = start; i >= 0; --i)
    {
        heapify(heap, i, size);
    }
}
int lastStoneWeight(int* stones, int stonesSize){
    int i = stonesSize - 1;
    while(i > 0)
    {
        build_heap(stones, i);
        int x = stones[0];
        swap(stones, 0, i);
        build_heap(stones, i - 1);
        int y = stones[0];
        if(x == y)
        {
            swap(stones, 0, i - 1);
            i = i - 2;
        }
        else
        {
            i = i - 1;
            stones[0] = x > y ? x - y : y - x;
        }
    }
    return i == 0 ? stones[0] : 0;
}
