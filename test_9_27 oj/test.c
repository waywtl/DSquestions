#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//138.���ƴ����ָ�������
/*typedef struct Node Node;
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
        copy->next = NULL;
        copy->random = NULL;
        copy->val = cur->val;
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
        cur = cur->next->next;
    }
    //3.������������
    cur = head;
    //���渴�������ͷ
    Node* copyHead = head->next;
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
}*/

//147.��������в�������
/*typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node* sortHead = head;
    Node* cur = head->next;
    sortHead->next = NULL;
    while (cur)
    {
        Node* next = cur->next;

        //��cur���뵽sortHead�����У����ұ�������
        if (cur->val <= sortHead->val)
        {
            //ͷ��
            cur->next = sortHead;
            sortHead = cur;
        }
        else
        {
            //�м��
            Node* sortPrev = sortHead;
            Node* sortCur = sortPrev->next;
            while (sortCur)
            {
                if (cur->val <= sortCur->val)
                {
                    sortPrev->next = cur;
                    cur->next = sortCur;
                    break;
                }
                else
                {
                    sortPrev = sortCur;
                    sortCur = sortCur->next;
                }
            }
            //β��
            if (sortCur == NULL)
            {
                sortPrev->next = cur;
                cur->next = NULL;
            }
        }
        //����
        cur = next;
    }
    return sortHead;
}*/
