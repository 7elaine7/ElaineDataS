/*
146. LRU缓存机制
运用你所掌握的数据结构，设计和实现一个  LRU (最近最少使用) 缓存机制。它应该支持以下操作： 获取数据 get 和 写入数据 put 。
获取数据 get(key) - 如果密钥 (key) 存在于缓存中，则获取密钥的值（总是正数），否则返回 -1。
写入数据 put(key, value) - 如果密钥已经存在，则变更其数据值；如果密钥不存在，则插入该组「密钥/数据值」。
当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值留出空间。
进阶:
你是否可以在 O(1) 时间复杂度内完成这两种操作？
示例:
LRUCache cache = new LRUCache( 2 // 缓存容量 );
cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // 返回  1
cache.put(3, 3);    // 该操作会使得密钥 2 作废
cache.get(2);       // 返回 -1 (未找到)
cache.put(4, 4);    // 该操作会使得密钥 1 作废
cache.get(1);       // 返回 -1 (未找到)
cache.get(3);       // 返回  3
cache.get(4);       // 返回  4
*/
typedef struct node{
    int key;
    int value;
    struct node* pre;    //链接双链表
    struct node* next;   //链接双链表
    struct node* hnext;  //链接散列表
} Node;
typedef struct hnode
{
    int count;      //每个散列表下已链接的元素个数
    Node* hhead;
}H_Node;
typedef struct{
    int capacity;   //总容量
    int size;       //哈希桶数量
    int total;      //总的元素个数
    Node* head;     //双链表头
    Node* tail;     //双链表尾
    H_Node* hash;
}LRUCache;

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* obj = (LRUCache*)malloc(sizeof(LRUCache));
    obj->capacity = capacity;
    obj->size = capacity * 4 / 3;
    obj->total = 0;
    obj->head = NULL;
    obj->tail = NULL;
    //建散列表
    obj->hash = (H_Node*)malloc(sizeof(H_Node) * obj->size);
    for(int i = 0; i < obj->size; ++i)
    {
        obj->hash[i].count = 0;
        obj->hash[i].hhead = NULL;
    }
    return obj;
}

int lRUCacheGet(LRUCache* obj, int key) {
    int index = key % obj->size;
    if(obj->hash[index].count == 0)
        return -1;
    Node** p = &(obj->hash[index].hhead);
    while(*p)
    {
        if((*p)->key == key)
        {
            //如果是尾节点不更新
            if(obj->tail->key == key || ((obj->capacity == 1) && (obj->total == 1)))
                return (*p)->value;
            //其他节点则在双链表中移到尾节点
            //如果是头节点
            if(obj->head->key == key)
            {
                obj->head = (*p)->next;
                (*p)->next->pre = NULL;
            }
            //如果是中间节点
            else
            {
                (*p)->pre->next = (*p)->next;
                (*p)->next->pre = (*p)->pre;
            }
            obj->tail->next = *p;
            (*p)->pre = obj->tail;
            (*p)->next = NULL;
            obj->tail = *p;
            return obj->tail->value;
        }
        p = &((*p)->hnext);
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    if(obj->capacity == 0)
        return;
    int index = key % obj->size;
    if(obj->total == 0)
    {
        obj->total = 1;
        Node* new = (Node*)malloc(sizeof(Node));    //一定要动态分配！！！
        new->key = key;
        new->value = value;
        new->pre = NULL;
        new->next = NULL;
        new->hnext = NULL;

        obj->head = new;
        obj->tail = new;

        obj->hash[index].count = 1;
        obj->hash[index].hhead = new;
        return;
    }

    if((obj->capacity == 1) && (obj->total == 1))
    {
        obj->hash[0].hhead->key = key;
        obj->hash[0].hhead->value = value;
        return;
    }

    //查找key是否已经存在
    Node** p = &(obj->hash[index].hhead);
    while(*p)
    {
        if((*p)->key == key)
        {
            //如果key存在，变更value
            (*p)->value = value;
            //将更新后的点挪到双链表尾部
            //如果是链表尾不动
            if(obj->tail->key == key)
                return;
            //如果是链表头
            if(obj->head->key == key)
            {
                //删掉链表头
                obj->head = (*p)->next;
                (*p)->next->pre = NULL;
            }
            else
            {
                //在链表中间
                (*p)->pre->next = (*p)->next;
                (*p)->next->pre = (*p)->pre;
            }
            //挪到链表尾
            obj->tail->next = *p;
            (*p)->pre = obj->tail;
            (*p)->next = NULL;
            obj->tail = *p;
            return;
        }
        p = &((*p)->hnext);
    }
        
    //key不存在插入新的key
    Node* new = (Node*)malloc(sizeof(Node));    //一定要动态分配！！！
    new->key = key;
    new->value = value;
    //如果已满，删除链表头
    if(obj->capacity == obj->total)
    {
        //找到头节点所在哈希表的位置
        int index_head = obj->head->key % obj->size;
        (obj->hash[index_head].count)--;
        Node** tmp = &(obj->hash[index_head].hhead);
        while(*tmp)
        {
            if((*tmp)->key == obj->head->key)
            {
                //删掉链表头
                Node* d = *tmp;
                *tmp = d->hnext;
                d->hnext = NULL;
                obj->head = d->next;
                d->next->pre = NULL;
                d->next = NULL;
                break;
            }
            tmp = &((*tmp)->hnext);
        }
    }
    else
        obj->total++;
    //新节点加到链表尾
    obj->hash[index].count++;
    *p = new;
    new->hnext = NULL;
    obj->tail->next = new;
    new->pre = obj->tail;
    new->next = NULL;
    obj->tail = new;
    return;
}

void lRUCacheFree(LRUCache* obj) {
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
