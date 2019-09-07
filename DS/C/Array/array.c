/*****************************************************************************
File name: ElaineDataS/DS/C/Array/array.c
Description: array common function
Author: Elaine Sun
Version: 
Date: 
History: 
*****************************************************************************/

#include "array.h"

#include <string.h>
#include <stdbool.h>

//dump every value in array
void dump(Array *array)
{
    int i;
    for(i = 0; i < array->len; i++)
        printf("[%02d]: %08d\n", i, array->p[i]);
}

//allocation 
int alloc(Array *array)
{
    array->p = malloc(array->size * sizeof(int));
    if(NULL == array->p)
    {
        printf("fail to get memory!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int relloc(Array *array, int num)
{
    array->size = array->size + num;
    array->p = realloc(array->p, array->size * sizeof(int));
    if(NULL == array->p)
    {
        printf("fail to re-get memory!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

//insert value 假定数组有序 由小到大
int insert(Array *array, int value)
{
    int index;
    if(array->len > array->size)
        return ERROR;
    if(array->len == array->size) //数组已满
    {
        if(EXIT_FAILURE == relloc(array, 1))
            return ERROR;
    }
    for(index = array->len; (value < array->p[index-1]) && (index > 0); index--)
    {
        array->p[index] = array->p[index-1]; 
    }
    array->p[index] = value;
    array->len++;
    return index;
}

//search the value
int search(Array *array, int value)
{
    int index;
    for(index = 0; index < array->len; index++)
    {
        if(array->p[index] == value)
        {
            printf("The value %d in position: %d \n", value, index);
            return index;
        }
    }
    printf("Can not find the value %d in the Array!\n", value);
    return ERROR;
}

//delete a the position value
int delete(Array *array, int pos)
{
    if(pos <0 || pos > array->len)
        return ERROR;
    for(int i = pos; i < array->len; i++)
    {
        array->p[i] = array->p[i+1];
    }
    array->len--;
    return EXIT_SUCCESS;
}

int main(int argv, char* argc[])
{
    int index;
    int value;
    int tmp;
    char ch;

//create a new array
    Array five_int = {5, 0, NULL};
    if(alloc(&five_int))
        return EXIT_FAILURE;

    while(true)
    {
        printf("Please enter the value you want to insert:");
        scanf("%d", &value);
        tmp = insert(&five_int, value);
        if(ERROR == tmp)
        {
            printf("Fail to insert %d!\n", value);
            return EXIT_FAILURE;
        }
        else
        {
            printf("insert %d in Array %d!\n", value, tmp);
        }
        printf("是否继续插入：(y)es/(n)o?");
        fflush(stdin); //清空缓冲区 gcc不太好用
        scanf(" %c", &ch);  //前面加一个空格抵消上一次输入缓冲区残留的字符比如回车
        if(ch!='Y'&&ch!='y')
        {
            break;
        }
    }

    printf("======= insert finish =======\n");
    dump(&five_int);

//search the value in the array, then delete;if can‘t find, insert

    printf("Please enter the value you want to search:");
    scanf("%d", &value);
    tmp = search(&five_int, value);
    if(ERROR == tmp)
    {
        tmp = insert(&five_int, value);
        if(ERROR == tmp)
        {
            printf("Fail to insert %d!\n", value);
            return EXIT_FAILURE;
        }
        else
        {
            printf("insert %d in Array %d!\n", value, tmp);
        }
    }
    else
    {
        tmp = delete(&five_int, tmp);
        if(ERROR == tmp)
        {
            printf("Fail to insert %d!\n", value);
            return EXIT_FAILURE;
        }
        else
        {
            printf("delete %d success!\n", value);
        }
    }
    printf("======= dump the array =======\n");
    dump(&five_int);   

    return EXIT_SUCCESS;

}