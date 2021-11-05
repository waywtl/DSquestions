#define _CRT_SECURE_NO_WARNINGS 1

//1218.最长定差子序列
int longestSubsequence(int* arr, int arrSize, int difference)
{
    int maxLength = 1;
    for (int i = 0; i < arrSize; i++)
    {
        int cur = i;
        int next = cur + 1;
        int length = 1;
        while (next < arrSize)
        {
            if (arr[next] - arr[cur] != difference)
                next++;
            else
            {
                length++;
                cur = next;
                next++;
            }
        }
        maxLength = length > maxLength ? length : maxLength;
    }
    return maxLength;
}