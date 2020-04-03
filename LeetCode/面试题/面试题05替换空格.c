/*
面试题05. 替换空格
请实现一个函数，把字符串 s 中的每个空格替换成"%20"。
示例 1：
输入：s = "We are happy."
输出："We%20are%20happy."
限制：
0 <= s 的长度 <= 10000
*/
char* replaceSpace(char* s){
    if(NULL == s)
        return s;
    int size = strlen(s);
    char *array = (char*)malloc(sizeof(char) * (size * 3 + 1));
    int m = 0;
    int n = 0;
    while(m < size)
    {
        if(' ' == s[m])
        {
            array[n++] = '%';
            array[n++] = '2';
            array[n++] = '0';
            ++m;
        }
        else
        {
            array[n++] = s[m++];
        }
    }
    array[n] = '\0';
    return array;
}