/*
23. 合并K个排序链表
合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
示例:
输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6
*/
//小顶堆实现，每个链表头节点放入堆中堆化，取出堆顶结点，再将此结点所在链表的下一个结点放入
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode Node;
void swap(Node** heap, int a, int b)
{
    Node* tmp = heap[a];
    heap[a] = heap[b];
    heap[b] = tmp;
}
void heapify(Node** heap, int parent, int end)
{
    int right, left, min;
    while(true)
    {
        min = parent;
        left = 2 * parent;
        right = left + 1;
        if(left <= end && heap[left]->val < heap[min]->val)
        {
            min = left;
        }
        if(right <= end && heap[right]->val < heap[min]->val)
        {
            min = right;
        }
        if(parent == min)
            break;
        swap(heap, parent, min);
        parent = min;
    }
}
void build_heap(Node** heap, int end)
{
    for(int i = end / 2; i > 0; --i)
    {
        heapify(heap, i, end);
    }
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    //建堆，0的位置空出来
    Node* heap[listsSize + 1];
    int size = 0;
    for(int i = 1; i <= listsSize; ++i)
    {
        if(lists[i - 1])
        {
            heap[size + 1] = lists[i - 1];
            size++;
        }
    }
    if(0 == size)
        return NULL;
    Node* obj = NULL;
    Node** p = &obj;
    while(size > 0)
    {
        build_heap(heap, size);
        //将小顶堆顶端最小值取走
        *p = heap[1];
        heap[1] = heap[1]->next;
        p = &(*p)->next;    //->，()优先级1，*，&优先级2
        //如果此时heap[1]值已经取空，将heap[1]移到最后
        if(heap[1] == NULL)
        {
            swap(heap, 1, size);
            size--;
        }
    }
    return obj;
}
