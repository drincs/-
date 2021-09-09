#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
struct people
{
    int height;
    char name[10];
};
vector<people> all;
bool cmp(people &a, people &b)
{
    if (a.height == b.height)
    {
        return strcmp(a.name, b.name) < 0;
    }
    return a.height > b.height;
}
bool cmp2(int &a, int &b)
{
    if (all[a].height == all[b].height)
    {
        return strcmp(all[a].name, all[b].name) < 0;
    }
    return all[a].height > all[b].height;
}
int main()
{
    int n, rows;
    scanf("%d%d", &n, &rows);
    vector<vector<int>> group;
    for (int i = 0; i < n; i++)
    {
        people a;
        scanf("%s%d", a.name, &a.height);

        all.push_back(a);
    }
    sort(all.begin(), all.end(), cmp);
    int m = n / rows;
    vector<vector<int>> photo;
    for (int i = 0; i < rows; i++)
    {
        if (i == rows - 1)
        {
            group.push_back(vector<int>(n - m * (rows - 1)));
            photo.push_back(vector<int>(n - m * (rows - 1)));
        }
        else
        {
            group.push_back(vector<int>(m));
            photo.push_back(vector<int>(m));
        }
    }
    int pp = 0;
    for (int i = rows - 1; i >= 0; i--)
    {
        int p = photo[i].size() / 2;
        int sign = 1;
        for (int j = 0; j < photo[i].size(); j++)
        {
            int pos = p + sign * j;
            photo[i][pos] = pp++;
            sign *= -1;
            p = pos;
        }
    }
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = 0; j < photo[i].size(); j++)
        {
            if (j != 0)
                printf(" ");
            printf("%s", all[photo[i][j]].name);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}