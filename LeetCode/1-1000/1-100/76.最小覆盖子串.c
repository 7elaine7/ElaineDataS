/*
76. 最小覆盖子串
给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字符的最小子串。
示例：
输入: S = "ADOBECODEBANC", T = "ABC"
输出: "BANC"
说明：
如果 S 中不存这样的子串，则返回空字符串 ""。
如果 S 中存在这样的子串，我们保证它是唯一的答案。
*/
#define SIZE 128
typedef struct pos
{
    int left;
    int right;
}Pos_info;
bool check(int* hash, int* count)
{
    for(int i = 0; i < SIZE; ++i)
    {
        if(hash[i] > count[i])
            return false;
    }
    return true;
}
char * minWindow(char * s, char * t){
    int s1 = strlen(s);
    int s2 = strlen(t);
    if(s1 < s2 || 0 == s || 0 == t)
        return "";
    //将t中字符分别统计进哈希
    int *hash_array = (int*)malloc(sizeof(int) * SIZE);
    memset(hash_array, 0, sizeof(int) * SIZE);
    for(int i = 0; i < s2; ++i)
    {
        hash_array[t[i]]++;
    }

    //统计s中出现t中字符的位置
    int* node = (int*)malloc(sizeof(int) * (s1 + 1));

    //统计每个位置各个字符出现次数和
    int *hash_count = (int*)malloc(sizeof(int) * SIZE);
    memset(hash_count, 0, sizeof(int) * SIZE);

    int count = -1;
    int left = 0; //node中的index
    int right = s1;
    Pos_info min;
    min.left = 0;
    min.right = s1;

    for(int i = 0; i < s1; ++i)
    {
        //如果是t中的字符
        if(hash_array[s[i]] > 0)
        {
            node[++count] = i;
            hash_count[s[i]]++;
            if(check(hash_array, hash_count) == false)
                continue;
            right = count;
            if(node[right] - node[left] + 1 < min.right - min.left + 1)
            {
                min.right = node[right];
                min.left = node[left];
            }
            for(int i = left; i < right; ++i)
            {
                left = i + 1;
                hash_count[s[node[i]]]--;
                if(hash_array[s[node[i]]] > hash_count[s[node[i]]])
                    break;
                if(node[right] - node[left] + 1 < min.right - min.left + 1)
                {
                    min.right = node[right];
                    min.left = node[left];
                }
            }
        }
    }
    if(min.left == 0 && min.right == s1)
        return "";
    int size = min.right - min.left + 1;
    char* res = (char*)malloc(sizeof(char) * (size + 1));
    for(int i = 0; i < size; ++i)
    {
        res[i] = s[min.left + i];
    }
    res[size] = '\0';
    return res;
}