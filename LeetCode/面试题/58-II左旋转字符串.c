/*
面试题58 - II. 左旋转字符串
字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
比如，输入字符串"abcdefg"和数字2，该函数将返回左旋转两位得到的结果"cdefgab"。
示例 1：
输入: s = "abcdefg", k = 2
输出: "cdefgab"
示例 2：
输入: s = "lrloseumgh", k = 6
输出: "umghlrlose"
*/

//function 1，新建一块内存，拷贝，搬移
char* reverseLeftWords(char* s, int n){
    int size = strlen(s);
    char* tmp = (char*)malloc(sizeof(char) * (size + 1));
    for(int i = 0; i < size; ++i)
    {
        tmp[i] = s[(i + n) % size];
    }
    tmp[size] = '\0';
    return tmp;
}

//function 2, 原地三次翻转
void swap(char* s, int a, int b)
{
    char tmp = s[a];
    s[a] = s[b];
    s[b] = tmp;
}
void reverse(char*s, int start, int end)
{
    while(start < end)
    {
        swap(s, start, end);
        start++;
        end--;
    }
}
char* reverseLeftWords(char* s, int n){
    int size = strlen(s);
    if(NULL == s || 0 == size)
        return s;
    //前n个翻转一下
    reverse(s, 0, n - 1);
    //后面的翻转一下
    reverse(s, n, size - 1);
    //整体翻转一下
    reverse(s, 0, size - 1);
    return s;
}