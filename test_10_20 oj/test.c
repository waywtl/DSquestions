#define _CRT_SECURE_NO_WARNINGS 1

//��ָOffer 03.�������ظ�������
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

//453.��С��������������Ԫ�����
//����Դ�С�仯������ÿ��ʹn-1��Ԫ������1���൱��ʹһ��Ԫ�ؼ���1
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