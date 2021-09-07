#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> zz(n + 1);
    for (int i = 1; i <= n; i++)
    {
        char a;
        int b;
        scanf("%c%d", &a, &b);
        if (a == '-')
        {
            zz[i] = -1 * b;
        }
        else
        {
            zz[i] = b;
        }
    }
    bool flag = false;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            //狼人标识
            vector<int> ss(n + 1, 1);
            ss[i] = -1;
            ss[j] = -1;
            int liarhaoren = 0;
            int liarlangren = 0;
            for (int i = 1; i <= n; i++)
            {
                int point = abs(zz[i]);
                if (ss[i] > 0)
                {
                    if (ss[point] * zz[i] < 0)
                    {
                        liarhaoren++;
                    }
                }
                else
                {
                    if (ss[point] * zz[i] < 0)
                    {
                        liarlangren++;
                    }
                }
            }
            if (liarlangren == 1 && liarhaoren == 1)
            {
                printf("%d %d\n", i, j);
                flag = true;
                break;
            }
        }
        if (flag)
        {
            break;
        }
    }
    if (!flag)
    {
        printf("No Solution\n");
    }
    system("pause");
    return 0;
}