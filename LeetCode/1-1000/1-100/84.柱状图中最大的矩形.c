/*
84. 柱状图中最大的矩形
给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
求在该柱状图中，能够勾勒出来的矩形的最大面积。
以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
示例:
输入: [2,1,5,6,2,3]
输出: 10
*/

//function 1, 暴力解法，超时
#define Max(x, y) (x > y ? x : y)
int largestRectangleArea(int* heights, int heightsSize){
    int max = 0;
    for(int i = 0; i < heightsSize; ++i)
    {
        int count = 1;
        for(int j = i - 1; j >= 0; --j)
        {
            if(heights[j] >= heights[i])
                count++;
            else
                break;
        }
        for(int j = i + 1; j < heightsSize; ++j)
        {
            if(heights[j] >= heights[i])
                count++;
            else
                break;            
        }
        count = count * heights[i];
        max = Max(max, count);
    }
    return max;
}

//function 2,   单调栈
//单调栈
#define Max(x, y) (x > y ? x : y)
int largestRectangleArea(int* heights, int heightsSize){
    //哨兵，前后加0节点
    int* tmp = (int*)malloc(sizeof(int) * (heightsSize + 2));
    tmp[0] = 0;
    tmp[heightsSize + 1] = 0;
    for(int i = 1; i <= heightsSize; ++i)
    {
        tmp[i] = heights[i - 1];
    }
    int* stack = (int*)malloc(sizeof(int) * (heightsSize + 2));
    int top = 0;
    int max = 0;
    int area;
    stack[top] = 0;
    for(int i = 1; i < heightsSize + 2; ++i)
    {
        while(top > 0 && tmp[i] < tmp[stack[top]])
        {
            area = tmp[stack[top]] * (i - stack[top - 1] - 1);
            max = Max(area, max);
            top--;
        }
        stack[++top] = i;
    }
    return max;
}