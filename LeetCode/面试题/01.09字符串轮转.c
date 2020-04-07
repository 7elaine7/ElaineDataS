/*
面试题 01.09. 字符串轮转
字符串轮转。给定两个字符串s1和s2，请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
示例1:
 输入：s1 = "waterbottle", s2 = "erbottlewat"
 输出：True
示例2:
 输入：s1 = "aa", "aba"
 输出：False
提示：
字符串长度在[0, 100000]范围内。
说明:
你能只调用一次检查子串的方法吗？
*/
bool isFlipedString(char* s1, char* s2){
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    if(0 == size1 && 0 == size2)
        return true;
    if(size1 != size2)
        return false;
    int n1,n2;
    bool flag = false;
    for(int i = 0; i < size1; ++i)
    {
        if(s1[i] == s2[0])
        {
            flag = true;
            n1 = i;
            n2 = 0;
            for(; n2 < size2; ++n2)
            {
                if(s1[n1] != s2[n2])
                {
                    flag = false;
                    break;
                }
                ++n1;
                if(n1 == size1)
                    n1 = 0;
            }
            if(true == flag)
                return flag;
        }
    }
    return flag;
}