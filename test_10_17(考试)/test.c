#define _CRT_SECURE_NO_WARNINGS 1

//�Ծ�ѡ����
//����δ�������� ���� �����з��ֵ�

//�Ծ�����
//1.һ���������ƶ����ٲ���Ϊ쳲�������(�����)


//2.�滻�ո񣬽�ÿ���ո񻻳�"%20"
//���ռ���
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
    
    char* pstr = (char*)malloc(sizeof(char) * curLength + 1);// + 1����ΪҪ��'\0'
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