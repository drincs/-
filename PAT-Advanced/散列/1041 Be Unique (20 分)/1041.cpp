#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int bets[10001] = {0};
    int a[100001];
    int res = -1;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        bets[a[i]]++;
    }
    bool hasFind = false;
    for (int i = 0; i < n; i++)
    {
        if (bets[a[i]] == 1)
        {
            printf("%d\n", a[i]);
            hasFind = true;
            break;
        }
    }
    if (!hasFind)
        printf("None\n");

    system("pause");
    return 0;
}