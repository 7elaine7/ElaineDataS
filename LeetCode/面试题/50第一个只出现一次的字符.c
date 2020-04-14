/*
面试题50. 第一个只出现一次的字符
在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。
示例:
s = "abaccdeff"
返回 "b"
s = "" 
返回 " "
限制：
0 <= s 的长度 <= 50000
*/
#define MAX_SIZE 128    //不能有分号
char firstUniqChar(char* s){
    int* hash_array = (int*)malloc(sizeof(int) * MAX_SIZE);
    memset(hash_array, 0, sizeof(int) * MAX_SIZE);
    int len = strlen(s);
    for(int i = 0; i < len; ++i)
    {
        hash_array[s[i]]++;
    }
    char result = ' ';
    for(int i = 0; i < len; ++i)
    {
        if(1 == hash_array[s[i]])
        {
            result = s[i];
            break;
        }
    }
    return result;
}