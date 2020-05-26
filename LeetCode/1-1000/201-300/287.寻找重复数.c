/*
287. 寻找重复数
给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
示例 1:
输入: [1,3,4,2,2]
输出: 2
示例 2:
输入: [3,1,3,4,2]
输出: 3
说明：
不能更改原数组（假设数组是只读的）。
只能使用额外的 O(1) 的空间。
时间复杂度小于 O(n2) 。
数组中只有一个重复的数字，但它可能不止重复出现一次。
*/
//function 1, 二分法
/*
统计数组中比自己小的值的个数count，比target小的值的count一定小于等于自身，比target大的值count一定比自身大
*/
int findDuplicate(int* nums, int numsSize){
    int left = 1;
    int right = numsSize - 1;
    int res = -1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        int count = 0;
        for(int i = 0; i < numsSize; ++i)
        {
            if(nums[i] <= mid)
                count++;
        }
        if(count <= mid)    //在target左边
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
            res = mid;
        }
    }
    return res;
}

//function 2, 二进制
int findDuplicate(int* nums, int numsSize){
    int res = 0;
    int bit_max = 31;
    //求二进制最高位为1的位数
    while((numsSize - 1) >> bit_max == 0)
    {
        bit_max -= 1;
    }
    for(int b = 0; b <= bit_max; ++b)
    {
        int x = 0;  //数组中位为1的个数
        int y = 0;  //1-n中位为1的个数
        for(int i = 0; i < numsSize; ++i)
        {
            //统计数组中的数，当前位为1的个数
            if((nums[i] & (1 << b)) != 0)
                x++;
            //统计1-n中，当前位为1的个数
            if((i & (1 << b)) != 0)
                y++;
        }
        //如果x > y证明target此位为1
        if(x > y)
            res = res | 1 << b;
    }
    return res;
}

//function 3, 快慢指针
int findDuplicate(int* nums, int numsSize){
    //快慢指针，以nums[i]为下一个数的index，有重复的数一定会成环
    int slow = 0;
    int fast = 0;
    //快指针两步，慢指针一步，找相遇点
    do{
        slow = nums[slow];
        fast = nums[nums[fast]];
    }while(slow != fast);
    //找到相遇位置后，慢指针回到起点
    slow = 0;
    //快慢指针同时出发，每次走一步，再次相遇的点为环的入口
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}