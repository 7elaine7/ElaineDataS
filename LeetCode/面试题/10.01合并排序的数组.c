/*
面试题 10.01. 合并排序的数组
给定两个排序后的数组 A 和 B，其中 A 的末端有足够的缓冲空间容纳 B。 
编写一个方法，将 B 合并入 A 并排序。
初始化 A 和 B 的元素数量分别为 m 和 n。
示例:
输入:
A = [1,2,3,0,0,0], m = 3
B = [2,5,6],       n = 3
输出: [1,2,2,3,5,6]
说明:
A.length == n + m
*/
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    int count1 = m - 1;
    int count2 = n - 1;
    int index = m + n - 1;
    while(count1 >= 0 && count2 >= 0)
    {
        if(A[count1] >= B[count2])
        {
            A[index] = A[count1--];
        }
        else
        {
            A[index] = B[count2--];
        }
        index--;
    }
    while(count1 >= 0)
    {
        A[index--] = A[count1--];
    }
    while(count2 >= 0)
    {
        A[index--] = B[count2--];
    } 
}