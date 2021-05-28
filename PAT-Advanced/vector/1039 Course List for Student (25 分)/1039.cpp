#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int M = 26 * 26 * 26 * 10 + 1;
const int N = 40000;
int getId(char name[])
{
    int id = 0;
    for (int i = 0; i < 3; i++)
    {
        id = id * 26 + (name[i] - 'A');
    }
    id = id * 10 + (name[3] - '0');
    return id;
}
vector<int> stu[M];
int main()
{
    int n, k;
    char name[5];
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; i++)
    {
        int course, x;
        scanf("%d%d", &course, &x);
        for (int j = 0; j < x; j++)
        {
            scanf("%s", name);
            int id = getId(name);
            stu[id].push_back(course);
        }
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%s", name);
        int id = getId(name);
        sort(stu[id].begin(), stu[id].end());
        printf("%s %d", name, stu[id].size());
        for (int j = 0; j < stu[id].size(); j++)
        {
            printf(" %d", stu[id][j]);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}