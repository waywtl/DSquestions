#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//206.��ת����
//�ⷨһ:����ָ�뻥�����,��תָ��ָ��
/*struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
    while(n2)
    {
        //��ת
        n2->next = n1;
        //����
        n1 = n2;
        n2 = n3;
        if(n3)
            n3 = n3->next;
    }
    return n1;
}*/

//�ⷨ��:ͷ�嵽��newheadΪͷ����������
/*struct ListNode* reverseList(struct ListNode* head)
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
}*/

//203.�Ƴ�����Ԫ��
/*
struct ListNode 
{
    int val;
    struct ListNode *next;
};


typedef struct ListNode Node;
struct ListNode* removeElements(struct ListNode* head, int val)
{
    Node* prev = NULL;
    Node* cur = head;
    while (cur)
    {
        if (cur->val == val)
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
}

int main()
{
    Node* n1 = (Node*)malloc(sizeof(Node));
    n1->val = 6;

    Node* n2 = (Node*)malloc(sizeof(Node));
    n2->val = 6;

    Node* n3 = (Node*)malloc(sizeof(Node));
    n3->val = 1;

    Node* n4 = (Node*)malloc(sizeof(Node));
    n4->val = 6;

    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = NULL;

    Node* head = removeElements(n1, 6);

    return 0;
}*/

//876.������м�ڵ�
//ʹ�ÿ���ָ��
/*typedef struct ListNode Node;
struct ListNode* middleNode(struct ListNode* head)
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

//��ָoffer 22.�����е�����k���ڵ�
/*typedef struct ListNode Node;
struct ListNode* getKthFromEnd(struct ListNode* head, int k)
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

//21.�ϲ�������������
/*typedef struct ListNode Node;
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    Node* head = NULL;
    Node* tail = NULL;
    if (l1->val < l2->val)
    {
        head = tail = l1;
        l1 = l1->next;
    }
    else
    {
        head = tail = l2;
        l2 = l2->next;
    }

    //head = tail = (Node*)malloc(sizeof(Node));

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
        tail->next = l2;

    //Node* realHead = head->next;
    //return realHead;
    return head;
}*/