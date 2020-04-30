/*
567. 字符串的排列
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的排列。
换句话说，第一个字符串的排列之一是第二个字符串的子串。
示例1:
输入: s1 = "ab" s2 = "eidbaooo"
输出: True
解释: s2 包含 s1 的排列之一 ("ba").
示例2:
输入: s1= "ab" s2 = "eidboaoo"
输出: False
注意：
输入的字符串只包含小写字母
两个字符串的长度都在 [1, 10,000] 之间
*/
#define SIZE 26
bool checkInclusion(char * s1, char * s2){
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    if(0 == size1)
        return true;
    if(size1 > size2)
        return false;    
    int hash_array[SIZE];
    int hash_count[SIZE];
    memset(hash_array, 0, sizeof(int) * SIZE);
    memset(hash_count, 0, sizeof(int) * SIZE);

    for(int i = 0; i < size1; ++i)
    {
        hash_array[s1[i] - 'a']++;
        hash_count[s1[i] - 'a']++;
    }
    for(int i = 0; i <= size2 - size1; ++i)
    {
        int tmp = i;
        int num = 0;
        while(hash_count[s2[tmp] - 'a'] != 0)
        {
            num++;
            hash_count[s2[tmp] - 'a']--;
            if(num == size1)
                return true;
            tmp++;
        }
        memcpy(hash_count, hash_array, sizeof(int)*SIZE);
    }
    return false;
}