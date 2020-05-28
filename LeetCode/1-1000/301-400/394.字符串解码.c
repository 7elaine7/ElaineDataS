/*
394. 字符串解码
给定一个经过编码的字符串，返回它解码后的字符串。
编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
示例:
s = "3[a]2[bc]", 返回 "aaabcbc".
s = "3[a2[c]]", 返回 "accaccacc".
s = "2[abc]3[cd]ef", 返回 "abcabccdcdcdef".
*/
#define S_SIZE 100
char * decodeString(char * s){
    int len = strlen(s);
    char* tmp = (char*)malloc(sizeof(char) * S_SIZE);
    char* res = (char*)malloc(sizeof(char) * S_SIZE);
    int top_t = -1;
    int size_t = S_SIZE;
    int top_r = -1;
    int size_r = S_SIZE;
    for(int i = 0; i < len; ++i)
    {
        if(s[i] == ']')
        {
            while(res[top_r] != '[')
            {
                //tmp容量不够用，扩容
                if(top_t == size_t - 2)
                {
                    size_t = size_t + S_SIZE;
                    tmp = (char*)realloc(tmp, sizeof(char) * size_t);
                }
                tmp[++top_t] = res[top_r--];
            }
            top_r = top_r - 1;
            //计算数字位
            int sum = 0;
            int n = 0;
            while(top_r >= 0 && isdigit(res[top_r]))
            {
                sum += (res[top_r--] - '0') * (pow(10, n++));
            }
            //将tmp中的字符复制n遍到res中
            for(int c = 1; c <= sum; ++c)
            {
                for(int j = top_t; j >= 0; --j)
                {
                    //res容量不够用，扩容
                    if(top_r == size_r - 2)
                    {
                        size_r = size_r + S_SIZE;
                        res = (char*)realloc(res, sizeof(char) * size_r);
                    }
                    res[++top_r] = tmp[j];
                }
            }
            top_t = -1;
        }
        else
        {
            //res容量不够用，扩容
            if(top_r == size_r - 2)
            {
                size_r = size_r + S_SIZE;
                res = (char*)realloc(res, sizeof(char) * size_r);
            }
            res[++top_r] = s[i];
        }
    }
    res[top_r + 1] = '\0';
    return res;
}