/*****************************************************************************
File name: ElaineDataS/DS/C/Recursion/climbing.c
Description: 爬楼梯，一次可以迈一个台阶，一次也可以迈两个，求n节台阶的走法
Author: Elaine Sun
Date: 19-09-20
*****************************************************************************/
#include <stdlib.h>
#include <stdio.h>

#define ERR -1

int find(int n, int *map)
{
    if( n == 0)
        return 0;
    if(map[n] != 0 )         //减少重复计算，已经计算过的记录一下
        return map[n];
    
    map[n] = find(n-1, map) + find(n-2, map);
    return map[n];
}

int climb(int n)
{
    int *map = NULL;
    map = (int*)calloc(n+1, sizeof(int));     //每个字节都初始化为0
    if(NULL == map)
    {
        printf("Fail to allocate the memory!\n");
        return ERR;
    }

    map[0] = 0;
    map[1] = 1;
    map[2] = 2;

    int result = find(n, map);
    free(map);

    return result;
}

int main(int argv, char *argc[])
{
    printf("Climb %d stairs have %d ways!\n", 0, climb(0));
    printf("Climb %d stairs have %d ways!\n", 2, climb(2));
    printf("Climb %d stairs have %d ways!\n", 5, climb(5));
    printf("Climb %d stairs have %d ways!\n", 6, climb(6));
    printf("Climb %d stairs have %d ways!\n", 7, climb(7));
    return EXIT_SUCCESS;
}