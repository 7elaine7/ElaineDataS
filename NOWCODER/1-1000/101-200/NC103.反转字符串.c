/*
NC103 反转字符串
描述
写出一个程序，接受一个字符串，然后输出该字符串反转后的字符串。（字符串长度不超过1000）

数据范围： 
要求：空间复杂度 ，时间复杂度 
示例1
输入："abcd"
返回值："dcba"

示例2
输入：""
返回值：""
*/
/**
 * 反转字符串
 * @param str string字符串 
 * @return string字符串
 */
char* solve(char* str ) {
    // write code here
    int len = strlen(str);
    char* start = str;
    char* end = str + len - 1;
    while(start < end)
    {
        char tmp = *start;
        *start = *end;
        *end = tmp;
        start++;
        end--;
    }
    return str;
}
