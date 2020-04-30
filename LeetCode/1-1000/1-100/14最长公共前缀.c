/*
14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1:
输入: ["flower","flow","flight"]
输出: "fl"
示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:
所有输入只包含小写字母 a-z 。
*/
char * longestCommonPrefix(char ** strs, int strsSize){
    if(0 == strsSize || NULL == *strs)
        return "";
    if(1 == strsSize)
        return strs[0];
    int min = strlen(strs[0]);
    for(int i = 1; i < strsSize; ++i)
    {
        if(strlen(strs[i]) < min)
            min = strlen(strs[i]);
    }
    char* array = (char*)malloc(sizeof(char) * (min + 1));
    int count = 0;
    for(int i = 0; i < min; ++i)
    {
        for(int j = 1; j < strsSize; ++j)
        {
            if(strs[0][i] != strs[j][i])
            {
                array[count] = '\0';
                return array;
            }
        }
        array[count++] = strs[0][i];
    }
    array[count] = '\0';
    return array;
}