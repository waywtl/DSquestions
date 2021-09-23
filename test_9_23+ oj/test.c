#define _CRT_SECURE_NO_WARNINGS 1

//26.删除有序数组中的重复项
//int removeDuplicates(int* nums, int numsSize)
//{
//    if (numsSize == 0)
//    {
//        return 0;
//    }
//    int src = 1, dest = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != nums[dest])
//        {
//            nums[dest + 1] = nums[src];
//            src++;
//            dest++;
//        }
//        else
//        {
//            src++;
//        }
//    }
//    return (dest + 1);
//}

//27.移除元素
//int removeElement(int* nums, int numsSize, int val)
//{
//    int src = 0, dest = 0;
//    while (src < numsSize)
//    {
//        if (nums[src] != val)
//        {
//            nums[dest] = nums[src];
//            src++;
//            dest++;
//        }
//        else
//        {
//            src++;
//        }
//    }
//    return dest;
//}

//989.数组形式的整数加法
//int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
//{
//    int KSize = 0;
//    int kNum = k;
//    while (kNum)
//    {
//        KSize++;
//        kNum /= 10;
//    }
//    int len = numSize > KSize ? numSize : KSize;
//    int* retArr = (int*)malloc(sizeof(int) * (len + 1));
//
//    int Ni = numSize - 1;
//    int reti = 0;
//    int nextNum = 0;
//    while (len--)
//    {
//        int N = 0;
//        if (Ni >= 0)
//        {
//            N = num[Ni];
//            Ni--;
//        }
//        int ret = N + k % 10 + nextNum;
//        k /= 10;
//
//        if (ret > 9)
//        {
//            ret -= 10;
//            nextNum = 1;
//        }
//        else
//        {
//            nextNum = 0;
//        }
//        retArr[reti] = ret;
//        reti++;
//    }
//    if (nextNum == 1)
//    {
//        retArr[reti] = 1;
//        reti++;
//    }
//
//    int left = 0;
//    int right = reti - 1;
//    while (left < right)
//    {
//        int tmp = retArr[left];
//        retArr[left] = retArr[right];
//        retArr[right] = tmp;
//        left++;
//        right--;
//    }
//    *returnSize = reti;
//    return retArr;
//}