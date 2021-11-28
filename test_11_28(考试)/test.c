#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
    char a[20] = { 0 };
    scanf("%s", a);
    int length = 0;
    for (int i = 0; i < 20; ++i)
    {
        if (a[i] != 0)
            length++;
    }

    for (int i = 0; i < length - 1; ++i)
    {
        char x = a[i + 1];
        int end = i;
        while (end >= 0)
        {
            if (a[end] > x)
            {
                a[end + 1] = a[end];
                end--;
            }
            else
                break;
        }
        a[end + 1] = x;
    }

    for (int i = 0; i < length; ++i)
    {
        printf("%c", a[i]);
    }
    return 0;
}