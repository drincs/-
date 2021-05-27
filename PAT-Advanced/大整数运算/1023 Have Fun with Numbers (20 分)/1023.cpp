#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n[22], res[22], num_n[10] = {0}, num_s[10] = {0};
    char in[22];
    scanf("%s", in);
    int len_n = strlen(in);
    for (int i = len_n - 1; i >= 0; i--)
    {
        n[len_n - 1 - i] = in[i] - '0';
        num_n[n[len_n - 1 - i]]++;
    }
    int carry = 0;
    int len_s = 0;
    for (len_s; len_s < len_n; len_s++)
    {
        int tmp = n[len_s] * 2 + carry;
        carry = tmp / 10;
        res[len_s] = tmp % 10;
        num_s[res[len_s]]++;
    }
    while (carry > 0)
    {
        res[len_s++] = carry % 10;
        num_s[carry % 10]++;
        carry /= 10;
    }
    int j = 0;
    for (j; j < 10; j++)
    {
        if (num_n[j] != num_s[j])
        {
            break;
        }
    }
    if (j == 10)
        printf("Yes\n");
    else
        printf("No\n");
    for (int i = 0; i < len_s; i++)
    {
        printf("%d", res[len_s - 1 - i]);
    }
    printf("\n");
    system("pause");
    return 0;
}