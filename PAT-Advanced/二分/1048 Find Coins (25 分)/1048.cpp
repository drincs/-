#include <iostream>
#include <algorithm>
using namespace std;
int num[100001];
int binarySearch(int l, int r, int target)
{
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (num[mid] == target)
        {
            return 1;
        }
        else if (num[mid] > target)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    sort(num, num + n);
    int find = 0;
    for (int i = 0; i < n; i++)
    {
        int left = binarySearch(0, i - 1, m - num[i]);
        int right = binarySearch(i + 1, n - 1, m - num[i]);
        if (left == 1 || right == 1)
        {
            find = 1;
            printf("%d %d\n", num[i], m - num[i]);
            break;
        }
    }
    if (find == 0)
    {
        printf("No Solution\n");
    }
    system("pause");
    return 0;
}