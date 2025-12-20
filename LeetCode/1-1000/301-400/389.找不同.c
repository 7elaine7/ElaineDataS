/*
**************************************************************
    Author：Elsun
    Date：2025-12-20
    Note: Leetcode 389
**************************************************************
389. 找不同
给定两个字符串 s 和 t ，它们只包含小写字母。
字符串 t 由字符串 s 随机重排，然后在随机位置添加一个字母。
请找出在 t 中被添加的字母。
示例 1：
输入：s = "abcd", t = "abcde"
输出："e"
解释：'e' 是那个被添加的字母。
示例 2：
输入：s = "", t = "y"
输出："y"
提示：
0 <= s.length <= 1000
t.length == s.length + 1
s 和 t 只包含小写字母
*/
char findTheDifference(char* s, char* t) {
    int count[26] = {0};
    int len_s = strlen(s);
    int len_t = strlen(t);
    for(int i = 0; i < len_s; i++)
    {
        count[s[i] - 'a']++;
    }
    int j = 0;
    for(; j < len_t; j++)
    {
        count[t[j] - 'a']--;
        if(count[t[j] - 'a'] < 0)
            break;
    }
    return t[j];
}