/*
125. 验证回文串
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:
输入: "race a car"
输出: false
*/
//function 1
bool isPalindrome(char * s){
    int size = strlen(s);
    int start = 0;
    int end = size - 1;
    while(start <= end)
    {
        while(start <= end && !isdigit(s[start]) && !isalpha(s[start]))
        {
            start++;
        }
        while(start <= end && !isdigit(s[end]) && !isalpha(s[end]))
        {
            end--;
        }
        if(start > end)
            return true;
        if(isdigit(s[start]) && isdigit(s[end]) && s[start] == s[end])
        {
            start++;
            end--;
        }
        else if((isalpha(s[start]) && isalpha(s[end])) && ((s[start] - 'a') == (s[end] - 'a') || (s[start] - 'a') == (s[end] - 'A') || (s[start] - 'A') == (s[end] - 'a')))
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

//function 2, 优化
bool isPalindrome(char * s){
    int size = strlen(s);
    int start = 0;
    int end = size - 1;
    while(start <= end)
    {
        //C 库函数 void isalnum(int c) 检查所传的字符是否是字母和数字。
        if(!isalnum(s[start]))
        {
            start++;
            continue;
        }
        if(!isalnum(s[end]))
        {
            end--;
            continue;
        }
        //C 库函数 int tolower(int c) 把给定的字母转换为小写字母。
        //tolower()如果传入的是数字输出的仍是数字
        if(tolower(s[start]) == tolower(s[end]))
        {
            start++;
            end--;
        }
        else
        {
            return false;
        }
    }
    return true;
}
