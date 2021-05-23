#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, m;
    int coins[100001];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &coins[i]);
    }
    sort(coins, coins + n);
    int left = 0, right = n - 1;
    while (left < right)
    {
        if (coins[left] + coins[right] < m)
        {
            left++;
        }
        else if (coins[left] + coins[right] > m)
        {
            right--;
        }
        else
        {
            break;
        }
    }
    if (left == right)
    {
        printf("No Solution\n");
    }
    else
    {
        printf("%d %d\n", coins[left], coins[right]);
    }
    system("pause");
    return 0;
}