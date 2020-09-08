/*
347. 前 K 个高频元素
给定一个非空的整数数组，返回其中出现频率前 k 高的元素。
示例 1:
输入: nums = [1,1,1,2,2,3], k = 2
输出: [1,2]
示例 2:
输入: nums = [1], k = 1
输出: [1]

提示：
你可以假设给定的 k 总是合理的，且 1 ≤ k ≤ 数组中不相同的元素的个数。
你的算法的时间复杂度必须优于 O(n log n) , n 是数组的大小。
题目数据保证答案唯一，换句话说，数组中前 k 个高频元素的集合是唯一的。
你可以按任意顺序返回答案。
*/
//function 1, 快排，待改进，参数类型不确定两种函数需合并优化
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//快排
typedef struct node
{
    int value;
    int num;
}Node;
//quik1
void swap(int* nums, int x, int y)
{
    int tmp = nums[x];
    nums[x] = nums[y];
    nums[y] = tmp;
}
int select_q(int* nums, int start, int end)
{
    int i = start;
    for(int j = start; j < end; ++j)
    {
        if(nums[j] > nums[end])
        {
            swap(nums, i, j);
            ++i;
        }
    }
    swap(nums, i, end);
    return i;
}
void quick(int* nums, int start, int end)
{
    if(start >= end)
        return;
    int q = select_q(nums, start, end);
    quick(nums, start, q - 1);
    quick(nums, q + 1, end);
}
//quik2
void swap_s(Node* queue, int x, int y)
{
    Node tmp = queue[x];
    queue[x] = queue[y];
    queue[y] = tmp;
}
int select_q_s(Node* queue, int start, int end)
{
    int i = start;
    for(int j = start; j < end; ++j)
    {
        if(queue[j].num > queue[end].num)
        {
            swap_s(queue, i, j);
            ++i;
        }
    }
    swap_s(queue, i, end);
    return i;
}
void quick_s(Node* queue, int start, int end)
{
    if(start >= end)
        return;
    int q = select_q_s(queue, start, end);
    quick_s(queue, start, q - 1);
    quick_s(queue, q + 1, end);
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    int* res = (int*)malloc(sizeof(int) * k);
    *returnSize = 0;

    quick(nums, 0, numsSize - 1);

    //统计重复个数
    Node* q = (Node*)malloc(sizeof(Node) * numsSize);
    int count = 1;
    int tmp = nums[0];
    int n = 0;
    for(int i = 1; i <= numsSize; ++i)
    {
        if(i == numsSize)
        {
            q[n].value = tmp;
            q[n++].num = count;
            break;
        }
        if(nums[i] == tmp)
        {
            count++;
        }
        else
        {
            q[n].value = tmp;
            q[n++].num = count;
            tmp = nums[i];
            count = 1;
        }
    }

    //次数排序
    quick_s(q, 0, n - 1);

    for(int i = 0; i < k; ++i)
    {
        res[i] = q[i].value;
    }
    *returnSize = k;    

    return res;
}


//function 2， 哈希， uthash用法
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct HASH_NODE
{
    int key;    //哈希存储数字
    int count;  //该数字出现的频率
    UT_hash_handle hh;  //hash处理句柄
}HASH;

//快排回调
int compfunc(HASH* x, HASH* y)
{
    return y->count - x->count;
}
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    *returnSize = k;
    HASH* head = NULL;
    HASH* p = NULL, *s = NULL;
    HASH* pNode = (HASH*)malloc(sizeof(HASH) * numsSize);

    int n = 0;
    for(; n < numsSize; ++n)
    {
        pNode[n].count = 1;
        pNode[n].key = nums[n];

        //查找哈希看该数字是否存在
        //HASH_FIND_INT(head,&nums[i],p)      
        //head为指向hash表的指针      
        //&nums[i]为传入的键值    
        //p为查找到的hash表指针
        HASH_FIND_INT(head, &nums[n], p);
        if(!p)
        {
            //如果不存在，将节点放入哈希表
            p = &pNode[n];
            //HASH_ADD_INT(head,key,p)        
            //head为指向hash表的指针      
            //key为键值       
            //p为需要插入hash表的节点指针
            HASH_ADD_INT(head, key, p);

        }
        else
        {
            p->count++;
        }
    }
    n = 0;
    //快排
    HASH_SORT(head, compfunc);
    //遍历
    HASH_ITER(hh, head, p, s)
    {
        if(n < k)
        {
            nums[n++] = p->key;
        }
    }
    return nums;
}

/*

uthash是C的比较优秀的开源代码，它实现了常见的hash操作函数，例如查找、插入、删除等待。

uthash定义，Uthash所实现的hash表中可以提供类似于双向链表的操作，可以通过结构体成员hh的 hh.prev和hh.next获取当前节点的上一个节点或者下一个节点。

#include"uthash.h"
 
struct my_struct {
    int id;                     //键值 
    char name[10];              //数据
    UT_hash_handle hh;          //hash处理句柄，不需要为该句柄变量赋值，但必须在该结构体中定义该变量。
};

Uthash为整型key提供的查找接口为HASH_FIND_INT

HASH_FIND_INT(head,&nums[i],p)      head为指向hash表的指针      &nums[i]为传入的键值    p为查找到的hash表指针

Uthash为整型key提供的插入接口为HASH_ADD_INT

HASH_ADD_INT(head,key,p)        head为指向hash表的指针      key为键值,结构体中成员       p为需要插入hash表的节点指针

Uthash提供的删除接口为HASH_DEL

HASH_DEL(head, p)      head为指向hash表的指针       p为需要删除的hash表节点指针

Uthash提供的查询hash表元素个数接口为HASH_COUNT

HASH_COUNT(head)     head为指向hash表的指针 

Uthash提供的遍历hash表接口为HASH_ITER

HASH_ITER(hh,head,p,s)      hh为hash处理句柄        head为指向hash表的指针      p为当前遍历到的结点指针     s为中间指针，用于内部操作

Uthash提供的快速排序hash表接口为HASH_SORT

HASH_SORT(head,compfunc)        head为指向hash表的指针      compfunc为快速排序回调函数

*/