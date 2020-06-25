/*
139. 单词拆分
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
说明：
拆分时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。
示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。
示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false
*/

bool wordBreak(char * s, char ** wordDict, int wordDictSize){
    if(!s || 0 == wordDictSize || !wordDict)
        return false;
    int size = strlen(s);
    //dp[i]前i个字符是否能匹配
    bool dp[size + 1];
    memset(dp, 0, sizeof(dp));
    //前0个字符，空字符串，可以匹配
    dp[0] = true;
    for(int i = 1; i <= size; ++i)
    {
        for(int j = 0; j < wordDictSize; ++j)
        {
            //从i的位置往前，看是否有单词可以匹配
            int len = strlen(wordDict[j]);
            //从i的位置往前，去掉当前匹配的单词，剩下的长度
            int left = i - len;
            if(left < 0)
                continue;
            if(dp[left] && strncmp(s + left, wordDict[j], len) == 0)
            {
                dp[i] = true;
                break;
            }
        }
    }
    return dp[size];
}