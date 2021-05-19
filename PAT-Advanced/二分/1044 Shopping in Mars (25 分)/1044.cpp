#include <iostream>
using namespace std;
int n, m;
int chain[100002];
int sum[100002];
int cost = 100000001;
int binarySearch(int l, int r, int target)
{
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (sum[mid] > target)
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &sum[i]);
        sum[i] = sum[i] + sum[i - 1];
    }
    //先找cost
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = n + 1;
        int j = binarySearch(l, r, sum[l - 1] + m);
        if (sum[j - 1] - sum[i - 1] == m)
        {
            cost = m;
            break;
        }
        else if (j <= n && sum[j - 1] - sum[i - 1] < cost)
        {
            cost = sum[j] - sum[i - 1];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = n + 1;
        int j = binarySearch(l, r, sum[l - 1] + cost);
        if (sum[j - 1] - sum[i - 1] == cost)
        {
            printf("%d-%d\n", i, j - 1);
        }
    }
    system("pause");
    return 0;
}