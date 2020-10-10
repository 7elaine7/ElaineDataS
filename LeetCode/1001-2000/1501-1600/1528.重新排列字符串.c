/*
1528. 重新排列字符串
给你一个字符串 s 和一个 长度相同 的整数数组 indices 。
请你重新排列字符串 s ，其中第 i 个字符需要移动到 indices[i] 指示的位置。
返回重新排列后的字符串。

示例 1：
输入：s = "codeleet", indices = [4,5,6,7,0,2,1,3]
输出："leetcode"
解释：如图所示，"codeleet" 重新排列后变为 "leetcode" 。
示例 2：
输入：s = "abc", indices = [0,1,2]
输出："abc"
解释：重新排列后，每个字符都还留在原来的位置上。
示例 3：
输入：s = "aiohn", indices = [3,1,4,2,0]
输出："nihao"
示例 4：
输入：s = "aaiougrt", indices = [4,0,2,6,7,3,1,5]
输出："arigatou"
示例 5：
输入：s = "art", indices = [1,0,2]
输出："rat" 

提示：

s.length == indices.length == n
1 <= n <= 100
s 仅包含小写英文字母。
0 <= indices[i] < n
indices 的所有的值都是唯一的（也就是说，indices 是整数 0 到 n - 1 形成的一组排列）。
*/
//function 1 冒泡
#define SIZE 100
void swap(int* indices, int x, int y)
{
    int tmp = indices[x];
    indices[x] = indices[y];
    indices[y] = tmp;
}
//冒泡排序
void sort(int* indices, int size)
{
    int flag = false;
    for(int j = 1; j < size; ++j)
    {
        for(int i = 0; i < size - j; ++i)
        {
            if(indices[i] > indices[i + 1])
            {
                swap(indices, i, i + 1);
                flag = true;
            }
        }
        if(flag == false)
            return;
    }
}
char * restoreString(char * s, int* indices, int indicesSize){
    int* hash = (int*)malloc(sizeof(int) * SIZE);
    for(int i = 0; i < indicesSize; ++i)
    {
        hash[indices[i]] = s[i];
    }

    sort(indices, indicesSize);
    for(int i = 0; i < indicesSize; ++i)
    {
        s[i] = hash[indices[i]];
    }
    return s;
}

//function 2， 插入排序
#define SIZE 100
//插入排序
void sort(int* indices, int size)
{
    for(int i = 1; i < size; ++i)
    {
        int tmp = indices[i];
        int j = i - 1;
        for(; j >= 0; --j)
        {
            if(indices[j] > tmp)
            {
                indices[j + 1] = indices[j];
            }
            else               
                break;
        }
        indices[j + 1] = tmp;
    }
}
char * restoreString(char * s, int* indices, int indicesSize){
    int* hash = (int*)malloc(sizeof(int) * SIZE);
    for(int i = 0; i < indicesSize; ++i)
    {
        hash[indices[i]] = s[i];
    }

    sort(indices, indicesSize);
    for(int i = 0; i < indicesSize; ++i)
    {
        s[i] = hash[indices[i]];
    }
    return s;
}

//function 3， 选择排序
#define SIZE 100
//选择排序
void swap(int* indices, int x, int y)
{
    int tmp = indices[x];
    indices[x] = indices[y];
    indices[y] = tmp;
}
void sort(int* indices, int size)
{
    if(size <= 1)
        return;
    for(int i = 0; i < size - 1; ++i)
    {
        int min = i;
        for(int j = i; j < size; ++j)
        {
            min = indices[j] < indices[min] ? j : min;
        }
        swap(indices, i, min);
    }
}
char * restoreString(char * s, int* indices, int indicesSize){
    int* hash = (int*)malloc(sizeof(int) * SIZE);
    for(int i = 0; i < indicesSize; ++i)
    {
        hash[indices[i]] = s[i];
    }

    sort(indices, indicesSize);
    for(int i = 0; i < indicesSize; ++i)
    {
        s[i] = hash[indices[i]];
    }
    return s;
}

//function 4， 快速排序
#define SIZE 100
//快速排序
void swap(int* indices, int x, int y)
{
    int tmp = indices[x];
    indices[x] = indices[y];
    indices[y] = tmp;
}
int select_q(int* indices, int start, int end)
{
    int i = start;
    for(int j = i; j < end; ++j)
    {
        if(indices[j] < indices[end])
        {
            swap(indices, i, j);
            ++i;
        }
    }
    swap(indices, i, end);
    return i;
}
void quick_sort(int* indices, int start, int end)
{
    if(start >= end)
        return;
    int q = select_q(indices, start, end);
    quick_sort(indices, start, q - 1);
    quick_sort(indices, q + 1, end);
}
char * restoreString(char * s, int* indices, int indicesSize){
    int* hash = (int*)malloc(sizeof(int) * SIZE);
    for(int i = 0; i < indicesSize; ++i)
    {
        hash[indices[i]] = s[i];
    }

    quick_sort(indices, 0, indicesSize - 1);
    for(int i = 0; i < indicesSize; ++i)
    {
        s[i] = hash[indices[i]];
    }
    return s;
}