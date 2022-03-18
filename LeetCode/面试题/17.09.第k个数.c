/*
面试题 17.09. 第 k 个数
有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。注意，不是必须有这些素因子，而是必须不包含其他的素因子。例如，前几个数按顺序应该是 1，3，5，7，9，15，21。
示例 1:
输入: k = 5
输出: 9
*/
#define MIN(a, b) (a < b ? a : b)

int getKthMagicNumber(int k){
    if(k == 0)
        return 0;
    int* res = (int*)malloc(sizeof(int) * k);
    int count = 0;
    res[0] = 1;
    int p1 = 0;
    int p2 = 0;
    int p3 = 0;
    int r1, r2, r3;

    for(int i = 1; i < k; ++i)
    {
        r1 = res[p1] * 3;
        r2 = res[p2] * 5;
        r3 = res[p3] * 7;
        int tmp = MIN(r1, MIN(r2, r3));
        res[++count] = tmp;
        if(tmp == r1)
            p1++;
        if(tmp == r2)
            p2++;
        if(tmp == r3)
            p3++;
    }
    return res[count];
}