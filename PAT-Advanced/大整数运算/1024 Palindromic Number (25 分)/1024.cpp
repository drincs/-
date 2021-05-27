#include <iostream>
#include <cstring>
using namespace std;
bool isPalindromic(int n[], int len)
{
    for (int i = 0; i <= len / 2; i++)
    {
        if (n[i] != n[len - 1 - i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    char in[1010];
    int n[1010] = {0};
    int res[1010] = {0};
    int k;
    scanf("%s %d", in, &k);
    int len = strlen(in);
    for (int j = 0; j < len; j++)
    {
        n[j] = in[len - 1 - j] - '0';
        res[j] = in[len - 1 - j] - '0';
    }
    int i = 0;
    for (i; i < k; i++)
    {
        if (isPalindromic(n, len))
        {
            break;
        }
        int c = 0;
        int j = 0;
        for (j; j < len; j++)
        {
            int tmp = n[j] + n[len - 1 - j] + c;
            res[j] = tmp % 10;
            c = tmp / 10;
        }
        while (c > 0)
        {
            res[j++] = c % 10;
            c /= 10;
        }
        memcpy(n, res, 1010);
        len = j;
    }
    for (int j = 0; j < len; j++)
    {
        printf("%d", res[len - j - 1]);
    }
    printf("\n");
    printf("%d\n", i);
    system("pause");
    return 0;
}