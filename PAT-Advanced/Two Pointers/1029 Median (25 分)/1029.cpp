#include <iostream>
using namespace std;
int main()
{
    int n1, n2;
    long long s1[200001], s2[200001];
    scanf("%d", &n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%ld", &s1[i]);
    }
    scanf("%d", &n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%ld", &s2[i]);
    }
    int mid = (n1 + n2 - 1) / 2;
    int p1 = 0, p2 = 0, p = 0;
    while (p1 < n1 && p2 < n2 && p < mid)
    {
        if (s1[p1] < s2[p2])
        {
            p1++;
        }
        else
        {
            p2++;
        }
        p++;
    }
    while (p1 < n1 && p < mid)
    {
        p1++;
        p++;
    }
    while (p2 < n2 && p < mid)
    {
        p2++;
        p++;
    }
    long long num = 0;
    if (p1 < n1 && p2 < n2)
    {
        num = s1[p1] < s2[p2] ? s1[p1] : s2[p2];
    }
    else
    {
        if (p1 < n1)
            num = s1[p1];
        else
            num = s2[p2];
    }
    printf("%ld\n", num);
    system("pause");
    return 0;
}