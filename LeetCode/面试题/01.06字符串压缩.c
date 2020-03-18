/*
字符串压缩。利用字符重复出现的次数，编写一种方法，实现基本的字符串压缩功能。比如，字符串aabcccccaaa会变为a2b1c5a3。
若“压缩”后的字符串没有变短，则返回原先的字符串。你可以假设字符串中只包含大小写英文字母（a至z）。

示例1:

 输入："aabcccccaaa"
 输出："a2b1c5a3"
示例2:

 输入："abbccd"
 输出："abbccd"
 解释："abbccd"压缩后为"a1b2c2d1"，比原字符串长度更长。
 */
char* compressString(char* S){

    int size = strlen(S);
    char* tmp = (char*)malloc(sizeof(char) * (size*2 + 1));
    if(size <= 1)
        return S;
    int count = 1;
    int index = 0;

    for(int m = 0; m < size; ++m)
    {
        if(S[m] == S[m+1])
        {
            count++;
        }
        else
        {
            tmp[index] = S[m];
            int num = (int)log10(count)+1;//count是几位数
            for(int tnum = num;tnum > 0;tnum--)
            {
                tmp[index + tnum] = count % 10 + '0';
                count = count / 10;
            }             
            index = index + num + 1;
            count = 1;
        }
    }

    tmp[index] = '\0';

    if(index >= size)
        return S;
    else
        return tmp;   
}