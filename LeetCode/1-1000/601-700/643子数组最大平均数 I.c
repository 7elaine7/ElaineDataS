/*
给定 n 个整数，找出平均数最大且长度为 k 的连续子数组，并输出该最大平均数。
示例：
输入：[1,12,-5,-6,50,3], k = 4
输出：12.75
解释：最大平均数 (12-5-6+50)/4 = 51/4 = 12.75 
提示：
1 <= k <= n <= 30,000。
所给数据范围 [-10,000，10,000]。
*/

double findMaxAverage(int* nums, int numsSize, int k){
    int left = 0;
    int right = k - 1;
    double sum = 0.0;
    double max;
    for(int i = left; i <= right; ++i)
    {
        sum = sum + nums[i];
    }
    max = sum / k;

    while(right < numsSize - 1)
    {
        sum = sum - nums[left++] + nums[++right];
        double tmp = sum / k;
        max = max > tmp ? max : tmp;
    }
    return max;
}