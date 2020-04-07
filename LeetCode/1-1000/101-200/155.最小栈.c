/*
155. 最小栈
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
push(x) —— 将元素 x 推入栈中。
pop() —— 删除栈顶的元素。
top() —— 获取栈顶元素。
getMin() —— 检索栈中的最小元素。
示例:
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.
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

int minStackGetMin(MinStack* obj) {
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
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/