#define _CRT_SECURE_NO_WARNINGS 1

//剑指Offer 03.数组中重复的数字
/*int findRepeatNumber(int* nums, int numsSize)
{
    for (int i = 0; i < numsSize; i++)
    {
        while (nums[i] != i)
        {
            if (nums[i] == nums[nums[i]])
            {
                return nums[i];
            }
            else
            {
                int tmp = nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
    }
    return NULL;
}*/

//453.最小操作次数是数组元素相等
//以相对大小变化来看，每次使n-1个元素增加1，相当于使一个元素减少1
int minMoves(int* nums, int numsSize)
{
    int i = 0;
    int min = nums[0];
    int num = 0;
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] < min)
            min = nums[i];
        num += nums[i];
    }
    return num - min * numsSize;
}