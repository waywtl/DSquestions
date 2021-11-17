#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Swap(int* px, int* py)
{
	int tmp = *px;
	*px = *py;
	*py = tmp;
}

int GetMidIndex(int* a, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (a[left] > a[mid])
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
}

int Partion(int* a, int left, int right)
{
	int midi = GetMidIndex(a, left, right);
	Swap(&a[left], &a[midi]);

	int key = a[left];
	int pivot = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			--right;
		}
		a[pivot] = a[right];
		pivot = right;
		while (left < right && a[left] <= key)
		{
			++left;
		}
		a[pivot] = a[left];
		pivot = left;
	}
	a[pivot] = key;
	return pivot;
}

void QuickSort(int* a, int left, int right)
{
	if (left >= right)
		return;
	int keyi = Partion( a, left, right);
	QuickSort(a, left, keyi - 1);
	QuickSort(a, keyi + 1, right);
}

int main()
{
	int a[] = { 47,12,38,69,71,52,86,45,20,64 };
	QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
	return 0;
}