#include <iostream>
using namespace std;
int main()
{
    int n, b; //10^9 转2 <36位
    int toB[37];
    scanf("%d%d", &n, &b);
    int pos = 0;
    while (n > 0)
    {
        toB[pos++] = n % b;
        n /= b;
    }
    bool isP = true;
    for (int i = 0; i < pos / 2; i++)
    {
        if (toB[i] != toB[pos - 1 - i])
        {
            isP = false;
            break;
        }
    }
    if (isP)
        printf("Yes\n");
    else
        printf("No\n");
    printf("%d", toB[pos - 1]);
    for (int i = pos - 2; i >= 0; i--)
    {
        printf(" %d", toB[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}