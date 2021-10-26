#define _CRT_SECURE_NO_WARNINGS 1

//138.复制带随机指针的链表
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
		return NULL;
	//1.拷贝节点，连接到原节点的后面
	Node* cur = head;
	while (cur)
	{
		//开辟复制节点并初始化
		Node* copy = (Node*)malloc(sizeof(Node));
		Node* next = cur->next;
		copy->val = cur->val;
		copy->next = NULL;
		copy->random = NULL;
		//把复制节点与原链表链接
		cur->next = copy;
		copy->next = next;
		//向后迭代
		cur = next;
	}
	//2.处理拷贝节点的random
	cur = head;
	while (cur)
	{
		//复制的random为原来random的下一个
		Node* copy = cur->next;
		if (cur->random != NULL)
			copy->random = cur->random->next;
		else
			copy->random = NULL;
		//向后迭代
		cur = copy->next;
	}
	//3.拆解出复制链表
	cur = head;
	//保存复制链表的头
	Node* copyHead = cur->next;
	while (cur)
	{
		Node* copy = cur->next;
		Node* next = copy->next;
		//重新链接
		cur->next = next;
		if (next)
			copy->next = next->next;
		else
			copy->next = NULL;
		//向后迭代
		cur = next;
	}
	return copyHead;
}