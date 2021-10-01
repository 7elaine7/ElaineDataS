/*
232. 用栈实现队列
请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
实现 MyQueue 类：
void push(int x) 将元素 x 推到队列的末尾
int pop() 从队列的开头移除并返回元素
int peek() 返回队列开头的元素
boolean empty() 如果队列为空，返回 true ；否则，返回 false
 
说明：
你只能使用标准的栈操作 —— 也就是只有 push to top, peek/pop from top, size, 和 is empty 操作是合法的。
你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。
 
进阶：
你能否实现每个操作均摊时间复杂度为 O(1) 的队列？换句话说，执行 n 个操作的总时间复杂度为 O(n) ，即使其中一个操作可能花费较长时间。
 
示例：
输入：
["MyQueue", "push", "push", "peek", "pop", "empty"]
[[], [1], [2], [], [], []]
输出：
[null, null, null, 1, 1, false]
解释：
MyQueue myQueue = new MyQueue();
myQueue.push(1); // queue is: [1]
myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
myQueue.peek(); // return 1
myQueue.pop(); // return 1, queue is [2]
myQueue.empty(); // return false
*/
//function 1, 并没有用双栈倒腾来倒腾去。。。。。。。
#define SIZE 100
typedef struct {
    int len;
    int head;
    int tail;
    int* stack;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* new = (MyQueue*)malloc(sizeof(MyQueue));
    new->len = 0;
    new->head = 0;
    new->tail = 0;
    new->stack = (int*)malloc(sizeof(int) * SIZE);
    memset(new->stack, 0, sizeof(int) * SIZE);
    return new;
}

void myQueuePush(MyQueue* obj, int x) {
    obj->stack[obj->tail++] = x;
    obj->len++;
}

int myQueuePop(MyQueue* obj) {
    int tmp = obj->stack[obj->head++];
    obj->len--;
    return tmp;
}

int myQueuePeek(MyQueue* obj) {
    return obj->stack[obj->head];
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->tail > obj->head)
        return false;
    else
        return true;
}

void myQueueFree(MyQueue* obj) {
    obj->stack = NULL;
    obj = NULL;
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/

//function 2， 双栈实现队列
#define SIZE 100
typedef struct {
    int head;   //存储队首元素
    int top1;
    int top2;
    int* stack1;
    int* stack2;
} MyQueue;

bool myQueueEmpty(MyQueue* obj);

MyQueue* myQueueCreate() {
    MyQueue* new = (MyQueue*)malloc(sizeof(MyQueue));
    new->head = 0;  //队首元素默认值为 0
    new->top1 = 0;
    new->top2 = 0;
    new->stack1 = (int*)malloc(sizeof(int) * SIZE);
    memset(new->stack1, 0, sizeof(int) * SIZE);
    new->stack2 = (int*)malloc(sizeof(int) * SIZE);
    memset(new->stack2, 0, sizeof(int) * SIZE);
    return new;
}

void myQueuePush(MyQueue* obj, int x) {
    if(myQueueEmpty(obj))
        obj->head = x;
    while(obj->top2)
    {
        obj->stack1[obj->top1++] = obj->stack2[--obj->top2];
    }
    obj->stack1[obj->top1++] = x;
}

int myQueuePop(MyQueue* obj) {
    while(obj->top1)
    {
        obj->stack2[obj->top2++] = obj->stack1[--obj->top1];
    }
    int tmp = obj->stack2[--obj->top2];
    //如果两个栈都是空，队首元素默认值为 0
    0 != obj->top2 ? obj->head = (obj->stack2[obj->top2 - 1]) : (obj->head = 0);
    return tmp;
}

int myQueuePeek(MyQueue* obj) {
    return obj->head;
}

bool myQueueEmpty(MyQueue* obj) {
    return !obj->top1 && !obj->top2;
}

void myQueueFree(MyQueue* obj) {
    obj->stack1 = NULL;
    obj->stack2 = NULL;
    obj = NULL;
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/