/*
415. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。
注意：
num1 和num2 的长度都小于 5100.
num1 和num2 都只包含数字 0-9.
num1 和num2 都不包含任何前导零。
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式。
*/
char * addStrings(char * num1, char * num2){
    int size1 = strlen(num1);
    int size2 = strlen(num2);
    int size = size1 > size2 ? size1 : size2;
    char* res = (char*)malloc(sizeof(char) * (size + 2));
    int bit = 0;
    int sum = 0;
    for(int i = 1; i <= size; ++i)
    {
        int n1 = size1 - i < 0 ? 0 : num1[size1 - i] - '0';
        int n2 = size2 - i < 0 ? 0 : num2[size2 - i] - '0';
        int tmp = n1 + n2 + bit;
        sum = tmp % 10;
        bit = tmp / 10;
        res[size + 1 - i] = sum + '0';
    }
    if(bit > 0)
    {
        res[0] = bit + '0';
        res[size + 1] = '\0';
    }
    else
    {
        for(int i = 0; i < size; ++i)
        {
            res[i] = res[i + 1];
        }
        res[size] = '\0';
    }
    return res;
}