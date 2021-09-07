#include <iostream>
using namespace std;
const int maxn = 100002;
bool table[maxn];
int main()
{
    int n;
    scanf("%d", &n);
    fill(table, table + maxn, true);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%d", &x);
        if (x > 0 && x < 100002)
        {
            table[x] = false;
        }
    }
    int j = 1;
    while (!table[j])
    {
        j++;
    }
    printf("%d\n", j);
    system("pause");
    return 0;
}