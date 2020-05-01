/*
43. 字符串相乘
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"
示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"
说明：
num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
通过次数58,734提交次数139,333
*/
char * multiply(char * num1, char * num2){
    int size1 = strlen(num1);
    int size2 = strlen(num2);
    char* result = (char*)malloc(sizeof(char) * (size1 + size2 + 1));   //最长的位数可能
    if(num1[0] == '0' || num2[0] == '0')
    {
        result[0] = '0';
        result[1] = '\0';
        return result;
    }
    for(int i = 0; i < size1 + size2; ++i)
    {
        result[i] = '0';
    }
    result[size1 + size2] = '\0';
    for(int i = size2 - 1; i >= 0; --i)
    {
        for(int j = size1 - 1; j >= 0; --j)
        {
            int sum = (num2[i] - '0') * (num1[j] - '0');
            //低位求和
            int sum_tmp = (result[i + j + 1] - '0') + sum % 10;
            result[i + j + 1] = sum_tmp % 10 + '0'; 
            //高位求和
            result[i + j] = (result[i + j] - '0')+ sum / 10 + sum_tmp / 10 + '0';
        }
    }

    if(result[0] == '0')
    {
        int i = 1;
        for(; i < size1 + size2; ++i)
        {
            result[i - 1] = result[i];
        }
        result[i-1] = '\0';
    }
    return result;
}
