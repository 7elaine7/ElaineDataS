/*
350. 两个数组的交集 II
给定两个数组，编写一个函数来计算它们的交集。
示例 1:
输入: nums1 = [1,2,2,1], nums2 = [2,2]
输出: [2,2]
示例 2:
输入: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出: [4,9]
说明：
输出结果中每个元素出现的次数，应与元素在两个数组中出现的次数一致。
我们可以不考虑输出结果的顺序。
进阶:
如果给定的数组已经排好序呢？你将如何优化你的算法？
如果 nums1 的大小比 nums2 小很多，哪种方法更优？
如果 nums2 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//function 1, 排序+双指针
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
        if(nums[j] < nums[end])
        {
            swap(nums, i, j);
            ++i;
        }
    }
    swap(nums, i, end);
    return i;
}
void quick_sort(int* nums, int start, int end)
{
    if(start >= end)
        return;
    int q = select_q(nums, start, end);
    quick_sort(nums, start, q - 1);
    quick_sort(nums, q + 1, end);
}
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    *returnSize = 0;
    if(!nums1 || !nums2 || nums1Size == 0 || nums2Size == 0)
        return NULL;
    quick_sort(nums1, 0, nums1Size - 1);
    quick_sort(nums2, 0, nums2Size - 1);

    int size = nums2Size < nums1Size? nums2Size : nums1Size;
    int* res = (int*)malloc(sizeof(int) * size);

    int n1 = 0;
    int n2 = 0;
    while(n2 < nums2Size && n1 < nums1Size)
    {
        if(nums2[n2] < nums1[n1])
        {
            n2++;
        }
        else if(nums2[n2] > nums1[n1])
        {
            n1++;
        }
        else
        {
            res[(*returnSize)++] = nums1[n1];
            n1++;
            n2++;
        }
    }
    return res;
}
//function 2， 哈希
//用数组下标映射哈希导致大数越界无法处理
//用哈希桶可以，但是还要处理冲突，太麻烦
/*
将其中一个数组内的值映射进哈希， 遍历另一个数组，遇到哈希桶中数相同写入结果，哈希桶中相应值计数减1
*/
