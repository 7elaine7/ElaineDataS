/*
560. 和为K的子数组
给定一个整数数组和一个整数 k，你需要找到该数组中和为 k 的连续的子数组的个数。
示例 1 :
输入:nums = [1,1,1], k = 2
输出: 2 , [1,1] 与 [1,1] 为两种不同的情况。
说明 :
数组的长度为 [1, 20,000]。
数组中元素的范围是 [-1000, 1000] ，且整数 k 的范围是 [-1e7, 1e7]。
*/

//function 1, 暴力解法, 非常慢
int subarraySum(int* nums, int numsSize, int k){
    int count = 0;
    for(int i = 0; i < numsSize; ++i)
    {
        int sum = 0;
        for(int j = i; j < numsSize; ++j)
        {
            sum += nums[j];
            if(k == sum)
                count++;
        }
    }
    return count;
}

//function 2， 哈希 + 前缀，很快
//依次计算出到i为止的数据和，pre[i], 找与pre[i]之前相差k的pre[j]的个数，一定要记录最左边界0
//前缀+hash
//创建哈希表
typedef struct hash_node
{
    int key;    //pre[i]的值
    int value;  //pre[i]的个数
    struct hash_node *next;
}Hash_node;
typedef struct hash_map
{
    int size;   //哈希桶数量
    Hash_node* node_list;
}Hash_map;
Hash_map* hash_creat(int size)
{
    Hash_map* map = (Hash_map*)malloc(sizeof(Hash_map));
    map->size = size;
    map->node_list = (Hash_node*)malloc(sizeof(Hash_node) * size);
    for(int i = 0; i < size; ++i)
    {
        map->node_list[i].key = INT_MIN;
        map->node_list[i].value = 0;
        map->node_list[i].next = NULL;
    }
    return map;
}
void hash_insert(Hash_map* map, int key)
{
    int tmp = abs(key) % map->size; //算出哈希值
    Hash_node **p = &(map->node_list[tmp].next); //第一个节点不使用
    while(*p)
    {
        if((*p)->key == key)
        {
            (*p)->value++;
            return;
        }
        else
            p = &((*p)->next);
    }
    //如果没找到建一个新的,链接到链表末尾
    Hash_node* new = (Hash_node*)malloc(sizeof(Hash_node));
    new->key = key;
    new->value = 1;
    new->next = NULL;
    *p = new;
}
int hash_get(Hash_map* map, int key)
{
    int tmp = abs(key) % map->size;
    Hash_node *p = map->node_list[tmp].next;
    while(p)
    {
        if(p->key == key)
            return p->value;
        else
            p = p->next;
    }
    return 0;
}
int subarraySum(int* nums, int numsSize, int k){
    int count = 0;
    int sum = 0;
    Hash_map *map = hash_creat(numsSize);
    //最前面需要有个0，作为边界值
    hash_insert(map, 0);
    for(int i = 0; i < numsSize; ++i)
    {
        sum += nums[i];
        count += hash_get(map, sum - k);
        hash_insert(map, sum);
    }
    return count;
}