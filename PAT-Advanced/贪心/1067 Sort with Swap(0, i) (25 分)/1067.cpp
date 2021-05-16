#include <iostream>
using namespace std;
int main()
{
    int n;
    int p[100001];
    scanf("%d", &n);
    int error = n - 1;
    int num;
    int next = 1;
    int step = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num);
        p[num] = i;
        if (num == i && num != 0)
        {
            error--;
        }
    }
    while (error > 0)
    {
        //0有序
        if (p[0] == 0)
        {
            while (next < n)
            {
                if (next != p[next])
                {
                    swap(p[0], p[next]);
                    step++;
                    break;
                }
                next++;
            }
        }
        while (p[0] != 0)
        {
            swap(p[0], p[p[0]]);
            step++;
            error--;
        }
    }
    printf("%d\n", step);
    system("pause");
    return 0;
}