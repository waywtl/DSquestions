#define _CRT_SECURE_NO_WARNINGS 1

//19.删除链表的倒数第N个节点
/*typedef struct ListNode LNode;
struct ListNode* removeNthFromEnd(struct ListNode* head, int n)
{
    if (head->next == NULL)
        return NULL;
    LNode* slowPrev = NULL;
    LNode* slow = head;
    LNode* fast = head;
    while (n--)
        fast = fast->next;
    while (fast)
    {
        slowPrev = slow;
        slow = slow->next;
        fast = fast->next;
    }
    if (slow == head)
        head = head->next;
    else
        slowPrev->next = slow->next;
    free(slow);
    slow = NULL;
    return head;
}*/

//232.用栈实现队列
/*typedef int STDataType;

typedef struct Stack
{
    STDataType* a;
    int top;
    int capacity;
}ST;

void StackInit(ST* ps)
{
    assert(ps);

    ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
    if (ps->a == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    ps->capacity = 4;
    ps->top = 0;
}
void StackDestory(ST* ps)
{
    assert(ps);

    free(ps->a);
    ps->a = NULL;
    ps->top = ps->capacity = 0;
}

//入栈
void StackPush(ST* ps, STDataType x)
{
    assert(ps);

    //满了
    if (ps->top == ps->capacity)
    {
        STDataType* tmp = (STDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(STDataType));
        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }
        else
        {
            ps->a = tmp;
            ps->capacity *= 2;
        }
    }

    ps->a[ps->top] = x;
    ps->top++;
}

//出栈
void StackPop(ST* ps)
{
    assert(ps);
    //栈空了，调用Pop，直接中止程序报错
    assert(ps->top > 0);

    ps->top--;
}

STDataType StackTop(ST* ps)
{
    assert(ps);
    //栈空了，调用Top，直接中止程序报错
    assert(ps->top > 0);

    return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{
    assert(ps);

    return ps->top;
}

bool StackEmpty(ST* ps)
{
    assert(ps);

    return ps->top == 0;
}

typedef struct
{
    ST pushST;
    ST popST;
} MyQueue;

MyQueue* myQueueCreate()
{
    MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
    if (pq == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    StackInit(&pq->pushST);
    StackInit(&pq->popST);

    return pq;
}

void myQueuePush(MyQueue* obj, int x)
{
    StackPush(&obj->pushST, x);
}

int myQueuePop(MyQueue* obj)
{
    if (StackEmpty(&obj->popST))
    {
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }
    int front = StackTop(&obj->popST);
    StackPop(&obj->popST);
    return front;
}

int myQueuePeek(MyQueue* obj)
{
    if (StackEmpty(&obj->popST))
    {
        while (!StackEmpty(&obj->pushST))
        {
            StackPush(&obj->popST, StackTop(&obj->pushST));
            StackPop(&obj->pushST);
        }
    }
    int front = StackTop(&obj->popST);
    return front;
}

bool myQueueEmpty(MyQueue* obj)
{
    return StackEmpty(&obj->pushST) && StackEmpty(&obj->popST);
}

void myQueueFree(MyQueue* obj)
{
    StackDestory(&obj->pushST);
    StackDestory(&obj->popST);

    free(obj);
}*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct List
{
    int data;
    struct List* next;
}List;

typedef struct
{
    List* head;
    List* tail;
    int k;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k)
{
    MyCircularQueue* cq = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
    cq->head = (List*)malloc(sizeof(List));
    cq->tail = cq->head;
    cq->k = k;
    while (k--)
    {
        List* newNode = (List*)malloc(sizeof(List));
        cq->tail->next = newNode;
        cq->tail = newNode;
    }
    cq->tail->next = cq->head;
    cq->tail = cq->head;
    return cq;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj);
bool myCircularQueueIsFull(MyCircularQueue* obj);

bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
{
    if (myCircularQueueIsFull(obj))
        return false;

    obj->tail->data = value;
    obj->tail = obj->tail->next;
    return true;
}

bool myCircularQueueDeQueue(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return false;
    obj->head = obj->head->next;
    return true;
}

int myCircularQueueFront(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    return obj->head->data;
}

int myCircularQueueRear(MyCircularQueue* obj)
{
    if (myCircularQueueIsEmpty(obj))
        return -1;
    List* cur = obj->tail;
    int tmp = obj->k;
    while (tmp--)
    {
        cur = cur->next;
    }
    return cur->data;
}

bool myCircularQueueIsEmpty(MyCircularQueue* obj)
{
    return obj->head == obj->tail;
}

bool myCircularQueueIsFull(MyCircularQueue* obj)
{
    return obj->tail->next == obj->head;
}

void myCircularQueueFree(MyCircularQueue* obj)
{
    while (obj->head != obj->tail)
    {
        List* headNext = obj->head->next;
        free(obj->head);
        obj->head = headNext;
    }
    free(obj->head);
    obj->head = obj->tail = NULL;
}

int main()
{
    MyCircularQueue* cq = myCircularQueueCreate(3);
    myCircularQueueEnQueue(cq, 1);
    myCircularQueueEnQueue(cq, 2);
    myCircularQueueEnQueue(cq, 3);
    int a = myCircularQueueFront(cq);
    printf("%d\n", a);
    int b = myCircularQueueRear(cq);
    printf("%d\n", b);
    if (myCircularQueueIsFull(cq))
        printf("full\n");
    myCircularQueueDeQueue(cq);
    myCircularQueueDeQueue(cq);
    myCircularQueueDeQueue(cq);
    if (myCircularQueueIsEmpty(cq))
        printf("empty\n");
    myCircularQueueFree(cq);
    return 0;
}