/*
面试题 16.18. 模式匹配
你有两个字符串，即pattern和value。 pattern字符串由字母"a"和"b"组成，用于描述字符串中的模式。例如，字符串"catcatgocatgo"匹配模式"aabab"（其中"cat"是"a"，"go"是"b"），该字符串也匹配像"a"、"ab"和"b"这样的模式。但需注意"a"和"b"不能同时表示相同的字符串。编写一个方法判断value字符串是否匹配pattern字符串。
示例 1：
输入： pattern = "abba", value = "dogcatcatdog"
输出： true
示例 2：
输入： pattern = "abba", value = "dogcatcatfish"
输出： false
示例 3：
输入： pattern = "aaaa", value = "dogcatcatdog"
输出： false
示例 4：
输入： pattern = "abba", value = "dogdogdogdog"
输出： true
解释： "a"="dogdog",b=""，反之也符合规则
提示：
0 <= len(pattern) <= 1000
0 <= len(value) <= 1000
你可以假设pattern只包含字母"a"和"b"，value仅包含小写字母。
*/
#define SIZE 1001
bool patternMatching(char* pattern, char* value){
    int size_p = strlen(pattern);
    int size_v = strlen(value);
    int count_a = 0;    //a的个数
    int count_b = 0;    //b的个数
    //统计a和b的个数
    for(int i = 0; i < size_p; ++i)
    {
        if(pattern[i] == 'a')
            count_a++;
        else
            count_b++;
    }
    //a的数量小于b时候，a与b互换，否则a为0超时
    if(count_a < count_b)
    {
        int tmp = count_a;
        count_a = count_b;
        count_b = tmp;
        for(int i = 0; i < size_p; ++i)
        {
            if(pattern[i] == 'a')
                pattern[i] = 'b';
            else
                pattern[i] = 'a';
        }
    }
    //如果value是空，只有pattern只包含一个字母或者为空才能匹配
    if(size_v == 0)
        return count_b == 0;
    //如果pattern为空，value不为空，不能匹配
    if(size_p == 0)
        return false;
    //如果都不为空
    //len_a * count_a + len_b * count_b = size_v
    int len_a;
    int len_b;
    for(len_a = 0; count_a * len_a <= size_v; ++len_a)
    {
        int rest = size_v - count_a * len_a;
        if((count_b == 0 && rest == 0) || (count_b != 0 && rest % count_b == 0))
        {
            len_b = (count_b == 0 ? 0 : rest / count_b);
            //存储a，b的value
            char value_a[SIZE];
            char value_b[SIZE];
            char tmp[SIZE];
            value_a[0] = value_b[0] = tmp[0] = '\0';
            int pos = 0;
            bool flag = true;
            for(int i = 0; i < size_p; ++i)
            {
                if(pattern[i] == 'a')
                {
                    for(int j = 0; j < len_a; ++j)
                        tmp[j] = value[j + pos];
                    tmp[len_a] = '\0';
                    if(!strlen(value_a))
                    {
                        strcpy(value_a, tmp);   //value_b第一次存储
                    }
                    else if(strcmp(value_a, tmp))   //后面的取值与存储的value_a不一样，证明不能匹配
                    {
                        //以此a的长度遍历查看是否符合
                        flag = false;
                        break;
                    }
                    pos += len_a;
                }
                else    //是b的情况
                {
                    for(int j = 0; j < len_b; ++j)
                        tmp[j] = value[j + pos];
                    tmp[len_b] = '\0';
                    if(!strlen(value_b))
                    {
                        strcpy(value_b, tmp);   //value_b第一次存储
                    }
                    else if(strcmp(value_b, tmp))   //后面的取值与存储的value_b不一样，证明不能匹配
                    {
                        flag = false;
                        break;
                    }
                    pos += len_b;
                }
            }
            if(flag && value_a != value_b)
                return true;
        }
    }
    return false;
}