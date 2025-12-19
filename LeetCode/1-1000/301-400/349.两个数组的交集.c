/*
**************************************************************
    Author：Elsun
    Date：2025-12-19
    Note: Leetcode 349
**************************************************************
349. 两个数组的交集
给定两个数组 nums1 和 nums2 ，返回 它们的 交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
示例 1：
输入：nums1 = [1,2,2,1], nums2 = [2,2]
输出：[2]
示例 2：
输入：nums1 = [4,9,5], nums2 = [9,4,9,8,4]
输出：[9,4]
解释：[4,9] 也是可通过的
提示：
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//插入排序之后去重
void InsertSort(int *num, int size);
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int count = 0;
    *returnSize = 0;
    int n = nums1Size <= nums2Size ? nums1Size : nums2Size;
    int *result = (int*)malloc(sizeof(int) * n);
    memset(result, -1, sizeof(int) * n);
    if(NULL != result)
    {
        InsertSort(nums1, nums1Size);
        InsertSort(nums2, nums2Size);
        int i, j = 0;
        while((i < nums1Size) && (j < nums2Size))
        {
            if(nums1[i] < nums2[j])
                i++;
            else if(nums1[i] > nums2[j])
                j++;
            else
            {
                if(count == 0)
                    result[count++] = nums1[i];
                else
                {
                    if(result[count - 1] != nums1[i])
                        result[count++] = nums1[i];
                }
                i++;
                j++;
            }
        }
    }

    result = (int*)realloc(result, sizeof(int) * count);

    *returnSize = count;
    return result;
}
void InsertSort(int *num, int size)
{
    if(size == 1)
        return;
    for(int j = 1; j < size; j++)
    {
        int tmp = num[j];
        int i = j - 1;
        for(; i >= 0; i--)
        {
            if(tmp < num[i])
                num[i + 1] = num[i];
            else
                break;
        }
        num[i + 1] = tmp;
    }
}