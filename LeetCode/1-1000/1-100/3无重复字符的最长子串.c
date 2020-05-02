/*
3. 无重复字符的最长子串
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

/*
字符串遍历一遍，哈希数组中记录上一次出现这个元素的下标
如果下标比窗口的start小，那么只需要更新哈希下标
如果大于等于start，也就是重复元素在窗口内，此时要将重复元素之前的全部去掉
*/
#define SIZE 128
int lengthOfLongestSubstring(char * s){
    int size = strlen(s);
    int hash_array[SIZE];
    for(int i = 0; i < SIZE; ++i)
    {
        hash_array[i] = -1;
    }
    int max = 0;
    int count = 0;
    int start = 0;
    for(int i = 0; i < size; ++i)
    {
        if(hash_array[s[i]] == -1)
            count++;
        else
        {
            if(hash_array[s[i]] >= start)
            {
                start = hash_array[s[i]] + 1;
                count = i - start + 1;
            }
            else
                count++;            
        }
        hash_array[s[i]] = i;
        if(count > max)
            max = count;
    }
    return max;
}