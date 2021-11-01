#define _CRT_SECURE_NO_WARNINGS 1

//575.·ÖÌÇ¹û
/*int com_int(const void* e1, const void* e2)
{
    return *(int*)e1 - *(int*)e2;
}

int distributeCandies(int* candyType, int candyTypeSize)
{
    qsort(candyType, candyTypeSize, sizeof(int), com_int);
    int p1 = 0;
    int p2 = 1;
    int typeNum = 1;
    while (p2 != candyTypeSize)
    {
        if (candyType[p1] == candyType[p2])
            p2++;
        else
        {
            typeNum++;
            p1 = p2;
            p2++;
        }
    }
    int ret = typeNum > (candyTypeSize / 2) ? (candyTypeSize / 2) : typeNum;
    return ret;
}*/
