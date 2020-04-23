/*
面试题49. 丑数
我们把只包含因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。
示例:
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  
1 是丑数。
n 不超过1690。
注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/
*/
#define MIN(a,b) (a > b ? b : a)
#define SIZE 1690
int nthUglyNumber(int n){
    if(n == 0)
        return 0;
    int* array = (int*)malloc(sizeof(int) * SIZE);
    array[0] = 1;
    int count = 1;
    int i2 = 0;
    int i3 = 0;
    int i5 = 0;
    while(count < n)
    {
        array[count] = MIN(2*array[i2], MIN(3*array[i3], 5*array[i5]));
        if(array[count] == 2*array[i2])
            i2++;
        if(array[count] == 3*array[i3])
            i3++;
        if(array[count] == 5*array[i5])
            i5++;
        count++;
    }
    return array[n - 1];
}