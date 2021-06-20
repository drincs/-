#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct edge
{
    int x;
    int y;
};
vector<edge> edges;
int main()
{
    int n, m, k;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        edge t;
        scanf("%d %d", &t.x, &t.y);
        if (t.x != t.y)
            edges.push_back(t);
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        vector<int> color;
        set<int> maxk;
        for (int j = 0; j < n; j++)
        {
            int t;
            scanf("%d", &t);
            color.push_back(t);
            maxk.insert(t);
        }
        bool isColor = true;
        for (int j = 0; j < m; j++)
        {
            if (color[edges[j].x] == color[edges[j].y])
            {
                isColor = false;
                break;
            }
        }
        if (isColor)
            printf("%d-coloring\n", maxk.size());
        else
            printf("No\n");
    }
    system("pause");
    return 0;
}
