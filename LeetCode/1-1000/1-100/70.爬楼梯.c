/*
70. 爬楼梯
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
注意：给定 n 是一个正整数。
示例 1：
输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：
输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
*/
//function 1, 递归， 将已经算好的值记录一下
int get_res(int* key, int n)
{
    if(key[n] > 0)
        return key[n];
    key[n] = get_res(key, n - 1) + get_res(key, n - 2);
    return key[n];
}
int climbStairs(int n){
    if(!n)
        return 1;
    if(n <= 2)
        return n;
    int* key = (int*)malloc(sizeof(int) * (n + 1));
    memset(key, 0, sizeof(int) * (n + 1));
    key[0] = 1;
    key[1] = 1;
    key[2] = 2;
    return get_res(key, n);
}

//动态规划
int climbStairs(int n){
    int res;
    if(!n)
        return 1;
    if(n <= 2)
        return n;
    int s1 = 1;
    int s2 = 2;
    for(int i = 3; i <= n; ++i)
    {
        int tmp = s1;
        s1 = s2;
        s2 = tmp + s2;
    }
    return s2;
}