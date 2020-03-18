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

//二分法
#define max(a,b) ((a)>(b)?(a):(b));
#define min(a,b) ((a)<(b)?(a):(b));

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    double result;
    if(nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    int left = 0;
    int right = nums1Size;
    int k = (nums1Size + nums2Size + 1) / 2;
    int m1, m2;
    while(left < right)
    {
        m1 = left + ((right - left) >> 1);
        m2 = k - m1;
        if(nums1[m1] < nums2[m2 - 1])
            left = m1 + 1;
        else
            right = m1;
    }
    m1 = left;
    m2 = k - m1;
    double r1 = (double)max((m1 <= 0 ? INT_MIN:nums1[m1-1]) , (m2 <= 0 ? INT_MIN:nums2[m2-1]));

    if(1 == (nums1Size + nums2Size) % 2) 
        return r1;  
    double r2 = (double)min((m1 >= nums1Size? INT_MAX:nums1[m1]) , (m2 >= nums2Size? INT_MAX:nums2[m2]));
        return (double)(r1 + r2) / 2.0;
}