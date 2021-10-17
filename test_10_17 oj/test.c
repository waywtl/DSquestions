#define _CRT_SECURE_NO_WARNINGS 1


//232.用栈实现队列
typedef int STDataType;

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
    ST s1;
    ST s2;
} MyQueue;

MyQueue* myQueueCreate()
{
    MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));
    if (pq == NULL)
    {
        printf("malloc fail\n");
        exit(-1);
    }
    StackInit(&pq->s1);
    StackInit(&pq->s2);

    return pq;
}

void myQueuePush(MyQueue* obj, int x)
{
    if (!StackEmpty(&obj->s1))
    {
        StackPush(&obj->s1, x);
    }
    else
    {
        StackPush(&obj->s2, x);
    }
}

int myQueuePop(MyQueue* obj)
{
    ST* emptyS = &obj->s1;
    ST* nonemptyS = &obj->s2;
    if (!StackEmpty(&obj->s1))
    {
        emptyS = &obj->s2;
        nonemptyS = &obj->s1;
    }
    while (StackSize(nonemptyS) > 1)
    {
        StackPush(emptyS, StackTop(nonemptyS));
        StackPop(nonemptyS);
    }
    int head = StackTop(nonemptyS);
    StackPop(nonemptyS);
    while (StackSize(emptyS) > 0)
    {
        StackPush(nonemptyS, StackTop(emptyS));
        StackPop(emptyS);
    }
    return head;
}

int myQueuePeek(MyQueue* obj)
{
    ST* emptyS = &obj->s1;
    ST* nonemptyS = &obj->s2;
    if (!StackEmpty(&obj->s1))
    {
        emptyS = &obj->s2;
        nonemptyS = &obj->s1;
    }
    while (StackSize(nonemptyS) > 1)
    {
        StackPush(emptyS, StackTop(nonemptyS));
        StackPop(nonemptyS);
    }
    int head = StackTop(nonemptyS);
    StackPush(emptyS, StackTop(nonemptyS));
    StackPop(nonemptyS);
    while (StackSize(emptyS) > 0)
    {
        StackPush(nonemptyS, StackTop(emptyS));
        StackPop(emptyS);
    }
    return head;
}

bool myQueueEmpty(MyQueue* obj)
{
    return StackEmpty(&obj->s1) && StackEmpty(&obj->s2);
}

void myQueueFree(MyQueue* obj)
{
    StackDestory(&obj->s1);
    StackDestory(&obj->s2);

    free(obj);
}