#define _CRT_SECURE_NO_WARNINGS 1

//912.ÅÅÐòÊý×é
int* sortArray(int* nums, int numsSize, int* returnSize)
{
    int* retArr = (int*)malloc(sizeof(int) * numsSize);
    for (int i = 0; i < numsSize; ++i)
    {
        retArr[i] = nums[i];
    }
    int gap = numsSize;
    while (gap > 1)
    {
        gap = gap / 3 + 1;
        for (int i = 0; i < numsSize - gap; ++i)
        {
            int end = i;
            int x = retArr[end + gap];
            while (end >= 0)
            {
                if (retArr[end] > x)
                {
                    retArr[end + gap] = retArr[end];
                    end -= gap;
                }
                else
                    break;
            }
            retArr[end + gap] = x;
        }
    }
    *returnSize = numsSize;
    return retArr;
}