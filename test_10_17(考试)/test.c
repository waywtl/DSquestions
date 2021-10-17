#define _CRT_SECURE_NO_WARNINGS 1

//试卷选择题
//函数未定义是在 链接 过程中发现的

//试卷编程题
//1.一个数至少移动多少步变为斐波那契数(已完成)


//2.替换空格，将每个空格换成"%20"
//另开空间做
char* replaceSpace(char* s)
{
    if (s == NULL)
        return NULL;
    int prevLength = 0;
    int blank = 0;
    int i = 0;
    while (s[i] != '\0')
    {
        prevLength++;
        if (s[i] == ' ')
            blank++;
        i++;
    }
    int curLength = prevLength + blank * 2;
    
    char* pstr = (char*)malloc(sizeof(char) * curLength + 1);// + 1是因为要放'\0'
    pstr = strcpy(pstr, s);
    int pPrev = prevLength;
    int pCur = curLength;
    while (pPrev >= 0 && pCur > pPrev)
    {
        if (pstr[pPrev] == ' ')
        {
            pstr[pCur--] = '0';
            pstr[pCur--] = '2';
            pstr[pCur--] = '%';
        }
        else
        {
            pstr[pCur--] = pstr[pPrev];
        }
        pPrev--;
    }
    return pstr;
}