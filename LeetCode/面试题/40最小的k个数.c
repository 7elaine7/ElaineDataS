/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

//大顶堆从1开始存储
void swap(int* arr, int m, int n)
{
    int tmp = arr[m];
    arr[m] = arr[n];
    arr[n] = tmp;
}
void heapify_big(int* arr, int parent, int size)
{
    int left,right,max;
    while(true)
    {
        left = parent * 2;
        right = parent * 2 + 1;
        max = parent;
        if(left <= size && arr[parent] < arr[left])
            max = left;
        if(right <= size && arr[max] < arr[right])
            max = right;
        if(parent == max)
            break;
        swap(arr, max, parent);
        parent = max;
    }
}
void build_big_heap(int* arr, int size)
{
    for(int n = size/2; n > 0; --n)
    {
        heapify_big(arr, n, size);
    }
}

int* getLeastNumbers(int* arr, int arrSize, int k, int* returnSize){
    int* k_arr = (int*)malloc(sizeof(int) * (k+2));
    if(NULL == k_arr)
    {
        printf("Fail to malloc for k_array!\n");
        return NULL;
    }

    int n;
    for(n = 0; n < k; ++n)
    {
        k_arr[n+1] = arr[n];
    }
    build_big_heap(k_arr, k);
    for(; n < arrSize; ++n)
    {
        if(k_arr[1] > arr[n])
        {
            k_arr[1] = arr[n];
            build_big_heap(k_arr, k);
        }
    }

    *returnSize = k;
    k_arr[0] = k_arr[k];

    return k_arr;
}

