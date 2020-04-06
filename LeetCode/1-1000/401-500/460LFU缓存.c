/*
460. LFU缓存
设计并实现最不经常使用（LFU）缓存的数据结构。它应该支持以下操作：get 和 put。
get(key) - 如果键存在于缓存中，则获取键的值（总是正数），否则返回 -1。
put(key, value) - 如果键不存在，请设置或插入值。当缓存达到其容量时，它应该在插入新项目之前，使最不经常使用的项目无效。
在此问题中，当存在平局（即两个或更多个键具有相同使用频率）时，最近最少使用的键将被去除。
进阶：
你是否可以在 O(1) 时间复杂度内执行两项操作？
示例：
LFUCache cache = new LFUCache( 2  ); // 2为capacity (缓存容量)
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回 1
cache.put(3, 3);    // 去除 key 2
cache.get(2);       // 返回 -1 (未找到key 2)
cache.get(3);       // 返回 3
cache.put(4, 4);    // 去除 key 1
cache.get(1);       // 返回 -1 (未找到 key 1)
cache.get(3);       // 返回 3
cache.get(4);       // 返回 4
*/
/*
以访问频率为索引主链表，从小到大排列
每个索引结点下链接不同的key

                                      [key8]
                                        |
          [key2]                      [key7]
             |                          |
          [key1]    [key3]            [key6]
             |        |                 |
->[head]->[freq0]->[freq1]->[freq2]->[freq5]
*/

typedef struct MyLFUCache{
    int key;
    int count;  //访问频率次数 || 头节点时代表结点总个数
    int value;
    int capacity;   //总容量  || 普通节点代表此频率下结点个数
    struct MyLFUCache *pre;
    struct MyLFUCache *next;
} LFUCache;

LFUCache* lFUCacheCreate(int capacity) {
    //头节点存储当前链表信息
    LFUCache *head = (LFUCache*)malloc(sizeof(LFUCache));
    head->count = 0;    //链表当前存储的个数
    head->pre = NULL;
    head->next = NULL;
    head->capacity = capacity;  //整体容量
    return head;
}

int lFUCacheGet(LFUCache* obj, int key) {
    if(0 == obj->capacity || NULL == obj)
        return -1;
    LFUCache *head = obj;
    LFUCache *current = head->next;
    int val = -1;
    bool flag = false;
    bool status = false;
    LFUCache *p;
    //找key的结点
    while(current)     //当前频率下结点个数不为0
    {
        p = current;
        while(p->pre)
        {
            if((p->pre->key) == key)
            {
                val = p->pre->value;
                flag = true;
                break;
            }
            p = p->pre;
        }
        if(flag)
            break;
        else
            current = current->next;
    }
    //要找的key值存在，将会进行频率调整
    if(flag)
    {
        int freq = current->count + 1;   //访问频率+1
        LFUCache *tmp = current;
        while(tmp->next && tmp->next->count <= freq)
        {
            if(freq == tmp->next->count)
            {
                status = true;
                break;
            }
        }
        if(true == status)  //+1的访问频率存在，将找到的结点放在当前频率链表的最顶端
        {
            LFUCache *p1 = tmp->next;
            while(p1->pre)
            {
                p1 = p1->pre;
            }
            p1->pre = p->pre;
            p->pre = p->pre->pre;
            p1->pre->pre = NULL;
            p1->pre->count++;
            tmp->next->capacity++;
        }
        else    //新建频率索引节点为freq的索引结点
        {
            LFUCache *node = (LFUCache*)malloc(sizeof(LFUCache));
            node->count = freq;
            node->capacity = 1;
            node->next = tmp->next;
            tmp->next = node;
            node->pre = p->pre;
            p->pre = p->pre->pre;
            node->pre->pre = NULL;
        }
        current->capacity--;
    }
    return val;
}

void lFUCachePut(LFUCache* obj, int key, int value) {
    if(0 == obj->capacity || NULL == obj)
        return;
    int result = lFUCacheGet(obj, key);
    LFUCache *head = obj;
    int flag = false;
    if(result != value && result != -1) //存的key对应的value不等于新加入的value，需要更新链表中key的value
    {
        LFUCache *find_r = head->next;
        LFUCache *find_c;
        while(find_r)     //当前频率下结点个数不为0
        {
            find_c = find_r;
            while(find_c->pre)
            {
                if((find_c->pre->key) == key)
                {
                    find_c->pre->value = value;
                    flag = true;
                    break;
                }
                find_c = find_c->pre;
            }
            if(flag)
                break;
            else
                find_r = find_r->next;
        }
        return;
    }
    if(-1 == result)    //链表里没有
    {
        //建立新节点，频率索引为0
        LFUCache *node = (LFUCache*)malloc(sizeof(LFUCache));
        node->key = key;
        node->value = value;
        node->count = 0;
        node->next = NULL;
        node->pre = NULL;
        if(head->capacity == head->count)   //容量已满, 频率索引为0的结点必然存在, 删除最近最少使用的
        {
            LFUCache *p1 = head->next;
            while(p1->capacity == 0)
            {
                p1 = p1->next;
            }
            LFUCache *tmp = p1->pre;
            p1->pre = tmp->pre;
            tmp->pre = NULL;
            free(tmp);
            p1->capacity--;
            //把新节点挂在0索引节点下边
            p1 = head->next;
            p1->capacity++;
            while(p1->pre)
            {
                p1 = p1->pre;
            }
            p1->pre = node;
            node->pre = NULL;
        }
        else if(head->count < head->capacity)   //容量还没满，直接插入
        {
            LFUCache *p = head;
            if(NULL == p->next || p->next->count != 0)     //没有频率为0的索引节点
            {
                //建造一个频率0的索引结点
                LFUCache *fre_node = (LFUCache*)malloc(sizeof(LFUCache));
                fre_node->count = 0;
                fre_node->capacity = 1;
                fre_node->next = p->next;
                fre_node->pre = NULL;
                p->next = fre_node;
                //把新节点挂在0索引节点下边
                p = p->next;
                p->pre = node;
                node->pre = NULL;
            }
            else{   //频率为0的索引节点存在，将新节点插在最上边
                p = p->next;
                p->capacity++;  //0索引结点下的数量+1
                while(p->pre)
                {
                    p = p->pre;
                }
                p->pre = node;
            }
            head->count++;  //总个数+1
        }
    }
}
                                  
void lFUCacheFree(LFUCache* obj) {
    LFUCache *tmp=obj;
    while(obj){
        obj=obj->next;
        free(tmp);
        tmp=obj;
    } 
}

/**
 * Your LFUCache struct will be instantiated and called as such:
 * LFUCache* obj = lFUCacheCreate(capacity);
 * int param_1 = lFUCacheGet(obj, key);
 
 * lFUCachePut(obj, key, value);
 
 * lFUCacheFree(obj);
*/