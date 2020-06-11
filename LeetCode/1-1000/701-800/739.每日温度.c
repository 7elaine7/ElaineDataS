/*
739. 每日温度
根据每日 气温 列表，请重新生成一个列表，对应位置的输出是需要再等待多久温度才会升高超过该日的天数。
如果之后都不会升高，请在该位置用 0 来代替。
例如，给定一个列表 temperatures = [73, 74, 75, 71, 69, 72, 76, 73]，你的输出应该是 [1, 1, 4, 2, 1, 1, 0, 0]。
提示：气温 列表长度的范围是 [1, 30000]。每个气温的值的均为华氏度，都是在 [30, 100] 范围内的整数。
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//单调栈
int* dailyTemperatures(int* T, int TSize, int* returnSize){
    int* stack = (int*)malloc(sizeof(int) * TSize);
    stack[0] = 0;
    int top = 0;
    for(int i = 1; i < TSize; ++i)
    {
        while(top >= 0 && T[stack[top]] < T[i])
        {
            T[stack[top]] = i - stack[top];
            top--;
        }
        stack[++top] = i;
    }
    while(top >= 0)
    {
        T[stack[top--]] = 0;
    }
    *returnSize = TSize;
    return T;
}