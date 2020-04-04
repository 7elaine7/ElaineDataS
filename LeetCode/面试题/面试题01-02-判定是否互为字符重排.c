/*
面试题 01.02. 判定是否互为字符重排
给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
示例 1：
输入: s1 = "abc", s2 = "bca"
输出: true 
示例 2：
输入: s1 = "abc", s2 = "bad"
输出: false
说明：
0 <= len(s1) <= 100
0 <= len(s2) <= 100
*/
bool CheckPermutation(char* s1, char* s2){
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    if(size1 != size2)
        return false;
    int *hash_count = (int*)malloc(sizeof(int) * 128);
    memset(hash_count, 0, sizeof(int) * 128);
    for(int i = 0; i < size1; ++i)
    {
        hash_count[s1[i]]++;
    }
    for(int i = 0; i < size2; ++i)
    {
        if(0 == hash_count[s2[i]])
            return false;
        else
            hash_count[s2[i]]--;
    }
    return true;
}