/*
32. 最长有效括号
给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
示例 1:
输入: "(()"
输出: 2
解释: 最长有效括号子串为 "()"
示例 2:
输入: ")()())"
输出: 4
解释: 最长有效括号子串为 "()()"
*/
//function 1, 栈
#define MAX(x, y) (x > y ? x : y)
int longestValidParentheses(char * s){
    int size = strlen(s);
    int* stack = (int*)malloc(sizeof(int) * (size + 1));
    int max = 0;
    int top = -1;
    stack[++top] = -1;
    for(int i = 0; i < size; ++i)
    {
        if(s[i] == '(')
        {
            stack[++top] = i;
        }
        else
        {
            --top;  //‘(’出栈
            if(top == -1)   //如果栈空证明‘）‘没有可以匹配的，计数重新开始，栈0的位置记录新的开始
            {
                stack[++top] = i;
            }
            else
            {
                max = MAX(max, i - stack[top]); 
            }
        }
    }
    return max;
}