/*
67. 二进制求和
给你两个二进制字符串，返回它们的和（用二进制表示）。
输入为 非空 字符串且只包含数字 1 和 0。
示例 1:
输入: a = "11", b = "1"
输出: "100"
示例 2:
输入: a = "1010", b = "1011"
输出: "10101"
提示：
每个字符串仅由字符 '0' 或 '1' 组成。
1 <= a.length, b.length <= 10^4
字符串如果不是 "0" ，就都不含前导零。
*/

//function 1
char * addBinary(char * a, char * b){
    int size1 = strlen(a);
    int size2 = strlen(b);
    int size = size1 > size2 ? size1 : size2;
    char* stack = (char*)malloc(sizeof(char) * (size + 2));
    int top = -1;
    int bit = 0;    //进位
    int i = size1 - 1;
    int j = size2 - 1;
    while(i >= 0 || j >= 0)
    {
        int sum = (i < 0 ? 0 : a[i] - '0') + (j < 0 ? 0 : b[j] - '0') + bit;
        if(sum == 0)
        {
            stack[++top] = 0 + '0';
            bit = 0;
        }
        else if(sum == 1)
        {
            stack[++top] = 1 + '0';
            bit = 0;            
        }
        else if(sum == 2)
        {
            stack[++top] = 0 + '0';
            bit = 1;
        }
        else    //sum == 3
        {
            stack[++top] = 1 + '0';
            bit = 1;
        }
        i--;
        j--;          
    }
    if(bit == 1)
        stack[++top] = 1 + '0';

    char* res = (char*)malloc(sizeof(char) * (top + 2));
    res[top + 1] = '\0';
    for(int i = 0; top >= 0; ++i)
    {
        res[i] = stack[top--];
    }
    return res;
}

//function 2, 优化
char * addBinary(char * a, char * b){
    int size1 = strlen(a);
    int size2 = strlen(b);
    int size = size1 > size2 ? size1 : size2;
    char* stack = (char*)malloc(sizeof(char) * (size + 2));
    int top = -1;
    int bit = 0;    //进位
    int i = size1 - 1;
    int j = size2 - 1;
    while(i >= 0 || j >= 0)
    {
        int sum = (i < 0 ? 0 : a[i] - '0') + (j < 0 ? 0 : b[j] - '0') + bit;
        stack[++top] = sum % 2 + '0';
        bit = sum / 2;
        i--;
        j--;          
    }
    if(bit == 1)
        stack[++top] = 1 + '0';

    char* res = (char*)malloc(sizeof(char) * (top + 2));
    res[top + 1] = '\0';
    for(int i = 0; top >= 0; ++i)
    {
        res[i] = stack[top--];
    }
    return res;
}

//funtion 3， 位运算
/*
我们可以设计这样的算法来计算：
    把 aa 和 bb 转换成整型数字 xx 和 yy，在接下来的过程中，xx 保存结果，yy 保存进位。
    当进位不为 00 时
        计算当前 xx 和 yy 的无进位相加结果：answer = x ^ y
        计算当前 xx 和 yy 的进位：carry = (x & y) << 1
        完成本次循环，更新 x = answer，y = carry
    返回 xx 的二进制形式
为什么这个方法是可行的呢？在第一轮计算中，answer 的最后一位是 xx 和 yy 相加之后的结果，
carry 的倒数第二位是 xx 和 yy 最后一位相加的进位。
接着每一轮中，由于 carry 是由 xx 和 yy 按位与并且左移得到的，那么最后会补零，所以在下面计算的过程中后面的数位不受影响，
而每一轮都可以得到一个低 ii 位的答案和它向低 i + 1i+1 位的进位，也就模拟了加法的过程。
*/