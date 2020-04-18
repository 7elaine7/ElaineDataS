/*
面试题 16.02. 单词频率
设计一个方法，找出任意指定单词在一本书中的出现频率。
你的实现应该支持如下操作：
WordsFrequency(book)构造函数，参数为字符串数组构成的一本书
get(word)查询指定单词在数中出现的频率
示例：
WordsFrequency wordsFrequency = new WordsFrequency({"i", "have", "an", "apple", "he", "have", "a", "pen"});
wordsFrequency.get("you"); //返回0，"you"没有出现过
wordsFrequency.get("have"); //返回2，"have"出现2次
wordsFrequency.get("an"); //返回1
wordsFrequency.get("apple"); //返回1
wordsFrequency.get("pen"); //返回1
提示：
book[i]中只包含小写字母
1 <= book.length <= 100000
1 <= book[i].length <= 10
get函数的调用次数不会超过100000
*/

//function 1, 超出时间限制
#define SIZE 26
typedef struct node{
    int index;
    struct node *next;
}NODE;
typedef struct hash_node{
    struct NODE* head;
}Hash_Node;
typedef struct wordsFrequency{
    Hash_Node* hash;
    char** book;
}WordsFrequency;

WordsFrequency* wordsFrequencyCreate(char** book, int bookSize) {
    WordsFrequency* dictionary = (WordsFrequency*)malloc(sizeof(WordsFrequency));
    //输入的字典
    dictionary->book = book;
    //26个小写字母，记录单词首字母出现的位置
    dictionary->hash = (Hash_Node*)malloc(sizeof(Hash_Node) * SIZE);
    for(int i = 0; i < SIZE; ++i)
    {
        (dictionary->hash)[i].head = NULL;
    }
    for(int i = 0; i < bookSize; ++i)
    {
        int findex = book[i][0] - 'a';
        //新的index头插
        NODE* new = (NODE*)malloc(sizeof(NODE));
        new->index = i;
        new->next = (dictionary->hash)[findex].head;
        (dictionary->hash)[findex].head = new;
    }
    return dictionary;
}

int wordsFrequencyGet(WordsFrequency* obj, char* word) {
    NODE *p = (obj->hash)[word[0] - 'a'].head;
    if(NULL == p)
        return 0;
    int count = 0;
    while(p)
    {
        int index = p->index;
        if(0 == strcmp(word, (obj->book)[index]))
        {
            count++;
        }
        p = p->next;
    }
    return count;
}

void wordsFrequencyFree(WordsFrequency* obj) {
    free(obj);
}

/**
 * Your WordsFrequency struct will be instantiated and called as such:
 * WordsFrequency* obj = wordsFrequencyCreate(book, bookSize);
 * int param_1 = wordsFrequencyGet(obj, word);
 
 * wordsFrequencyFree(obj);
*/

//function 2, 进一步哈希算法
//执行用时 :364 ms, 在所有 C 提交中击败了64.84%的用户，内存消耗 :90.8 MB, 在所有 C 提交中击败了100.00%的用户
/*
哈希函数：
将单词中的每一位字母ascii码幂乘26的n次方，相加之后每个单词对应的数字唯一
因范围太大，最多100000个单词，分配150000个位置，装填因子大概在0.7左右
10位的单词计算后分配到150000个桶里
*/
#define SIZE 150000
typedef struct hash_node{
    char *word;
    int count;
    struct hash_node* next;
}Hash_Node;
typedef struct wordsFrequency{
    Hash_Node* head;
}WordsFrequency;

int get_hash(char* word)
{
    int size =  strlen(word);
    long long sum = 0;
    for(int i = 0; i < size; ++i)
    {
        sum = sum + (word[i] - 'a') * pow(26, size - i - 1);
    }
    int hash = (int)(sum % SIZE);
    return hash;
}
//初始化时候，用来确定是否已经有word在hash表中存在
bool find_word(Hash_Node* node, char* word)
{
    Hash_Node *tmp = node;
    while(tmp)
    {
        if(0 == strcmp(tmp->word, word))    
        {
            (tmp->count)++; //已经找到，数量+1
            return true;
        }
        else
        {
            tmp = tmp->next;
        }
    }
    return false;
}
WordsFrequency* wordsFrequencyCreate(char** book, int bookSize) {
    WordsFrequency* obj = (WordsFrequency*)malloc(sizeof(WordsFrequency) * SIZE);
    memset(obj, 0, sizeof(WordsFrequency) * SIZE);
    for(int i = 0; i < bookSize; ++i)
    {
        int hash_id = get_hash(book[i]);
        int size = strlen(book[i]);
        if(find_word(obj[hash_id].head, book[i])) 
            continue;   //已经存在，数量+1，跳出本次循环
        else    //没有头插一个新的
        {
            Hash_Node* node = (Hash_Node*)malloc(sizeof(Hash_Node));
            node->word = book[i];
            node->count = 1;
            node->next = obj[hash_id].head;
            obj[hash_id].head = node;
        }
    }
    return obj;
}

int wordsFrequencyGet(WordsFrequency* obj, char* word) {
    int id = get_hash(word);
    Hash_Node *p = obj[id].head;
    while(p)
    {
        if(0 == strcmp(p->word, word))
        {
            return p->count;
        }
        else
        {
            p = p->next;
        }
    }
    return 0;
}

void wordsFrequencyFree(WordsFrequency* obj) {
    free(obj);
}

/**
 * Your WordsFrequency struct will be instantiated and called as such:
 * WordsFrequency* obj = wordsFrequencyCreate(book, bookSize);
 * int param_1 = wordsFrequencyGet(obj, word);
 
 * wordsFrequencyFree(obj);
*/