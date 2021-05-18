#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    long long num[100001], p;
    int n;
    scanf("%d%ld", &n, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &num[i]);
    }
    sort(num, num + n);
    int res = 1;
    for (int i = 0; i < n; i++)
    {
        int min = num[i];
        long long x = min * p;
        int low = i + 1, high = n - 1;
        if (num[high] <= x)
        {
            low = n;
        }
        else
        {
            while (low < high)
            {
                int mid = (low + high) / 2;
                if (num[mid] <= x)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid;
                }
            }
        }
        if (res < (low - i))
            res = low - i;
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}