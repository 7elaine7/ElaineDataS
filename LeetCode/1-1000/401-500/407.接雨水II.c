/*
407. 接雨水 II
给你一个 m x n 的矩阵，其中的值均为非负整数，代表二维高度图每个单元的高度，
请计算图中形状最多能接多少体积的雨水。
示例：
给出如下 3x6 的高度图:
[
  [1,4,3,1,3,2],
  [3,2,1,3,2,4],
  [2,3,3,2,3,1]
]
返回 4 。
提示：
1 <= m, n <= 110
0 <= heightMap[i][j] <= 20000
*/
/*
优先级队列，用小顶堆
先把最外面一层入堆，并且全部置为已访问过
堆顶元素弹出，作为海面高度，向四周扩散
如果周围未访问元素比海平面低，则可以接到雨水，量为：海平面 - 周围元素，将此元素置为已访问，入堆，值改为海平面的值
如果周围未访问元素比海平面高，则接不到雨水，置为已访问后，入堆
缩小范围直到堆中为空
*/
//入堆元素需存储其坐标
typedef struct node
{
    int x;
    int y;
    int value;
}Node;
typedef struct heap
{
    int size;
    Node* data;
}Heap;
//小顶堆，0位置留白，从1开始存储数据
void swap(Heap* heap, int x, int y)
{
    Node tmp = heap->data[x];
    heap->data[x] = heap->data[y];
    heap->data[y] = tmp;
}
void heapify(Heap* heap, int parent)
{
    int left;
    int right;
    int min;
    while(true)
    {
        left = parent * 2;
        right = parent * 2 + 1;
        min = parent;
        if(left <= heap->size && heap->data[left].value < heap->data[min].value)
            min = left;
        if(right <= heap->size && heap->data[right].value < heap->data[min].value)
            min = right;
        if(min == parent)
            break;
        swap(heap, min, parent);
        parent = min;
    }
}
void build_heap(Heap* heap)
{
    for(int i = heap->size / 2; i > 0; --i)
    {
        heapify(heap, i);
    }
}
int trapRainWater(int** heightMap, int heightMapSize, int* heightMapColSize){
    //如果只有围墙存在，无法接雨水
    if(heightMapSize <= 2 || *heightMapColSize <= 2)
        return 0;
    int r = heightMapSize;
    int c = * heightMapColSize;
    Heap heap;
    //建小顶堆，0留空，从1开始
    heap.data = (Node*)malloc(sizeof(Node) * r * c);
    heap.size = 0;
    //建立访问表，0未访问，1已访问
    int visited[r][c];
    for(int i = 0; i < r; ++i)
    {
        for(int j = 0; j < c; ++j)
        {
            visited[i][j] = 0;
        }
    }
    //最外围一圈，入堆，标记为已访问
    //最上一行
    for(int i = 0; i < c; ++i)
    {
        heap.data[++heap.size].value = heightMap[0][i];
        heap.data[heap.size].x = 0;
        heap.data[heap.size].y = i;
        visited[0][i] = 1;
    }

    //最后一列
    for(int i = 1; i < r; ++i)
    {
        heap.data[++heap.size].value = heightMap[i][c - 1];
        heap.data[heap.size].x = i;
        heap.data[heap.size].y = c - 1;
        visited[i][c - 1] = 1; 
    }
    //最下一行
    for(int i = 0; i < c - 1; ++i)
    {
        heap.data[++heap.size].value = heightMap[r - 1][i];
        heap.data[heap.size].x = r - 1;
        heap.data[heap.size].y = i;
        visited[r - 1][i] = 1;
    }
    //最前一列
    for(int i = 1; i < r - 1; ++i)
    {
        heap.data[++heap.size].value = heightMap[i][0];
        heap.data[heap.size].x = i;
        heap.data[heap.size].y = 0;
        visited[i][0] = 1;
    }

    int delt_x[4] = {0, 0, -1, 1};
    int delt_y[4] = {-1, 1, 0, 0};
    build_heap(&heap);
    int res = 0;
    while(heap.size > 0)
    {
        //堆顶弹出，堆尾补到1的位置
        Node tmp = heap.data[1];
        heap.data[1] = heap.data[heap.size--];

        for(int i = 0; i < 4; ++i)
        {
            int tmp_x = tmp.x + delt_x[i];
            int tmp_y = tmp.y + delt_y[i];
            if(tmp_x > 0 && tmp_x < r - 1 && tmp_y > 0 && tmp_y < c - 1 && visited[tmp_x][tmp_y] == 0)
            {
                visited[tmp_x][tmp_y] = 1;
                //周围未访问元素比海平面低，可以接到雨水，res为：海平面 - 周围元素，将此元素置为已访问，入堆，值改为海平面的值
                if(tmp.value > heightMap[tmp_x][tmp_y])
                {
                    res += tmp.value - heightMap[tmp_x][tmp_y];
                    heap.data[++heap.size].value = tmp.value;
                    heap.data[heap.size].x = tmp_x;
                    heap.data[heap.size].y = tmp_y;
                }
                //周围未访问元素比海平面高，接不到雨水，置为已访问，入堆
                else
                {
                    heap.data[++heap.size].value = heightMap[tmp_x][tmp_y];
                    heap.data[heap.size].x = tmp_x;
                    heap.data[heap.size].y = tmp_y;
                }
            }
        }
        build_heap(&heap);
    }
    return res;
}