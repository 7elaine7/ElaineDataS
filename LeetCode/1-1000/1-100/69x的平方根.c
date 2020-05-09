/*
69. x 的平方根
实现 int sqrt(int x) 函数。
计算并返回 x 的平方根，其中 x 是非负整数。
由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。
示例 1:
输入: 4
输出: 2
示例 2:
输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
*/

//function 1, 二分法
//二分
int mySqrt(int x){
    int left = 0;
    int right = x;
    int res = -1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if((long)mid * mid <= x)
        {
            res = mid;
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return res;
}

//牛顿迭代
/*
C的平方根为方程y = x^2 - C，当y = 0时候的正解，也就是曲线与x轴正区间交点
方程曲线斜率是2xi，切线方程为：f'(xi) = (f(x) - f(xi)) / (x - xi) = 2xi
2xi(x - xi) + xi^2 - C = f(x)
切线与x轴焦点为（1/2 * (C/xi + xi), 0）, 横坐标在我们所求的结果右侧
xi左移，无限趋近结果
每一次迭代后，我们都会距离零点更进一步，所以当相邻两次迭代得到的交点非常接近时，
我们就可以断定，此时的结果已经足够我们得到答案了。
一般来说，可以判断相邻两次迭代的结果的差值是否小于一个极小的非负数ϵ，
其中ϵ 一般可以取 10^{-6}或 10^{-7}
*/

int mySqrt(int x){
    if(0 == x)
        return 0;
    double x0 = x;  //初始值取x0 = x
    double C = x;
    while(true)
    {
        double xi = 0.5 * (C / x0 + x0);
        if(fabs(x0 - xi) < 1e-7) //相邻两次结果足够近，那么已经无限靠近结果
        {
            break;
        }
        x0 = xi;
    }
    return (int)(x0);
}