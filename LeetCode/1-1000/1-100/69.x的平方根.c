/*
**************************************************************
    Author：Elsun
    Date：2025-12-18
    Note: Leetcode 69
**************************************************************
69. x 的平方根 
已解答
简单
相关标签
premium lock icon
相关企业
提示
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

示例 1：

输入：x = 4
输出：2
示例 2：

输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。

提示：
0 <= x <= 231 - 1
*/
int mySqrt(int x) {
    if(x <= 1)
        return x;
    int low = 1;
    int high = x / 2;

    long long mid;
    while(low <= high)
    {
        mid = high + (low - high) / 2;
        long long value = mid * mid;

        if(value == x)
            return mid;
        else if(value > x)
        {
            high = mid - 1;
        }
        else if(value < x)
        {
            low = mid + 1;
        }
    }
    return low - 1;
}