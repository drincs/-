#include <iostream>
#include <algorithm>
using namespace std;
int num[100001];
int main()
{
    int n, p;
    scanf("%d%d", &n, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    int i = 0, j = 0, count = 1;
    while (i < n && j < n)
    {
        while (j < n && (long long)num[i] * p >= num[j])
        {
            if (j - i + 1 > count)
            {
                count = j - i + 1;
            }
            j++;
        }

        i++;
    }
    printf("%d\n", count);
    system("pause");
    return 0;
}