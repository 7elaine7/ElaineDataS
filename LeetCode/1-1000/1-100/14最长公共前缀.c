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
//纵向遍历
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
//functinon 2， 二分法， 注意边界的取值
bool isCommonPrefix(char** strs, int size, int len)
{
    for(int i = 1; i < size; ++i)
    {
        if(memcmp(strs[0], strs[i], sizeof(char) * len))
            return false;
    }
    return true;
}
char * longestCommonPrefix(char ** strs, int strsSize){
    if(!strs || !strsSize)
        return "";
    //获取最小值
    int min = strlen(strs[0]);
    for(int i = 1; i < strsSize; ++i)
    {
        min = strlen(strs[i]) < min ? strlen(strs[i]) : min;
    }
    int left = 0;
    int right = min;
    int mid;
    while(left < right)
    {
        mid = left + (right - left + 1) / 2;    //注意边界的取值！
        if(isCommonPrefix(strs, strsSize, mid))
        {
            left = mid;     //注意边界的取值！
        }
        else
        {
            right = mid - 1;    //注意边界的取值！
        }
    }
    char* res = (char*)malloc(sizeof(char) * (left + 1));
    memcpy(res, strs[0], sizeof(char) * left);
    res[left] = '\0';
    return res;
}