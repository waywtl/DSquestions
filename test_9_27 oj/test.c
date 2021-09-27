#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//138.复制带随机指针的链表
/*typedef struct Node Node;
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
        copy->next = NULL;
        copy->random = NULL;
        copy->val = cur->val;
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
        cur = cur->next->next;
    }
    //3.拆解出复制链表
    cur = head;
    //保存复制链表的头
    Node* copyHead = head->next;
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
}*/

//147.对链表进行插入排序
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

        //把cur插入到sortHead链表中，并且保持有序
        if (cur->val <= sortHead->val)
        {
            //头插
            cur->next = sortHead;
            sortHead = cur;
        }
        else
        {
            //中间插
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
            //尾插
            if (sortCur == NULL)
            {
                sortPrev->next = cur;
                cur->next = NULL;
            }
        }
        //迭代
        cur = next;
    }
    return sortHead;
}*/
