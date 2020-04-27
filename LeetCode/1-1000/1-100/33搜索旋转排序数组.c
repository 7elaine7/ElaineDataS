/*
33. 搜索旋转排序数组
假设按照升序排序的数组在预先未知的某个点上进行了旋转。
( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
你可以假设数组中不存在重复的元素。
你的算法时间复杂度必须是 O(log n) 级别。
示例 1:
输入: nums = [4,5,6,7,0,1,2], target = 0
输出: 4
示例 2:
输入: nums = [4,5,6,7,0,1,2], target = 3
输出: -1
*/
//function 1
int search(int* nums, int numsSize, int target){
    if(NULL == nums || 0 == numsSize)
        return -1;
    int left = 0;
    int right = numsSize - 1;
    if(target < nums[left] && target > nums[right])
        return -1;
    while(left <= right)
    {
        int mid = left + ((right - left) >> 1);
        if(nums[mid] == target)
        {
            return mid;
        }
        if(nums[mid] >= nums[left]) //左边有序(mid = 0的情况要放在此分支处理，例:[3,1] 1)
        {
            if(target >= nums[left] && target < nums[mid])
                right = mid - 1;
            else
                left = mid + 1;
        }
        else    //右边有序 或者数组中只有一个元素
        {
            if(target > nums[mid] && target <= nums[right])
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;    
}

//function 2
int search(int* nums, int numsSize, int target){
    if(0 == numsSize || NULL == nums)
        return -1;
    int left = 0;
    int right = numsSize - 1;
    //left和right没有旋转之前是连在一起的，中间没有值
    while(left <= right)
    {
        if(target < nums[left] && target > nums[right])
            return -1;
        int mid = left + ((right - left) >> 1);
        if(target == nums[mid])
            return mid;
        //target落在左边大的部分
        if(target >= nums[left])
        {
            if(target < nums[mid] || nums[mid] < nums[left])
                right = mid - 1;
            else
                left = mid + 1;
        }
        //target落在右边小的部分
        else if(target <= nums[right])
        {
            if(nums[mid] > nums[right] || nums[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return -1;
}