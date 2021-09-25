#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

//206.反转链表
//解法一:三个指针互相迭代,反转指针指向
/*struct ListNode* reverseList(struct ListNode* head)
{
    if(head == NULL || head->next == NULL)
        return head;

    struct ListNode* n1 = NULL, *n2 = head, *n3 = head->next;
    while(n2)
    {
        //反转
        n2->next = n1;
        //迭代
        n1 = n2;
        n2 = n3;
        if(n3)
            n3 = n3->next;
    }
    return n1;
}*/

//解法二:头插到以newhead为头的新链表中
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

//203.移除链表元素
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

//876.链表的中间节点
//使用快慢指针
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

//剑指offer 22.链表中倒数第k个节点
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

//21.合并两个有序链表
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