#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int K = 2501;
const int N = 40010;
vector<int> course[K];
char name[N][5];
bool cmp(int &a, int &b)
{
    return strcmp(name[a], name[b]) < 0;
}
int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        int x;
        scanf("%s%d", name[i], &x);
        for (int j = 0; j < x; j++)
        {
            int id;
            scanf("%d", &id);
            course[id].push_back(i);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        printf("%d %d\n", i, course[i].size());
        sort(course[i].begin(), course[i].end(), cmp);
        for (int j = 0; j < course[i].size(); j++)
        {
            printf("%s\n", name[course[i][j]]);
        }
    }
    system("pause");
    return 0;
}