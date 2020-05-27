/*
974. 和可被 K 整除的子数组
给定一个整数数组 A，返回其中元素之和可被 K 整除的（连续、非空）子数组的数目。
示例：
输入：A = [4,5,0,-2,-3,1], K = 5
输出：7
解释：
有 7 个子数组满足其元素之和可被 K = 5 整除：
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
提示：
1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000
*/

//和560相类似
//前缀+哈希
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
int subarraysDivByK(int* A, int ASize, int K){
    int count = 0;
    int sum = 0;
    Hash_map *map = hash_creat(ASize);
    //最前面需要有0，作为边界值
    hash_insert(map, 0);
    for(int i = 0; i < ASize; ++i)
    {
        sum += A[i];
        //负数mod需要+K
        int mod = (sum % K + K) % K;
        count += hash_get(map, mod);
        hash_insert(map, mod);
    }
    return count;
}