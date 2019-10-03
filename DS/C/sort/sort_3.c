/*****************************************************************************
File name: ElaineDataS/DS/C/sort/sort_3.c
Description: bucket sort, extern quicksort, count sort, radix sort
Author: Elaine Sun
Date: 19-10-02
*****************************************************************************/
#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

extern int select_q(ARRAY_S *array_s, int n1, int n2);
extern void quicksort(ARRAY_S* array_s, int n1, int n2);
extern void dump(ARRAY_S *array);

void Bucket_sort(ARRAY_S *array)
{
    printf("Enter: %s::%s\n", __FILE__, __FUNCTION__);
    int i, num, k;
    int min = array->array[0];
    int max = array->array[0];
    int index = 0;
    for(i = 0; i < array->size; i++)
    {
        if(array->array[i] > max)
            max = array->array[i];
        else if(array->array[i] < min)
            min = array->array[i];
    }
    printf("max: %d, min: %d\n", max, min);

    num = max/10 - min/10 + 1;    //num个桶
    BUCKET *arr = (BUCKET*)malloc(sizeof(BUCKET) * num);
    if(NULL == arr)
    {
        printf("Fail to allocate the memory for struct BUCKET!\n");
        return;
    }

    //平均分配到每个桶里面
    for(i = 0; i < array->size; i++)
    {
        k = array->array[i]/10 - min/10;
        (arr+k)->node[(arr+k)->count] = array->array[i];
        (arr+k)->count++;
    }


    ARRAY_S *p = (ARRAY_S*)malloc(sizeof(ARRAY_S));
    if(NULL == p)
    {
        printf("Fail to allocate the memoryn for struct ARRAY_S!\n");
        return;
    }

    for(k = 0; k < num; k++)
    {
        p->array = (arr+k)->node;
        p->size = (arr+k)->count;

        if((arr+k)->count>0)
        {
            quicksort(p, 0, p->size-1);
            for(i = 0; i < p->size; i++)
            {
                array->array[index] = p->array[i];
                index++;
            }
        }
    }

    if( NULL != arr)
    {
        free(arr);
        arr = NULL;
    }
    if( NULL != p)
    {
        free(p);
        p = NULL;
    }   
}

void Count_sort(ARRAY_S *array_s)
{
    int max = 0;
    int min = 0;
    int i;
    int m;
    printf("Enter: %s::%s\n", __FILE__, __FUNCTION__);
    for(i=0; i<array_s->size; i++)
    {
        if(array_s->array[i] > max)
            max = array_s->array[i];
        else if(array_s->array[i] < min)
            min = array_s->array[i];
    }
    printf("Max: %d, Min: %d\n", max, min);

    int *arr = (int*)calloc((max+1), sizeof(int));    //初始化为0
    if(NULL == arr)
    {
        printf("Fail to allocate the memory!\n");
        return;
    }

    //将数组array中的值依次分布到值对应下标的数组arr中
    for(i = 0; i<array_s->size; i++)
    {
        arr[array_s->array[i]]++;
    }
    //累加求和
    for(i = 0; i<max; i++)
    {
        arr[i+1] = arr[i+1] + arr[i];
    }

    int *tmp = (int*)malloc(sizeof(int)*(array_s->size));
    if(NULL == tmp)
    {
        printf("Fail to allocate the memory!\n");
        return;
    }
    //从后向前遍历，arr[array_s->array[i]]-1就是排序好的数组的下标
    for(i = array_s->size-1; i>=0; i--)
    {
        tmp[arr[array_s->array[i]]-1] = array_s->array[i];
        arr[array_s->array[i]]--;
    }

    memcpy(array_s->array, tmp, sizeof(int)*array_s->size);

    if(NULL != arr)
    {
        free(arr);
        arr = NULL;
    }
    if(NULL != tmp)
    {
        free(tmp);
        tmp = NULL;
    }
}

void Radix_sort(ARRAY_S *array_s)
{
    printf("Enter: %s::%s\n", __FILE__, __FUNCTION__);
    int count[10];
    int i, p, pos;
    int flag = 0;
    int n = 1;
    
    int *tmp1 = (int*)malloc(sizeof(int)*(array_s->size));
    if(NULL == tmp1)
    {
        printf("Fail to allocate the memory!\n");
        return;
    }
    
    int *tmp2 = (int*)malloc(sizeof(int)*(array_s->size));
    if(NULL == tmp2)
    {
        printf("Fail to allocate the memory!\n");
        return;
    }

    while(flag < array_s->size)
    {
        flag = 0;
        memset(count, 0, 10*sizeof(int));

        for(i=0; i<array_s->size; i++)
        {
            p = array_s->array[i] / (int)pow(10, n);
            pos = array_s->array[i] % (int)pow(10, n);
            if(n > 1.0)
            {
                pos = pos / (int)pow(10, n-1);
            }

            tmp1[i] = pos;
            if(p == 0)
                flag++;
            count[pos]++;
        }
        for(i=0; i<9; i++)
        {
            count[i+1] = count[i+1] + count[i];
        }
        
        for(i=array_s->size-1; i>=0; i--)
        {
            tmp2[count[tmp1[i]]-1] = array_s->array[i];
            count[tmp1[i]]--;
        }
        n++;
        memcpy(array_s->array, tmp2, sizeof(int)*array_s->size);  
    }  

    if(NULL != tmp1)
    {
        free(tmp1);
        tmp1 = NULL;
    }
    if(NULL != tmp2)
    {
        free(tmp2);
        tmp2 = NULL;
    }
}

int main(int argv, char *argc[])
{
    ARRAY_S *array_s = (ARRAY_S*)malloc(sizeof(ARRAY_S));
    if(NULL == array_s)
    {
        printf("Fail to allocate the memory!\n");
        return EXIT_FAILURE;
    }

    int array[11] = {7, 17, 9, 59, 27, 31, 52, 40, 66, 16, 0};
    array_s->array = array;
    array_s->size = sizeof(array) / sizeof(array[0]);

    Bucket_sort(array_s);
//    quicksort(array_s, 0, array_s->size - 1);
    dump(array_s);

    int array2[16] = {7, 0, 8, 5, 2, 0, 7, 6, 1, 5, 2, 6, 7, 8, 6, 1};
    array_s->array = array2;
    array_s->size = sizeof(array2) / sizeof(array2[0]);

    Count_sort(array_s);
    dump(array_s);

    int array3[12] = {12345, 77, 111, 0, 1, 789652, 66, 666, 17777, 1, 520, 521};
    array_s->array = array3;
    array_s->size = sizeof(array3) /sizeof(array3[0]);

    Radix_sort(array_s);
    dump(array_s);

    return EXIT_SUCCESS;
}
