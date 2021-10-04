#define _CRT_SECURE_NO_WARNINGS 1

typedef struct ListNode Node;
/*struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	Node* n1 = NULL;
	Node* n2 = head;
	Node* n3 = head->next;
	while (n2)
	{
		n2->next = n1;
		n1 = n2;
		n2 = n3;
		if(n3)
		    n3 = n3->next;
	}
	return n1;
}*/

/*struct ListNode* reverseList(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;
	Node* newhead = NULL;
	Node* cur = head;
	Node* next = head->next;
	while (cur)
	{
		cur->next = newhead;
		newnode = cur;
		cur = next;
		if(cur)
		    next = next->next;
	}
	return newhead;
}*/

/*struct ListNode* removeElements(struct ListNode* head, int val)
{
	Node* prev = NULL, * cur = head;
	while (cur)
	{
		if (cur->next == val)
		{
			if (cur == head)
			{
				head = cur->next;
				free(cur);
				cur = head;
			}
			else
			{
				prev->next = cur->next;
				free(cur);
				cur = prev->next;
			}
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return head;
}*/

/*struct ListNode* middleNode(struct ListNode* head)
{
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}*/

/*struct ListNode* getKthFromEnd(struct ListNode* head, int k)
{
	Node* slow = head;
	Node* fast = head;
	while (k--)
	{
		if (fast)
		{
			fast = fast->next;
		}
		else
			return NULL;
	}
	while (fast)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}*/

/*struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	Node* head = NULL;
	Node* tail = NULL;
	head = tail = (Node*)malloc(sizeof(Node));
	while (l1 && l2)
	{
		if (l1->val < l2->val)
		{
			tail->next = l1;
			l1 = l1->next;
		}
		else
		{
			tail->next = l2;
			l2 = l2->next;
		}
		tail = tail->next;
	}
	if (l1)
		tail->next = l1;
	else
		tail0->next = l2;
	Node* realHead = head->next;
	return realHead;
}*/

/*struct ListNode* partition(struct ListNode* head, int x)
{
	Node* greatHead = (Node*)malloc(sizeof(Node));
	Node* lessHead = (Node*)malloc(sizeof(Node));
	Node* greatTail = greatHead;
	Node* lessTail = lessHead;
	greatHead->next = NUll;
	lessHead->next = NUll;
	Node* cur = head
	while (cur)
	{
		if (cur->val < x)
		{
			lessTail->next = cur;
			lessTail = lessTail->next;
		}
		else
		{
			greatTail->next = cur;
			greatTail = greatTail->next;
		}
		cur = cur->next;
	}
	lessTail->next = greathead->next;
	greatTail->next = NULL;
	Node* realHead = lessHead->next;
	free(greatHead);
	free(lessHead);
	return realHead;
}*/

/*struct ListNode* reverselist(struct ListNode* head)
{
	if (head == NULL || head->next == NULL)
		return head;

	struct ListNode* newhead = NULL, * cur = head, * next = cur->next;
	while (cur)
	{
		cur->next = newhead;
		newhead = cur;
		cur = next;
		if (cur)
			next = next->next;
	}
	return newhead;
}

bool isPalindrome(struct ListNode* head)
{
	Node* slow = head;
	Node* fast = head;
	Node* prev = NULL;
	while (fast && fast->next)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	if (prev == NULL)
		return true;
	prev->next = NULL;
	slow = reverselist(slow);
	while (head)
	{
		if (head->val != slow->next)
			return false;
		else
		{
			head = head->next;
			slow = slow->next;
		}
	}
	return true;
}*/

/*struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
	Node* curA = headA;
	int la = 0;
	while (curA)
	{
		la++;
		curA = curA->next;
	}
	Node* curB = headB;
	int lb = 0;
	while (curB)
	{
		lb++;
		curB = curB->next;
	}
	Node* longList = headA;
	Node* shortList = headB;
	if (lb > la)
	{
		longList = headB;
		shortList = headA;
	}
	int gap = abs(la - lb);
	while (gap--)
		longList = longList->next;
	while (longList)
	{
		if (longList == shortList)
			return longList;
		longList = longList->next;
		shortList = shortList->next;
	}
	return NULL;
}*/

/*bool hasCycle(struct ListNode* head)
{
	Node* slow = head;
	Node* fast = head;
	while (fast && fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;

		if (fast == slow)
			return true;
	}
	return NULL;
}*/