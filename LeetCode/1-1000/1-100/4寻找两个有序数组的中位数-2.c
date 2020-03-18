/*
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。

请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。

你可以假设 nums1 和 nums2 不会同时为空。

示例 1:

nums1 = [1, 3]
nums2 = [2]

则中位数是 2.0
示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

则中位数是 (2 + 3)/2 = 2.5
*/

//堆
void swap(int* array, int m, int n)
{
    int tmp = array[m];
    array[m] = array[n];
    array[n] = tmp;
}
//大顶堆, 从1开始存储
void heapify_big(int* array, int parent, int size){
    int left, right, max;
    while(true)
    {
        left = parent * 2;
        right = left + 1;
        max = parent;
        if(left <= size && array[parent] < array[left])
            max = left;
        if(right <= size && array[max] < array[right])
            max = right;
        if(max == parent)
            break;
        swap(array, parent, max);
        parent = max;
    }
}
void build_big(int* array, int size){
    for(int m = size / 2; m > 0; m-- )
        heapify_big(array, m, size);
}

//小顶堆, 从1开始存储
void heapify_small(int* array, int parent, int size){
    int left, right, min;
    while(true)
    {
        left = parent * 2;
        right = left + 1;
        min = parent;
        if(left <= size && array[parent] > array[left])
            min = left;
        if(right <= size && array[min] > array[right])
            min = right;
        if(min == parent)
            break;
        swap(array, parent, min);
        parent = min;
    }
}
void build_small(int* array, int size){
    for(int m = size / 2; m > 0; m-- )
        heapify_small(array, m, size);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double result;
    int max;
    if(nums1Size >= nums2Size)
        max = nums1Size;
    else
        max = nums2Size;
    int* array1 = (int*)malloc(sizeof(int) * (max + 2));
    if(NULL == array1)
        printf("Fail to malloc for array1!\n");
    int* array2 = (int*)malloc(sizeof(int) * (max + 2));
    if(NULL == array2)
        printf("Fail to malloc for array2!\n");

    int m = 0;
    for(; m < nums1Size/2; ++m)
    {
        array1[m+1] = nums1[m];
    }
    int count1 = m; //从1开始存储
    for(; m < nums1Size; ++m)
    {
        array2[m - count1 + 1] = nums1[m];
    }
    int count2 = m - count1; //从1开始存储

    build_big(array1, count1);
    build_small(array2, count2);

    int size = count1 + count2;
    for(m = 0; m < nums2Size; ++m)
    {
        if(nums2[m] <= array1[1] )
        {
            count1 ++;
            array1[count1] = nums2[m];
        }
        else if(nums2[m] >= array2[1])
        {
            count2 ++;
            array2[count2] = nums2[m];
        }
        else
        {
            count2 ++;
            array2[count2] = nums2[m];
            build_small(array2, count2);
        }
        size++;
        if((0 == (size % 2)) && (count1 != size/2))
        {
            array1[count1 + 1] = array2[1];
            array2[1] = array2[count2];
            count1++;
            count2--;
        }
        if((1 == (size % 2)) && (count1 != size/2))
        {
            array2[count2 + 1] = array1[1];
            array1[1] = array1[count1];
            count2++;
            count1--;
        }
        build_big(array1, count1);
        build_small(array2, count2);
    }
    if(0 == (size % 2))
        result = (double)(array1[1] + array2[1]) / 2;
    else
        result = (double)array2[1];

    return result;
}

