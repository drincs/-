#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> nums;
int main()
{
    int m, n, u, v, x;
    scanf("%d%d", &m, &n);
    vector<int> p(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
        nums[p[i]] = true;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        for (int j = 0; j < n; j++)
        {
            x = p[j];
            if ((x <= u && x >= v) || (x <= v && x >= u))
            {
                break;
            }
        }
        if (nums[u] == false && nums[v] == false)
        {
            printf("ERROR: %d and %d are not found.\n", u, v);
        }
        else if (nums[u] == false || nums[v] == false)
        {
            printf("ERROR: %d is not found.\n", nums[u] == false ? u : v);
        }
        else
        {
            if (x == u || x == v)
            {
                printf("%d is an ancestor of %d.\n", x, x == u ? v : u);
            }
            else
            {
                printf("LCA of %d and %d is %d.\n", u, v, x);
            }
        }
    }
    system("pause");
    return 0;
}