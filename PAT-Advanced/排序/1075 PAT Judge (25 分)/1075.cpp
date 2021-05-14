#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct user
{
    int id;
    int score = 0;
    bool isValid = false;
    int p[6] = {-1, -1, -1, -1, -1, -1};
    int full = 0;
    user(int id)
    {
        this->id = id;
    }
};
bool cmp(user &a, user &b)
{
    if (a.score == b.score)
    {
        if (a.full == b.full)
        {
            return a.id < b.id;
        }
        return a.full > b.full;
    }
    return a.score > b.score;
}
int main()
{
    int n, k, m;
    int p_full[6];
    vector<user> users;
    scanf("%d %d %d", &n, &k, &m);
    for (int i = 1; i <= k; i++)
    {
        scanf("%d", &p_full[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        user a(i);
        users.push_back(a);
    }
    //先确定排序用户名单（没提交 提交编译未通过的不参与排序）
    for (int i = 0; i < m; i++)
    {
        int id, pid, score;
        scanf("%d%d%d", &id, &pid, &score);
        if (users[id - 1].p[pid] < score && score > -1)
        {
            users[id - 1].isValid = true;
            users[id - 1].p[pid] = score;
        }
        //未编译通过的设成0便于后续输出
        if (score == -1 && users[id - 1].p[pid] == -1)
        {
            users[id - 1].p[pid] = 0;
        }
    }
    vector<user> ranklist;
    for (int i = 0; i < n; i++)
    {
        if (users[i].isValid)
        {
            for (int j = 1; j <= k; j++)
            {
                if (users[i].p[j] == p_full[j])
                {
                    users[i].full++;
                }
                if (users[i].p[j] > 0)
                    users[i].score += users[i].p[j];
            }
            ranklist.push_back(users[i]);
        }
    }
    sort(ranklist.begin(), ranklist.end(), cmp);
    int pos = 1;
    int current = ranklist[0].score;
    for (int i = 0; i < ranklist.size(); i++)
    {
        if (current > ranklist[i].score)
        {
            pos = 1 + i;
            current = ranklist[i].score;
        }
        printf("%d %05d %d", pos, ranklist[i].id, ranklist[i].score);
        for (int j = 1; j <= k; j++)
        {
            if (ranklist[i].p[j] == -1)
            {
                printf(" -");
            }
            else
            {
                printf(" %d", ranklist[i].p[j]);
            }
        }
        printf("\n");
    }
    system("pause");
    return 0;
}