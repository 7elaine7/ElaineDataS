/*
42. 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。
示例:
输入: [0,1,0,2,1,0,1,3,2,1,2,1]
输出: 6
*/
int trap(int* height, int heightSize){
    int max = 0;
    int sum = 0;
    for(int i = 0; i < heightSize; ++i)
    {
        if(height[i] > height[max])
        {
            max = i;
        }
    }
    int leftMax = 0;
    int rightMax = heightSize - 1;
    //从左向最高点遍历
    for(int i = 1; i < max; ++i)
    {
        if(height[i] < height[leftMax])
        {
            sum = sum + height[leftMax] - height[i];
        }
        else
        {
            leftMax = i;
        }
    }
    for(int i = heightSize - 2; i > max; --i)
    {
        if(height[i] < height[rightMax])
        {
            sum = sum + height[rightMax] - height[i];
        }
        else
        {
            rightMax = i;
        }
    }
    return sum;
}