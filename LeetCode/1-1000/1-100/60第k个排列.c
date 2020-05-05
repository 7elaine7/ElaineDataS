/*
60. 第k个排列
给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
"123"
"132"
"213"
"231"
"312"
"321"
给定 n 和 k，返回第 k 个排列。
说明：
给定 n 的范围是 [1, 9]。
给定 k 的范围是[1,  n!]。
示例 1:
输入: n = 3, k = 3
输出: "213"
示例 2:
输入: n = 4, k = 9
输出: "2314"
*/

char * getPermutation(int n, int k){
    int* factorial = (int*)malloc(sizeof(int) * (n + 1));
    factorial[0] = 0;
    factorial[1] = 1;
    for(int i = 2; i <= n; ++i)
    {
        factorial[i] = factorial[i - 1] * i;
    }
    int hash[10];
    memset(hash, 0, sizeof(int) * 10);

    char* res = (char*)malloc(sizeof(char) * (n + 1));
    res[n] = '\0';
    for(int i = 1; i < n; ++i)
    {
        int tmp = (k - 1) / factorial[n - i] + 1;
        int count = 0;
        for(int i = 1; i <= n; i++)
        {
            if(hash[i] == 0)
                count++;
            if(count == tmp)
            {
                tmp = i;
                break;
            }
        }
        res[i - 1] = tmp + '0';
        hash[tmp] = 1;
        tmp = k % factorial[n - i];
        if(tmp == 0)
            k = factorial[n - i];
        else
            k = tmp;
    }
    int i = 1;
    while(hash[i] == 1)
        i++;
    res[n - 1] = i + '0';
    return res;
}