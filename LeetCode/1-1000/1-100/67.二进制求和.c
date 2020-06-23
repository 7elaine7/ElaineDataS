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