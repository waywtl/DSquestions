#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//88.合并两个有序数组
/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    int* tmp = (int*)malloc(sizeof(int) * (m + n));
    int i1 = 0, i2 = 0;
    int i = 0;
    //每一次依次把小的元素放到tmp数组中
    while (i1 < m && i2 < n)
    {
        if (nums1[i1] < nums2[i2])
            tmp[i++] = nums1[i1++];
        else
            tmp[i++] = nums2[i2++];
    }
    //当其中一个数组结束时，把另一个数组接到tmp数组后面
    while (i1 < m)
        tmp[i++] = nums1[i1++];
    while (i2 < n)
        tmp[i++] = nums2[i2++];
    //把tmp数组中的内容拷贝到nums1数组中
    memcpy(nums1, tmp, sizeof(int) * (m + n));
    free(tmp);
}*/

//189.旋转数组
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
//    //1.时间复杂度不满足
//    /*while(k--)
//    {
//        int tmp = nums[numsSize-1];
//        for(int i = 0;i < numsSize-1;i++)
//        {
//            nums[numsSize-1-i] = nums[numsSize-2-i];
//        }
//        nums[0] = tmp;
//    }*/
//    //2.空间复杂度不满足
//    //int* pn = (int*)malloc(sizeof(int)*numsSize);
//    //3.三步翻转法
//    k %= numsSize;
//    reverse(nums, 0, numsSize - k - 1);
//    reverse(nums, numsSize - k, numsSize - 1);
//    reverse(nums, 0, numsSize - 1);
//
//}

//86.分割链表
/*typedef struct ListNode ListNode;
struct ListNode* partition(struct ListNode* head, int x)
{
    //给less,greater开一个哨兵位
    ListNode* lessHead = (Node*)malloc(sizeof(Node));
    ListNode* greaterHead = (Node*)malloc(sizeof(Node));
    ListNode* lessTail = lessHead;
    ListNode* greaterTail = greaterHead;
    //初始化两个链表中的next
    lessHead->next = greaterHead->next = NULL;
    //把小于x的分到less链表，大于等于x的分到greater链表
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

    //将less的尾与greater的头链接
    lessTail->next = greaterHead->next;
    //将greater的尾中的next置空
    greaterTail->next = NULL;

    ListNode* list = lessHead->next;
    //释放
    free(lessHead);
    free(greaterHead);
    return list;
}*/

//234.回文链表
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
    //从中间位置开始
    Node* fast = head;
    Node* slow = head;
    Node* prev = NULL;
    while (fast && fast->next)
    {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    //判定仅有一个元素的情况
    if (prev == NULL)
        return true;
    //将左右断开链接
    prev->next = NULL;
    //逆置右部链表
    slow = reverseList(slow);
    //判定右部逆置后是否与左部相等
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

//160.相交链表
/*typedef struct ListNode ListNode;
struct ListNode* getIntersectionNode(struct ListNode* headA, struct ListNode* headB)
{
    //求A链表长度
    ListNode* curA = headA;
    int la = 0;
    while (curA)
    {
        la++;
        curA = curA->next;
    }
    //求B链表长度
    ListNode* curB = headB;
    int lb = 0;
    while (curB)
    {
        lb++;
        curB = curB->next;
    }

    //分出长短链表
    ListNode* longlist = headA;
    ListNode* shortlist = headB;
    if (lb > la)
    {
        longlist = headB;
        shortlist = headA;
    }

    //求A，B链表差值的绝对值
    int gap = abs(la - lb);
    //让长链表走到离交点相同距离的位置
    while (gap--)
        longlist = longlist->next;
    //两个链表一起走
    while (longlist)
    {
        if (longlist == shortlist)
            return longlist;

        longlist = longlist->next;
        shortlist = shortlist->next;
    }
    return NULL;
}*/

//141.环形链表
//typedef struct ListNode ListNode;
//bool hasCycle(struct ListNode* head)
//{
//    ListNode* slow = head;
//    ListNode* fast = head;
//    while (fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        /*如果fast一次走3步，当slow进环时，假设它们之间的距离为X,每走一次，他们之间
//        * 举例缩小2，如果X是奇数就会导致错过，不能相遇。如果错过之后，再算差距还是奇
//        * 数，就会导致下一次还是错过，如果极端情况下每次差距都是奇数，就会一直错过，
//        * 无法相遇，死循环。
//        * 一次走N步也是类似的道理
//        */
//        if (slow == fast)
//            return true;
//    }
//    return false;
//}

//142.环形链表Ⅱ
/*typedef struct ListNode ListNode;
struct ListNode* detectCycle(struct ListNode* head)
{
    ListNode* slow, * fast;
    slow = fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        //判断是否相遇
        if (fast == slow)
            break;
    }
    //若相遇，则跳过此条件
    if (fast == NULL || fast->next == NULL)
        return NULL;

    //让相遇节点与第一个节点同时走
    //slow走的距离：LS = L+X
    //fast走的距离：LF = L+N*C+X
    //而2*(L+X) = L+N*C+X
    //L = N*C-X
    //两个再次相遇的节点即为环的开始点

    ListNode* meet = fast;
    while (head != meet)
    {
        head = head->next;
        meet = meet->next;
    }

    return meet;
}*/