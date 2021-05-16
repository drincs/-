#include <iostream>
using namespace std;
int main()
{
    int n, m;
    int coins[1001] = {0};
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int value;
        scanf("%d", &value);
        coins[value]++;
    }
    //从1开始才能得到差异最大的方案
    bool find = false;
    for (int i = 1; i < 501; i++)
    {
        if (coins[i] > 0)
        {
            if (m - i == i)
            {
                if (coins[i] >= 2)
                {
                    find = true;
                    printf("%d %d\n", i, m - i);
                    break;
                }
            }
            else if (m - i > 0)
            {
                if (coins[m - i] > 0)
                {
                    find = true;
                    printf("%d %d\n", i, m - i);
                    break;
                }
            }
        }
    }
    if (!find)
    {
        printf("No Solution\n");
    }
    system("pause");
    return 0;
}