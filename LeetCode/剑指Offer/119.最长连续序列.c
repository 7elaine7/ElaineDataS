/*
剑指 Offer II 119. 最长连续序列
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
示例 1：
输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：
输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
 
提示：
0 <= nums.length <= 104
-109 <= nums[i] <= 109
进阶：可以设计并实现时间复杂度为 O(n) 的解决方案吗？
*/
//function 1, 快排遍历
int comfunc(const void* a, const void* b)
{
    return *(int*)a < *(int*)b ? -1 : *(int*)a > *(int*)b;
}
int longestConsecutive(int* nums, int numsSize){
    if(NULL == nums || numsSize == 0)
        return 0;
    qsort(nums, numsSize, sizeof(int), comfunc);
    int count = 1;
    int max = 1;
    int tmp = nums[0];
    for(int i = 1; i < numsSize; ++i)
    {
        if(nums[i] == tmp + 1)
        {
            count++;
        }
        else if(nums[i] == tmp)
        {
            continue;
        }
        else
        {
            max = count > max ? count : max;
            count = 1;
        }
        tmp = nums[i];
    }
    return max > count ? max : count;
}

//function 2, 并查集
int comfunc(const void* a, const void* b)
{
    return *(int*)a < *(int*)b ? -1 : *(int*)a > *(int*)b;
}
int find_root(int* parent, int x)
{
    while(x != parent[x])
    {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }
    return x;
}
void Union(int* parent, int* size, int x, int y)
{
    int root_x = find_root(parent, x);
    int root_y = find_root(parent, y);
    if(root_x == root_y)
        return;
    if(size[root_x] > size[root_y])
    {
        parent[root_y] = root_x;
        size[root_x] += size[root_y];
    }
    else
    {
        parent[root_x] = root_y;
        size[root_y] += size[root_x];
    }
}
int longestConsecutive(int* nums, int numsSize){
    if(NULL == nums || numsSize == 0)
        return 0;
    qsort(nums, numsSize, sizeof(int), comfunc);
    int* parent = (int*)malloc(sizeof(int) * numsSize);
    int* size = (int*)malloc(sizeof(int) * numsSize);
    int max = 1;
    for(int i = 0; i < numsSize; ++i)
    {
        parent[i] = i;
        size[i] = 1;
    }
    for(int i = 1, j = 0; i < numsSize && j < numsSize; ++i)
    {
        if(nums[j] == nums[i])
        {
            continue;
        }
        else if(nums[j] + 1 == nums[i])
        {
            Union(parent, size, j, i);
        }
        j = i;
    }
    for(int i = 0; i < numsSize; ++i)
    {
        max = size[i] > max ? size[i] : max; 
    }
    return max;
}
