/*
680. 验证回文字符串 Ⅱ
给定一个非空字符串 s，最多删除一个字符。判断是否能成为回文字符串。
示例 1:
输入: "aba"
输出: True
示例 2:
输入: "abca"
输出: True
解释: 你可以删除c字符。
注意:
字符串只包含从 a-z 的小写字母。字符串的最大长度是50000。
*/
bool check(char* s, int left, int right)
{
    while(left < right)
    {
        if(s[left] == s[right])
        {
            ++left;
            --right;
        }
        else
            return false;
    }
    return true;
}
bool validPalindrome(char * s){
    int left = 0;
    int right = strlen(s) - 1;
    while(left < right)
    {
        if(s[left] == s[right])
        {
            ++left;
            --right;
        }
        else
        {
            return check(s, left + 1, right) || check(s, left, right - 1);
        }
    }
    return true;
}