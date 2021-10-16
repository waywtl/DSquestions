#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include <stdlib.h>

//20.有效的括号
/*typedef char STDataType;

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

bool isValid(char* s)
{
    ST st;
    StackInit(&st);
    while (*s != '\0')
    {
        switch (*s)
        {
        case '{':
        case '[':
        case '(':
        {
            StackPush(&st, *s);
            ++s;
            break;
        }
        case '}':
        case ']':
        case ')':
        {
            if (StackEmpty(&st))
            {
                StackDestory(&st);
                return false;
            }
            char top = StackTop(&st);
            StackPop(&st);
            //不匹配
            if ((*s == '}' && top != '{')
                || (*s == ']' && top != '[')
                || (*s == ')' && top != '('))
            {
                StackDestory(&st);
                return false;
            }
            //匹配
            else
            {
                ++s;
            }
            break;
        }
        default:
            break;
        }
    }
    bool ret = StackEmpty(&st);
    StackDestory(&st);
    return ret;
}*/

//用两个队列实现栈
typedef int QDataType;

typedef struct QueueNode
{
    QDataType data;
    struct QueueNode* next;
}QNode;

typedef struct Queue
{
    QNode* head;
    QNode* tail;
}Queue;

void QueueInit(Queue* pq)
{
    assert(pq);

    pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
    assert(pq);

    QNode* cur = pq->head;
    while (cur)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }

    pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);

    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }

    newnode->data = x;
    newnode->next = NULL;

    if (pq->tail == NULL)
    {
        pq->head = pq->tail = newnode;
    }
    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }
}

void QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    //1.一个
    //2.多个
    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->head = pq->tail = NULL;
    }
    else
    {
        QNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }
}

QDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
    assert(pq);
    assert(pq->tail);

    return pq->tail->data;
}

int QueueSize(Queue* pq)
{
    assert(pq);

    int size = 0;
    QNode* cur = pq->head;
    while (cur)
    {
        size++;
        cur = cur->next;
    }
    return size;
}

bool QueueEmpty(Queue* pq)
{
    assert(pq);

    return pq->head == NULL;
}

typedef struct
{
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate()
{
    MyStack* ps = (MyStack*)malloc(sizeof(MyStack));
    if (ps == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    QueueInit(&ps->q1);
    QueueInit(&ps->q2);

    return ps;
}

void myStackPush(MyStack* obj, int x)
{
    if (!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1, x);
    }
    else
    {
        QueuePush(&obj->q2, x);
    }
}

int myStackPop(MyStack* obj)
{
    Queue* emptyQ = &obj->q1;
    Queue* nonemptyQ = &obj->q2;
    if (!QueueEmpty(&obj->q1))
    {
        emptyQ = &obj->q2;
        nonemptyQ = &obj->q1;
    }
    //倒数据
    while (QueueSize(nonemptyQ) > 1)
    {
        QueuePush(emptyQ, QueueFront(nonemptyQ));
        QueuePop(nonemptyQ);
    }

    int top = QueueFront(nonemptyQ);
    QueuePop(nonemptyQ);

    return top;
}

int myStackTop(MyStack* obj)
{
    if (!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj)
{
    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj)
{
    QueueDestory(&obj->q1);
    QueueDestory(&obj->q2);

    free(obj);
}