/*
1248. 统计「优美子数组」
给你一个整数数组 nums 和一个整数 k。
如果某个 连续 子数组中恰好有 k 个奇数数字，我们就认为这个子数组是「优美子数组」。
请返回这个数组中「优美子数组」的数目。
示例 1：
输入：nums = [1,1,2,1,1], k = 3
输出：2
解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
示例 2：
输入：nums = [2,4,6], k = 1
输出：0
解释：数列中不包含任何奇数，所以不存在优美子数组。
示例 3：
输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
输出：16 
提示：
1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/

/*
function 1:
统计出所有的奇数下标，从第一位开始放入新建的odd数组中
例1: [2,2,2,1,2,2,1,2,2,2]，第3和6为奇数，1221包含k=2个奇数，
所以这组数左边可以取[0,3]个数，右边可以取[0,3]个数，那么一共可以取16个
例2: [1, 2, 1, 2, 2, 1, 2], k = 2
奇数下标为0，2，5，加上边界处理，奇数下标数组为odd[-1, 0, 2, 5, 7]
0和2，左侧有(0 - (-1))种，右边有(5 - 2)种，一共1*3 = 3
2和5，左侧有(2 - 0)种，右边有(7 - 5)种，一共2*2 = 4
所以总和是 3 + 4 = 7
*/
int numberOfSubarrays(int* nums, int numsSize, int k){
    //统计奇数下标
    int *odd = (int*)malloc(sizeof(int) * (numsSize + 2));
    int count = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(1 == nums[i] % 2)
        {
            odd[++count] = i;
        }
    }
    odd[0] = -1;
    odd[++count] = numsSize;
    int sum = 0;
    for(int i = 1; i + k <= count; ++i)
    {
        sum = sum + (odd[i] - odd[i - 1]) * (odd[i + k] - odd[i + k - 1]);
    }
    return sum;
}

//function 2
/*
pre：记录到当前结点为止含有奇数的个数
cnt：记录pre为n的个数，当数组为空时，cnt[0]，最开始为1，是{}
例：
arr：1，2，1，2，2，1，2
pre：1，1，2，2，2，3，3
cnt：1，2，3，2
遍历数组，计算[i-k]的和
*/

int numberOfSubarrays(int* nums, int numsSize, int k){
    int *count = (int*)malloc(sizeof(int) * (numsSize + 1));
    memset(count, 0, sizeof(int)*(numsSize + 1));
    count[0] = 1;   //{}
    int pre = 0;
    int sum = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        if(1 == nums[i] % 2)
        {
            pre++;
        }
        sum = sum + (pre - k >= 0 ? count[pre - k] : 0);
        count[pre]++;
    }
    return sum;
}