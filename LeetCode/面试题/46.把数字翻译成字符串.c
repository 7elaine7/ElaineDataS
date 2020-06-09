/*
面试题46. 把数字翻译成字符串
给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
示例 1:
输入: 12258
输出: 5
解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"
提示：
0 <= num < 231
*/
int translateNum(int num){
    if(num == 0)
        return 1;
    //从后向前数
    int count = 1;  //到当前点为止多少种
    int pre = 1;    //到前一个点为止多少种
    int c_n = num % 10;    //当前位数
    int p_n;               //上一位
    int part = num / 10;
    while(part)
    {
        p_n = c_n;
        c_n = part % 10;    //当前位
        part = part / 10;   //上一位
        //int sum = c_n * 10 + p_n;
        //if(sum >= 10 && sum < 26)
        if((c_n == 1) || (c_n == 2 && p_n < 6))
        {
            int tmp = pre;
            pre = count;
            count = count + tmp;
        }
        else
        {
            pre = count;
        }
    }
    return count;
}