/*
**************************************************************
    Author：Elsun
    Date：2025-12-18
    Note: Leetcode 242
**************************************************************
242. 有效的字母异位词
给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
示例 1:
输入: s = "anagram", t = "nagaram"
输出: true
示例 2:
输入: s = "rat", t = "car"
输出: false
提示:
1 <= s.length, t.length <= 5 * 104
s 和 t 仅包含小写字母
进阶: 如果输入字符串包含 unicode 字符怎么办？你能否调整你的解法来应对这种情况？
*/
//function 1
#define NUM 26
bool isAnagram(char* s, char* t) {
    int arr_s[NUM] = {0};
    int arr_t[NUM] = {0};
    int len_s = strlen(s);
    int len_t = strlen(t);
    for(int i = 0; i < len_s; i++)
    {
        arr_s[s[i] - 'a']++;
    }
    for(int j = 0; j < len_t; j++)
    {
        arr_t[t[j] - 'a']++;
    }
    for(int n = 0; n < NUM; n++)
    {
        if(arr_s[n] != arr_t[n])
            return false;
    }
    return true;
}
//function 2
#define NUM 26
bool isAnagram(char* s, char* t) {
    int len_s = strlen(s);
    int len_t = strlen(t);
    if(len_s != len_t)
        return false;
    int arr[NUM] = {0};

    for(int i = 0; i < len_s; i++)
    {
        arr[s[i] - 'a']++;
    }
    for(int j = 0; j < len_t; j++)
    {
        arr[t[j] - 'a']--;
        //如果相同数量肯定是能对得上的，如果对不上肯定会有小于0不够减的
        if(arr[t[j] - 'a'] < 0)
            return false;
    }

    return true;
}