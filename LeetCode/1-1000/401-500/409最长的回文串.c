/*
409. 最长回文串
给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。

注意:
假设字符串的长度不会超过 1010。

示例 1:
输入:
"abccccdd"
输出:
7

解释:
我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
*/
int hash_a(char a)
{
    return a - 'A';
}

int longestPalindrome(char * s){
    int hash_array[60];
    memset(hash_array, 0, sizeof(hash_array));
    char *p = s;
    bool flag = false;
    int count = 0;
    while('\0' != *p)
    {
        hash_array[hash_a(*p)]++;
        p++;
    }
    for(int n = 0; n < sizeof(hash_array)/sizeof(hash_array[0]); ++n)
    {
        if(0 == (hash_array[n] % 2))
        {
            count = count + hash_array[n];
        }
        else
        {
            count = count + hash_array[n] - 1;
            if(false == flag)
            {
                flag = true;
            }            
        }
    }
    if(true == flag)
        count++;
    return count;
}