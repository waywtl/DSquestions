#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//88.�ϲ�������������
/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * (m + n));
    int i1 = 0, i2 = 0;
    int i = 0;
    //ÿһ�����ΰ�С��Ԫ�طŵ�tmp������
    while (i1 < m && i2 < n)
    {
        if (nums1[i1] < nums2[i2])
            tmp[i++] = nums1[i1++];
        else
            tmp[i++] = nums2[i2++];
    }
    //������һ���������ʱ������һ������ӵ�tmp�������
    while (i1 < m)
        tmp[i++] = nums1[i1++];
    while (i2 < n)
        tmp[i++] = nums2[i2++];
    //��tmp�����е����ݿ�����nums1������
    memcpy(nums1, tmp, sizeof(int) * (m + n));
    free(tmp);
}*/

//189.��ת����
//void reverse(int* nums, int left, int right)
//{
//    while (left < right)
//    {
//        int tmp = nums[left];
//        nums[left] = nums[right];
//        nums[right] = tmp;
//        left++;
//        right--;
//    }
//}
//
//void rotate(int* nums, int numsSize, int k)
//{
//    //1.ʱ�临�ӶȲ�����
//    /*while(k--)
//    {
//        int tmp = nums[numsSize-1];
//        for(int i = 0;i < numsSize-1;i++)
//        {
//            nums[numsSize-1-i] = nums[numsSize-2-i];
//        }
//        nums[0] = tmp;
//    }*/
//    //2.�ռ临�ӶȲ�����
//    //int* pn = (int*)malloc(sizeof(int)*numsSize);
//    //3.������ת��
//    k %= numsSize;
//    reverse(nums, 0, numsSize - k - 1);
//    reverse(nums, numsSize - k, numsSize - 1);
//    reverse(nums, 0, numsSize - 1);
//
//}

//86.�ָ�����
/*typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x)
{
    //��less,greater��һ���ڱ�λ
    ListNode* lessHead = (Node*)malloc(sizeof(Node));
    ListNode* greaterHead = (Node*)malloc(sizeof(Node));
    ListNode* lessTail = lessHead;
    ListNode* greaterTail = greaterHead;
    //��ʼ�����������е�next
    lessHead->next = greaterHead->next = NULL;
    //��С��x�ķֵ�less�������ڵ���x�ķֵ�greater����
    ListNode* cur = head;
    while (cur)
    {
        if (cur->val < x)
        {
            lessTail->next = cur;
            lessTail = lessTail->next;
        }
        else
        {
            greaterTail->next = cur;
            greaterTail = greaterTail->next;
        }
        cur = cur->next;
    }

    //��less��β��greater��ͷ����
    lessTail->next = greaterHead->next;
    //��greater��β�е�next�ÿ�
    greaterTail->next = NULL;

    ListNode* list = lessHead->next;
    //�ͷ�
    free(lessHead);
    free(greaterHead);
    return list;
}*/

//234.��������
/*typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head)
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
    //���м�λ�ÿ�ʼ
    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    //�ж�����һ��Ԫ�ص����
    if (prev == NULL)
        return true;
    //�����ҶϿ�����
    prev->next = NULL;
    //�����Ҳ�����
    slow = reverseList(slow);
    //�ж��Ҳ����ú��Ƿ��������
    while (head)
    {
        if (head->val != slow->val)
            return false;
        else
        {
            head = head->next;
            slow = slow->next;
        }
    }
    return true;
}*/

//160.�ཻ����
/*typedef struct ListNode ListNode;
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //��A������
    ListNode* curA = headA;
    int la = 0;
    while (curA)
    {
        la++;
        curA = curA->next;
    }
    //��B������
    ListNode* curB = headB;
    int lb = 0;
    while (curB)
    {
        lb++;
        curB = curB->next;
    }

    //�ֳ���������
    ListNode* longlist = headA;
    ListNode* shortlist = headB;
    if (lb > la)
    {
        longlist = headB;
        shortlist = headA;
    }

    //��A��B�����ֵ�ľ���ֵ
    int gap = abs(la - lb);
    //�ó������ߵ��뽻����ͬ�����λ��
    while (gap--)
        longlist = longlist->next;
    //��������һ����
    while (longlist)
    {
        if (longlist == shortlist)
            return longlist;

        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return NULL;
}*/

//141.��������
//typedef struct ListNode ListNode;
//bool hasCycle(struct ListNode* head)
//{
//    ListNode* slow = head;
//    ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        /*���fastһ����3������slow����ʱ����������֮��ľ���ΪX,ÿ��һ�Σ�����֮��
//        * ������С2�����X�������ͻᵼ�´��������������������֮�������໹����
//        * �����ͻᵼ����һ�λ��Ǵ����������������ÿ�β�඼���������ͻ�һֱ�����
//        * �޷���������ѭ����
//        * һ����N��Ҳ�����Ƶĵ���
//        */
//        if (slow == fast)
//            return true;
//    }
//    return false;
//}

//142.���������
/*typedef struct ListNode ListNode;
struct ListNode* detectCycle(struct ListNode* head)
{
    ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        //�ж��Ƿ�����
        if (fast == slow)
            break;
    }
    //��������������������
    if (fast == NULL || fast->next == NULL)
        return NULL;

    //�������ڵ����һ���ڵ�ͬʱ��
    //slow�ߵľ��룺LS = L+X
    //fast�ߵľ��룺LF = L+N*C+X
    //��2*(L+X) = L+N*C+X
    //L = N*C-X
    //�����ٴ������Ľڵ㼴Ϊ���Ŀ�ʼ��

    ListNode* meet = fast;
    while (head != meet)
    {
        head = head->next;
        meet = meet->next;
    }

    return meet;
}*/