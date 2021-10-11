#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//一个整型数组 nums 里除两个数字之外，其他数字都出现了两次。
//请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
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


//写一个宏，可以将一个整数的二进制位的奇数位和偶数位交换。
/*#define SWAP_BIT(n) (n=((n&0xaaaaaaaa)>>1) + ((n&0x55555555)<<1))

int main()
{
	int a = 10;
	SWAP_BIT(a);
	printf("%d\n", a);
	return 0;
}*/


//offsetof宏,写一个宏，计算结构体中某变量相对于首地址的偏移，并给出说明
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