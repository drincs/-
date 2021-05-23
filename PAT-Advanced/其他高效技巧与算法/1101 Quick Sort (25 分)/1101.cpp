#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100001;
int main()
{
    int n;
    scanf("%d", &n);
    int num[MAXN];
    int smaller[MAXN] = {0};
    int larger[MAXN] = {0};
    int pivot[MAXN] = {0};
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        if (i == 0)
            smaller[i] = num[i];
        else
        {
            if (num[i] > smaller[i - 1])
            {
                smaller[i] = num[i];
            }
            else
            {
                smaller[i] = smaller[i - 1];
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1)
        {
            larger[i] = num[i];
        }
        else
        {
            if (num[i] > larger[i + 1])
            {
                larger[i] = larger[i + 1];
            }
            else
            {
                larger[i] = num[i];
            }
        }
        if (larger[i] == smaller[i])
        {
            pivot[count] = num[i];
            count++;
        }
    }
    sort(pivot, pivot + count);
    printf("%d\n", count);
    for (int i = 0; i < count; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", pivot[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}