#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

//225.用队列实现栈
/*typedef int QDataType;

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

void QueueDestroy(Queue* pq)
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
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);

	free(obj);
}

void TestMyStack()
{
	MyStack* ST = myStackCreate();
	myStackPush(ST, 1);
	myStackPush(ST, 2);
	myStackPush(ST, 3);
	myStackPush(ST, 4);
	myStackPush(ST, 5);
	printf("%d\n", myStackTop(ST));

	printf("%d\n", myStackPop(ST));
	printf("%d\n", myStackPop(ST));

	printf("%d\n", myStackTop(ST));

	while (!myStackEmpty(ST))
	{
		printf("%d ", myStackPop(ST));
	}
	printf("\n");

	myStackFree(ST);

}

int main()
{
	TestMyStack();
	return 0;
}*/

//237.删除链表中的节点
/*typedef struct ListNode LNode;
void deleteNode(struct ListNode* node)
{
	LNode* cur = node;
	LNode* curPrev = NULL;
	while (cur->next)
	{
		curPrev = cur;
		cur->val = cur->next->val;
		cur = cur->next;
	}
	curPrev->next = NULL;
	free(cur);
	cur = NULL;
}*/