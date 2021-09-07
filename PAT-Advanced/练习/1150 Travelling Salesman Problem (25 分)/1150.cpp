#include <iostream>
#include <vector>
using namespace std;
int arr[201][201];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    fill(arr[0], arr[0] + 201 * 201, -1);
    for (int i = 0; i < m; i++)
    {
        int c1, c2, d;
        scanf("%d%d%d", &c1, &c2, &d);
        arr[c1][c2] = d;
        arr[c2][c1] = d;
    }
    int q;
    int index = 1;
    int minD;
    scanf("%d", &q);
    for (int i = 1; i <= q; i++)
    {
        int k;
        scanf("%d", &k);
        if (k == 0)
        {
            printf("Path %d: NA (Not a TS cycle)\n", i);
            continue;
        }
        else
        {
            int total = 0;
            int x, y, z;
            scanf("%d", &x);
            y = x;
            bool NA = false;
            vector<bool> all(n + 1, false);
            all[x] = true;
            for (int j = 1; j < k; j++)
            {
                scanf("%d", &z);
                if (arr[y][z] > 0 && NA == false)
                {
                    total += arr[y][z];
                    all[z] = true;
                    y = z;
                }
                else
                {
                    NA = true;
                }
            }
            if (!NA)
            {
                bool cycle = true;
                for (int ii = 1; ii <= n; ii++)
                {
                    if (!all[ii])
                    {
                        cycle = false;
                        break;
                    }
                }
                if (!cycle || x != y)
                    printf("Path %d: %d (Not a TS cycle)\n", i, total);
                else
                {
                    if (k == n + 1)
                    {
                        printf("Path %d: %d (TS simple cycle)\n", i, total);
                    }
                    else
                    {
                        printf("Path %d: %d (TS cycle)\n", i, total);
                    }
                    if (i == 1)
                    {
                        minD = total;
                    }
                    if (total < minD)
                    {
                        minD = total;
                        index = i;
                    }
                }
            }
            else
            {
                printf("Path %d: NA (Not a TS cycle)\n", i);
            }
        }
    }
    printf("Shortest Dist(%d) = %d\n", index, minD);

    system("pause");
    return 0;
}