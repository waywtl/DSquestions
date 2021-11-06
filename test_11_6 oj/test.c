#define _CRT_SECURE_NO_WARNINGS 1

//268.ÏûÊ§µÄÊı×Ö
int missingNumber(int* nums, int numsSize)
{
    int lostNum = 0;
    for (int i = 0; i < numsSize; i++)
        lostNum ^= nums[i];
    for (int i = 0; i <= numsSize; i++)
        lostNum ^= i;
    return lostNum;
}