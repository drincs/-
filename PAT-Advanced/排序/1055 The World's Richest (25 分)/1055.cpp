#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct person
{
    char name[9];
    int age;
    int worth;
};
bool cmp(person &a, person &b)
{
    if (a.worth == b.worth)
    {
        if (a.age == b.age)
        {
            return strcmp(a.name, b.name) < 0;
        }
        return a.age < b.age;
    }
    return a.worth > b.worth;
}
int main()
{
    int n, k;
    vector<person> pers;
    vector<person> ranks;
    int ages[201] = {0};
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        person t;
        scanf("%s %d %d", t.name, &t.age, &t.worth);
        pers.push_back(t);
    }
    sort(pers.begin(), pers.end(), cmp);
    //m<=100 每个年龄只有前100的人才参加排名 就像我 没有资格
    for (int i = 0; i < n; i++)
    {
        if (ages[pers[i].age] < 100)
        {
            ages[pers[i].age]++;
            ranks.push_back(pers[i]);
        }
    }
    for (int i = 1; i <= k; i++)
    {
        int m, young, old;
        int hasPrint = 0;
        scanf("%d%d%d", &m, &young, &old);
        printf("Case #%d:\n", i);
        for (int j = 0; hasPrint < m && j < ranks.size(); j++)
        {
            if (young <= ranks[j].age && old >= ranks[j].age)
            {
                //输出前m个
                printf("%s %d %d\n", ranks[j].name, ranks[j].age, ranks[j].worth);
                hasPrint++;
            }
        }
        if (hasPrint == 0)
            printf("None\n");
    }
    system("pause");
    return 0;
}