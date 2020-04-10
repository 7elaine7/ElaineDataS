/*
151. 翻转字符串里的单词
给定一个字符串，逐个翻转字符串中的每个单词。
示例 1：
输入: "the sky is blue"
输出: "blue is sky the"
示例 2：
输入: "  hello world!  "
输出: "world! hello"
解释: 输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
示例 3：
输入: "a good   example"
输出: "example good a"
解释: 如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。 
说明：
无空格字符构成一个单词。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
进阶：
请选用 C 语言的用户尝试使用 O(1) 额外空间复杂度的原地解法。
*/

void reverse(char *s, int start, int end)
{
    if(start == end)
        return;
    int tmp;
    while(start < end)
    {
        tmp = s[start];
        s[start] = s[end];
        s[end] = tmp;
        start++;
        end--;
    }
}
void move(char *s, int *m, int start, int size)
{
    while(s[start] != ' ' && start < size)
    {
        s[*m] = s[start];
        (*m)++;
        start++;
    }
}
char * reverseWords(char * s){
    int size = strlen(s);
    if(NULL == s || 0 == size)
        return s;
    int start = 0;
    int end = size - 1;
    //去掉前面的空格
    while(s[start] == ' ')
    {
        start++;
        if(start == size)
            return "";
    }
    //去掉后面的空格
    while(s[end] == ' ')
    {
        end--;
    }
    //前后翻转
    reverse(s, start, end);
    //逐个单词翻转
    int i = start;
    int m = 0;
    while(i <= end)
    {
        while(s[i] != ' ' && i <= end)
        {
            i++;
        }
        //单个单词翻转
        reverse(s, start, i-1);
        //移动
        move(s, &m, start, size);
        s[m++] = ' ';
        while(s[i] == ' ' && i <= end)
        {
            i++;
        }
        start = i;
    }
    s[m-1] = '\0';
    return s;
}