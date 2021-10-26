#define _CRT_SECURE_NO_WARNINGS 1

//138.���ƴ����ָ�������
typedef struct Node Node;
struct Node* copyRandomList(struct Node* head)
{
	if (head == NULL)
		return NULL;
	//1.�����ڵ㣬���ӵ�ԭ�ڵ�ĺ���
	Node* cur = head;
	while (cur)
	{
		//���ٸ��ƽڵ㲢��ʼ��
		Node* copy = (Node*)malloc(sizeof(Node));
		Node* next = cur->next;
		copy->val = cur->val;
		copy->next = NULL;
		copy->random = NULL;
		//�Ѹ��ƽڵ���ԭ��������
		cur->next = copy;
		copy->next = next;
		//������
		cur = next;
	}
	//2.�������ڵ��random
	cur = head;
	while (cur)
	{
		//���Ƶ�randomΪԭ��random����һ��
		Node* copy = cur->next;
		if (cur->random != NULL)
			copy->random = cur->random->next;
		else
			copy->random = NULL;
		//������
		cur = copy->next;
	}
	//3.������������
	cur = head;
	//���渴�������ͷ
	Node* copyHead = cur->next;
	while (cur)
	{
		Node* copy = cur->next;
		Node* next = copy->next;
		//��������
		cur->next = next;
		if (next)
			copy->next = next->next;
		else
			copy->next = NULL;
		//������
		cur = next;
	}
	return copyHead;
}