/*
22. 括号生成
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。
示例：
输入：n = 3
输出：[
       "((()))",
       "(()())",
       "(())()",
       "()(())",
       "()()()"
     ]
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//最大区域用C(2n)(n)
int calculate(int n)
{
    if(n == 0)
        return 0;
    int result1 = 1;
    int result2 = 1;
    for(int i = 1; i <= n; ++i)
    {
        result1 = result1 * i;
        result2 = result2 * (n + i);
    }
    return result2 / result1;
}
void dfs(char** array, int *count, int left, int right, int n, char* tmp)
{
    if(left == n && right == n)
    {
        array[*count] = (char*)malloc(sizeof(char) * (n * 2 + 1));
        tmp[2 * n] = '\0';
        memcpy(array[*count], tmp, (n * 2 + 1));
        (*count)++;
        return;
    }
    //如果左边还剩，拼左括号
    if(left < n)
    {
        tmp[left + right] = '(';
        dfs(array, count, left+1, right, n, tmp);
    }
    //如果右括号少于左括号
    if(right < left)
    {
        tmp[left + right] = ')';
        dfs(array, count, left, right+1, n, tmp);
    }
}
char ** generateParenthesis(int n, int* returnSize){
    int mal = calculate(n);
    char** array = (char**)malloc(sizeof(char*) * mal);
    char* tmp = (char*)malloc(sizeof(char) * (n * 2 + 1));
    int count = 0;

    dfs(array, &count, 0, 0, n, tmp);
    *returnSize = count;
    return array;
}