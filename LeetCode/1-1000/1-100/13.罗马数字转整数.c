/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。

示例 1:
输入: s = "III"
输出: 3
示例 2:
输入: s = "IV"
输出: 4
示例 3:
输入: s = "IX"
输出: 9
示例 4:
输入: s = "LVIII"
输出: 58
解释: L = 50, V= 5, III = 3.
示例 5:
输入: s = "MCMXCIV"
输出: 1994
解释: M = 1000, CM = 900, XC = 90, IV = 4.
 
提示：
1 <= s.length <= 15
s 仅含字符 ('I', 'V', 'X', 'L', 'C', 'D', 'M')
题目数据保证 s 是一个有效的罗马数字，且表示整数在范围 [1, 3999] 内
题目所给测试用例皆符合罗马数字书写规则，不会出现跨位等情况。
IL 和 IM 这样的例子并不符合题目要求，49 应该写作 XLIX，999 应该写作 CMXCIX 。
关于罗马数字的详尽书写规则，可以参考 罗马数字 - 百度百科。
*/
/*
    Author：Elsun
    Date：2025-12-13
*/
//查看是否是罗马数字所包含字母, 返回代表的值
typedef enum{
    I = 1,
    V = 5,
    X = 10,
    L = 50,
    C = 100,
    D = 500,
    M = 1000
}LM;
int checkChar(char x)
{   
    LM num = 0;
    switch(x)
    {
        case 'I':
            num = I;
            break;
        case 'V':
            num = V;
            break;
        case 'X':
            num = X;
            break;
        case 'L':
            num = L;
            break;
        case 'C':
            num = C;
            break;
        case 'D':
            num = D;
            break;
        case 'M':
            num = M;
            break;
        default:
            break;
    }
    return num;
}
//查看是否为六种特殊规则IV IX XL XC CD CM
int checkSpec(int n1, int n2)
{
    LM num = 0;
    switch(n1)
    {
        printf("n1 = %d\n", n1);
        case I:
            if(n2 == V)
                return num = V - I;
            else if(n2 == X)
                return num = X - I;
            break;
        case X:
            if(n2 == L)
                return num = L - X;
            else if(n2 == C)
                return num = C - X;
            break;
        case C:
            if(n2 == D)
                return num = D - C;
            else if(n2 == M)
                return num = M - C;
            break;
        default:
            break;
    }
    return num;
}
int romanToInt(char* s) {
    //长度需在1到15之间
    int len = strlen(s);
    int result = 0;
    if(len < 1 || len > 15)
        return 0;
    printf("len = %d\n", len);
    char *p = s;

    //长度是1，单字母，直接返回结果
    result = checkChar(*p);
    if((len == 1) && result)
    {
        return result;
    }
    int n1 = result;
    int n2, tmp = 0;

    while(*(++p) != '\0')
    {
        if(n2 = checkChar(*p))
        {
            if(n1 >= n2)
            {
                result = result + n2;
            }
            else if((n1 < n2) && (tmp = checkSpec(n1, n2)))
            {
                result = result - n1 + tmp;
            }
            else
                return 0;
            n1 = n2;
        }
        else
            return 0;       
    }
    return result;
}