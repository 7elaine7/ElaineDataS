/*
215. 数组中的第K个最大元素
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
示例 1:
输入: [3,2,1,5,6,4] 和 k = 2
输出: 5
示例 2:
输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
输出: 4
说明:
你可以假设 k 总是有效的，且 1 ≤ k ≤ 数组的长度。
*/

//function 1, 冒泡排序，580ms，太慢
void swap(int* nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
void bubble_sort(int* nums, int size)
{
    for(int i = 1; i < size; ++i)
    {
        int flag = 0;
        for(int j = 0; j < size - i; ++j)
        {
            if(nums[j] < nums[j + 1])
            {
                swap(nums, j, j + 1);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }    
}
int findKthLargest(int* nums, int numsSize, int k){
    bubble_sort(nums, numsSize);
    return nums[k - 1];
}

//function 2, 插入排序，稳定排序，212ms，慢
//插入排序
int findKthLargest(int* nums, int numsSize, int k){
    if(numsSize == 1 && k == 1)
        return nums[0];
    for(int i = 1; i < numsSize; ++i)
    {
        int j = i - 1;
        int tmp = nums[i];
        while((j >= 0) && (nums[j] < tmp))
        {
            nums[j + 1] = nums[j];
            j--;
        }
        nums[j + 1] = tmp;
    }
    return nums[k - 1];
}

//function 3, 选择排序， 非稳定排序， 384ms
//选择排序
int findKthLargest(int* nums, int numsSize, int k){
    int j;
    for(int i = 0; i < numsSize - 1; ++i)
    {
        int max = i;
        for(j = i; j < numsSize; ++j)
        {
            if(nums[j] > nums[max])
            {
                max = j;
            }
        }
        int tmp = nums[i];
        nums[i] = nums[max];
        nums[max] = tmp;
    }                                                                                       
    return nums[k - 1];
}

//function 4, 快排，352ms，慢
//快速排序
void swap(int* nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
int select_q(int* nums, int start, int end)
{
    int i = start;
    for(int j = start; j < end; ++j)
    {
        if(nums[j] > nums[end])
        {
            swap(nums, i, j);
            i++;
        }
    }
    swap(nums, i, end);
    return i;
}
void quik_sort(int* nums, int start, int end)
{
    if(start >= end)
        return;
    int q = select_q(nums, start, end);
    quik_sort(nums, start, q - 1);
    quik_sort(nums, q + 1, end);
}
int findKthLargest(int* nums, int numsSize, int k){
    quik_sort(nums, 0, numsSize - 1);                        
    return nums[k - 1];
}

//function 5, 归并， 24ms，稳定排序
//归并排序
void merge(int*nums, int start, int mid, int end)
{
    int* tmp = (int*)malloc(sizeof(int) * (end - start + 1));
    int n1 = start;
    int n2 = mid + 1;
    int n = 0;
    while((n1 <= mid) && (n2 <= end))
    {
        if(nums[n1] >= nums[n2])
        {
            tmp[n++] = nums[n1++];
        }
        else
        {
            tmp[n++] = nums[n2++];
        }
    }
    if(n1 <= mid)   //n1还有剩余
    {
        memcpy(&(tmp[n]), &(nums[n1]), sizeof(int) * (mid - n1 + 1));
        memcpy(&(nums[start]), tmp, sizeof(int) * (end - start + 1));
    }
    else if(n2 <= end)  //n2还有剩余, 直接把tmp复制给nums就好
    {
        memcpy(&(nums[start]), tmp, sizeof(int) * n);
    }
}
void merge_sort(int* nums, int start, int end)
{
    if(start >= end)
        return;
    int mid = start + (end - start) / 2;
    merge_sort(nums, start, mid);
    merge_sort(nums, mid + 1, end);
    merge(nums, start, mid, end);
}
int findKthLargest(int* nums, int numsSize, int k){
    merge_sort(nums, 0, numsSize - 1);                        
    return nums[k - 1];
}

//function 6, 堆排序，16ms，非稳定排序
//堆排序
void swap(int* nums, int a, int b)
{
    int tmp = nums[a];
    nums[a] = nums[b];
    nums[b] = tmp;
}
void heapify(int* heap, int parent, int size)
{
    int left;
    int right;
    int min;
    while(true)
    {
        min = parent;
        left = parent * 2;
        right = parent * 2 + 1;
        if((left <= size) && (heap[left] < heap[min]))
            min = left;
        if((right <= size) && (heap[right] < heap[min]))
            min = right;
        if(min == parent)
            return;
        swap(heap, min, parent);
        parent = min;
    }
}
void build_heap(int* heap, int size)
{
    for(int i = size / 2; i > 0; --i)
        heapify(heap, i, size);
}
int findKthLargest(int* nums, int numsSize, int k){
    if((numsSize == 1) && (k == 1))
        return nums[0];
    //建一个大小为k的小顶堆，0的位置空出来，root从1开始
    int* heap = (int*)malloc(sizeof(int) * (k + 1));
    for(int i = 0; i < k; ++i)
    {
        heap[i + 1] = nums[i];
    }
    build_heap(heap, k);
    for(int i = k; i < numsSize; ++i)
    {
        if(nums[i] > heap[1])
        {
            heap[1] = nums[i];
            build_heap(heap, k);
        }
    }           
    return heap[1]; 
}

//funtion 7，堆排序，每次排完删掉最顶端，删掉size - k个，非常慢
//堆排序
void swap(int* nums, int x, int y)
{
    int tmp = nums[x];
    nums[x] = nums[y];
    nums[y] = tmp;
}
//堆化，小顶堆
void heapify(int* nums, int size, int parent)
{
    int left;
    int right;
    int min;
    while(true)
    {
        left = parent * 2 + 1;
        right = parent * 2 + 2;
        min = parent;
        if(left < size && nums[left] < nums[min])
            min = left;
        if(right < size && nums[right] < nums[min])
            min = right;
        if(min == parent)
            return;
        swap(nums, parent, min);
        parent = min;
    }
}
//建小顶堆, 从0开始
void build_heap(int* nums, int size)
{
    for(int i = size / 2 - 1; i >= 0; --i)
    {
        heapify(nums, size, i);
    }
}

int findKthLargest(int* nums, int numsSize, int k){
    build_heap(nums, numsSize);
    for(int i = numsSize; i > k; --i)
    {
        swap(nums, 0, i - 1);
        --numsSize;
        build_heap(nums, numsSize);
    }
    return nums[0];
}

