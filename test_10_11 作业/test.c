#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//һ���������� nums �����������֮�⣬�������ֶ����������Ρ�
//��д�����ҳ�������ֻ����һ�ε����֡�Ҫ��ʱ�临�Ӷ���O(n)���ռ临�Ӷ���O(1)��
/*int* singleNumbers(int* nums, int numsSize, int* returnSize)
{
    int ret = 0;
    for (int i = 0; i < numsSize; i++)
    {
        ret ^= nums[i];
    }

    int pos = 0;
    for (int i = 0; i < sizeof(int) * 8; i++)
    {
        if ((ret >> i) & 1 == 1)
        {
            pos = i;
            break;
        }
    }

    int m = 0;
    int n = 0;
    for (int i = 0; i < numsSize; i++)
    {
        int tmp = nums[i];
        tmp = tmp >> pos;
        if ((tmp & 1) == 1)
        {
            m ^= nums[i];
        }
        else
        {
            n ^= nums[i];
        }
        *returnSize = 2;
    }
    int* singleNums = (int*)malloc(sizeof(int) * 2);
    singleNums[0] = m;
    singleNums[1] = n;
    return singleNums;
}*/


//дһ���꣬���Խ�һ�������Ķ�����λ������λ��ż��λ������
/*#define SWAP_BIT(n) (n=((n&0xaaaaaaaa)>>1) + ((n&0x55555555)<<1))

int main()
{
	int a = 10;
	SWAP_BIT(a);
	printf("%d\n", a);
	return 0;
}*/


//offsetof��,дһ���꣬����ṹ����ĳ����������׵�ַ��ƫ�ƣ�������˵��
#define OFFSETOF(struct_name, member_name) (int)&(((struct_name*)0)->member_name)

struct Stu
{
	int a;
	char c;
	double d;
};

int main()
{
	printf("%d\n", OFFSETOF(struct Stu,a));
	printf("%d\n", OFFSETOF(struct Stu,c));
	printf("%d\n", OFFSETOF(struct Stu,d));
	return 0;
}