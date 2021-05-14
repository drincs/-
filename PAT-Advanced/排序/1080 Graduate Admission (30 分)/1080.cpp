#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct student
{
    int id;
    int ge;
    int gi;
    int total;
    int rank;
    int k[5];
};
struct school
{
    int id;
    vector<int> stu;
    int num;
    int in_num = 0;
    bool stop = false;
    school(int id, int num)
    {
        this->id = id;
        this->num = num;
    }
};
bool cmp(student &a, student &b)
{
    if (a.total == b.total)
    {
        return a.ge > b.ge;
    }
    return a.total > b.total;
}
int main()
{
    int n, m, k, all = 0;
    scanf("%d%d%d", &n, &m, &k);
    vector<student> students;
    vector<school> schools;
    for (int i = 0; i < m; i++)
    {
        int num;
        scanf("%d", &num);
        school a(i, num);
        all += num;
        schools.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        student tmp;
        tmp.id = i;
        scanf("%d%d", &tmp.ge, &tmp.gi);
        for (int j = 0; j < k; j++)
        {
            scanf("%d", &tmp.k[j]);
        }
        tmp.total = tmp.ge + tmp.gi;
        students.push_back(tmp);
    }
    sort(students.begin(), students.end(), cmp);
    student current = students[0];
    for (int i = 0; i < n; i++)
    {
        if (current.total == students[i].total)
        {
            if (current.ge > students[i].ge)
            {
                // 不同排名进入下一轮
                // 更新学校状态
                for (int j = 0; j < m; j++)
                {
                    if (schools[j].in_num >= schools[j].num)
                    {
                        schools[j].stop = true;
                    }
                }
                current = students[i];
            }
        }
        else
        {
            // 不同排名进入下一轮
            // 更新学校状态
            for (int j = 0; j < k; j++)
            {
                if (schools[j].in_num >= schools[j].num)
                {
                    schools[j].stop = true;
                }
            }
            current = students[i];
        }
        for (int j = 0; j < k; j++)
        {
            if (!schools[students[i].k[j]].stop)
            {
                schools[students[i].k[j]].stu.push_back(students[i].id);
                schools[students[i].k[j]].in_num++;
                break;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (schools[i].stu.size() == 0)
            printf("\n");
        else
        {
            sort(schools[i].stu.begin(), schools[i].stu.end());
            for (int j = 0; j < schools[i].in_num; j++)
            {
                if (j != 0)
                    printf(" ");
                printf("%d", schools[i].stu[j]);
            }
            printf("\n");
        }
    }
    system("pause");
    return 0;
}