#include <iostream>
#include <queue>
using namespace std;
struct player
{
    int weight;
    int rank;
};
int main()
{
    int p, g;
    scanf("%d%d", &p, &g);
    player players[1001];
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &players[i].weight);
    }
    queue<int> q;
    for (int i = 0; i < p; i++)
    {
        int t;
        scanf("%d", &t);
        q.push(t);
    }
    int tmp = p, group;
    while (q.size() != 1)
    {
        if (tmp % g == 0)
        {
            group = tmp / g;
        }
        else
        {
            group = tmp / g + 1;
        }
        //共group个组
        for (int i = 0; i < group; i++)
        {
            int k = q.front();
            for (int j = 0; j < g; j++)
            {
                if (i * g + j >= tmp)
                    break;
                int front = q.front();
                if (players[front].weight > players[k].weight)
                {
                    k = front;
                }
                players[front].rank = group + 1;
                q.pop();
            }
            //晋级继续排队尾
            q.push(k);
        }
        tmp = group;
    }
    players[q.front()].rank = 1;
    for (int i = 0; i < p; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", players[i].rank);
    }
    printf("\n");
    system("pause");
    return 0;
}