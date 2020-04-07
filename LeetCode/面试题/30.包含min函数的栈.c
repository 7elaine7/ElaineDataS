/*
面试题30. 包含min函数的栈
定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的 min 函数在该栈中，调用 min、push 及 pop 的时间复杂度都是 O(1)。
示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.min();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.min();   --> 返回 -2. 
提示：
各函数的调用总次数不超过 20000 次
*/

//function1，链表实现，时间太长
typedef struct myStack{
    struct myStack* pre;
    int data;   //头节点代表链表中个数
    int min;    //代表到当前节点为止的最小值
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack* head = (MinStack*)malloc(sizeof(MinStack));
    head->data = 0;
    head->min = INT_MAX;
    head->pre = NULL;
    return head;
}

void minStackPush(MinStack* obj, int x) {
    MinStack *head = obj;
    MinStack *p = head;
    MinStack *node = (MinStack*)malloc(sizeof(MinStack));
    node->pre = NULL;
    node->data = x;
    while(p->pre)
    {
        p = p->pre;
    }
    p->pre = node;
    head->data++;
    if(x < p->min)
    {
        node->min = x;
    }
    else
    {
        node->min = p->min;
    }
    head->min = node->min;
    printf("min = %d\n",head->min);
    node = NULL;
    free(node);
}

void minStackPop(MinStack* obj) {
    MinStack *head = obj;
    int tmp = INT_MAX;

    if(0 == head->data || NULL == obj)
        return;
    MinStack **p = &head;
    while((*p)->pre)
    {
        tmp = (*p)->min;
        p = &((*p)->pre);
    }
    *p = NULL;
    head->data--;
    if(0 == head->data)
        head->min = INT_MAX;
    else
        head->min = tmp;
}

int minStackTop(MinStack* obj) {
    MinStack *p = obj;
    if(0 == p->data || NULL == obj)
        return -1;
    while(p->pre)
    {
        p = p->pre;
    }
    return p->data;    
}

int minStackMin(MinStack* obj) {
    return obj->min;
}

void minStackFree(MinStack* obj) {
    MinStack *p = obj;
    while(obj)
    {
        obj = obj->pre;
        free(p);
        p = obj;
    }
}

/*
function2，数组实现, 较快
*/
#define MAX_SIZE 20001
typedef struct mymin{
    int min;   //top为当前节点时栈的最小值
    int data;
}MyMin;
typedef struct myStack{
    int len;    //栈中元素个数
    int top;    //栈顶
    MyMin array[MAX_SIZE];
} MinStack;

/** initialize your data structure here. */

MinStack* minStackCreate() {
    MinStack *stack = (MinStack*)malloc(sizeof(MinStack));
    stack->len = 0;
    stack->top = 0;
    return stack;
}

void minStackPush(MinStack* obj, int x) {
    obj->array[obj->top].data = x;
    obj->len++;
    if(obj->len == 1)
        obj->array[obj->top].min = x; 
    else if(x < obj->array[obj->top - 1].min)
        obj->array[obj->top].min = x;
    else
        obj->array[obj->top].min = obj->array[obj->top - 1].min;
    obj->top++;
}

void minStackPop(MinStack* obj) {
    obj->top--;
    obj->len--;
}

int minStackTop(MinStack* obj) {
   return obj->array[obj->top - 1].data;
}

int minStackMin(MinStack* obj) {
    return obj->array[obj->top - 1].min;
}

void minStackFree(MinStack* obj) {
    free(obj);
}


/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, x);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackMin(obj);
 
 * minStackFree(obj);
*/