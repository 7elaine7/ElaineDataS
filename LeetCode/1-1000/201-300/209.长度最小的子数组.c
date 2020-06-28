/*
209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的连续子数组，并返回其长度。如果不存在符合条件的连续子数组，返回 0。
示例: 
输入: s = 7, nums = [2,3,1,2,4,3]
输出: 2
解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
进阶:
如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
*/
int minSubArrayLen(int s, int* nums, int numsSize){
    if(!nums || numsSize == 0)
        return 0;   
    int left = 0;
    int right = 0;
    int sum = nums[0];
    int res = INT_MAX;
    int count = INT_MAX;
    while(right < numsSize)
    {
        if(sum >= s && left <= right)
        {
            res = sum - s < res - s ? sum : res;
            int tmp = right - left + 1;
            count = tmp < count ? tmp : count;
            sum = sum - nums[left];
            left++;
        }
        else
        {
            right++;
            if(right == numsSize)
                break;
            sum = sum + nums[right];
        }
    }
    if(count == INT_MAX)
        return 0;
    return count;
}

//function 2, 优化
int minSubArrayLen(int s, int* nums, int numsSize){
    if(!nums || numsSize == 0)
        return 0;   
    int count = INT_MAX;
    int left = 0, right = 0;
    int sum = 0;
    while(right < numsSize)
    {
        sum += nums[right];
        while(sum >= s)
        {
            int tmp = right - left + 1;
            count = tmp < count ? tmp : count;
            sum -= nums[left];
            left++;
        }
        right++;
    }
    return count == INT_MAX ? 0 : count;
}

//function 3，前缀和 + 二分法
int b_search(int* nums, int left, int right, int target)
{
    if(nums[right] < target)
        return -1;
    while(left < right)
    {
        int mid = left + (right - left) / 2;
        if(nums[mid] >= target)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}
int minSubArrayLen(int s, int* nums, int numsSize){
    if(!nums || numsSize == 0)
        return 0;   
    int count = INT_MAX;
    //pre记录前缀和，pre[i]代表前i个元素和，递增
    int* pre = (int*)malloc(sizeof(int) * (numsSize + 1));
    //前0个元素和是0
    pre[0] = 0;
    for(int i = 1; i <= numsSize; ++i)
    {
        pre[i] = pre[i - 1] + nums[i - 1];
    }
    //pre[index] - pre[i - 1] >= s;
    for(int i = 1; i <= numsSize; ++i)
    {
        int target = s + pre[i - 1];
        //二分查找大于等于target的index
        int index = b_search(pre, 1, numsSize, target);
        if(index != -1)
        {
            int tmp = index - i + 1;
            count = tmp < count ? tmp : count;
        }
    }
    return count == INT_MAX ? 0 : count;
}