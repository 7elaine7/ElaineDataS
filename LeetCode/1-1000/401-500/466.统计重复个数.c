/*
466. 统计重复个数
由 n 个连接的字符串 s 组成字符串 S，记作 S = [s,n]。例如，["abc",3]=“abcabcabc”。
如果我们可以从 s2 中删除某些字符使其变为 s1，则称字符串 s1 可以从字符串 s2 获得。
例如，根据定义，"abc" 可以从 “abdbec” 获得，但不能从 “acbbe” 获得。
现在给你两个非空字符串 s1 和 s2（每个最多 100 个字符长）和两个整数 0 ≤ n1 ≤ 106 和 1 ≤ n2 ≤ 106。
现在考虑字符串 S1 和 S2，其中 S1=[s1,n1] 、S2=[s2,n2] 。
请你找出一个可以满足使[S2,M] 从 S1 获得的最大整数 M 。
示例：
输入：
s1 ="acb",n1 = 4
s2 ="ab",n2 = 2
返回：
2
*/
//找循环节
// s1:      |abaacdbac | abaacdbac | abaacdbac | abaacdbac | abaacdbac | abaacdbac
// s2:      |a    d  c    b   d|a         d  c    b   d|a     b  c b          d|
// s2_idx:  |0         |3          |1          |3
// s2_cnt:  |0         |0          |1          |1
//--------------------------------------------------------------------------------
// s1_cnt   |0         |1          |2          |3          |4          |5

typedef struct hashnode{
    int c1;
    int c2;
}HashNode;
int getMaxRepetitions(char * s1, int n1, char * s2, int n2){
    if(0 == n1)
        return 0;
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    HashNode* hash = (HashNode*)malloc(sizeof(HashNode) * size2);
    memset(hash, 0, sizeof(HashNode) * size2);
    int count1 = 0;
    int count2 = 0;
    int index2 = 0;
    int tmp1, tmp2;
    while(count1 <= n1)
    {
        for(int i = 0; i < size1; i++)
        {
            if(s2[index2] == s1[i])
            {
                index2++;
                if(index2 == size2)
                {
                    count2++;
                    index2 = 0;
                }
            }
        }
        count1++;
        //并没有找到循环节
        if(count1 == n1)
        {
            return count2 / n2;
        }
        //如果一遍s1遍历结束，s2的索引对应的哈西值大于0，证明已经出现过，找到循环节
        if(hash[index2].c1 > 0)
        {
            tmp1 = hash[index2].c1;
            tmp2 = hash[index2].c2;
            break;
        }
        else
        {
            hash[index2].c1 = count1;
            hash[index2].c2 = count2;
        }
    }
    //tmp1个s1中有tmp2个s2，每count1-tmp1个s1中包含count2-tmp2个s2
    int result = tmp2 + (n1 - tmp1) / (count1 - tmp1) * (count2 - tmp2);
    //计算后面剩下的s1
    int rest = (n1 - tmp1) % (count1 - tmp1);
    for(int i = 0; i < rest; ++i)
    {
        for(int j = 0; j < size1; ++j)
        {
            if(s1[j] == s2[index2])
            {
                index2++;
                if(index2 == size2)
                {
                    result++;
                    index2 = 0;
                }
            }
        }
    }
    return result / n2;
}