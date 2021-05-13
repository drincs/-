#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct student
{
    int id;
    char name[9];
    int grade;
};
bool cmp1(student &a, student &b)
{
    return a.id < b.id;
}
bool cmp2(student &a, student &b)
{
    if (strcmp(a.name, b.name) == 0)
    {
        return a.id < b.id;
    }
    return strcmp(a.name, b.name) < 0;
}
bool cmp3(student &a, student &b)
{
    if (a.grade == b.grade)
    {
        return a.id < b.id;
    }
    return a.grade < b.grade;
}
int main()
{
    int n, c;
    scanf("%d%d", &n, &c);
    vector<student> stu;
    for (int i = 0; i < n; i++)
    {
        student tmp;
        scanf("%d %s %d", &tmp.id, tmp.name, &tmp.grade);
        stu.push_back(tmp);
    }
    if (c == 1)
        sort(stu.begin(), stu.end(), cmp1);
    else if (c == 2)
        sort(stu.begin(), stu.end(), cmp2);
    else
        sort(stu.begin(), stu.end(), cmp3);
    for (int i = 0; i < stu.size(); i++)
    {
        printf("%06d %s %d\n", stu[i].id, stu[i].name, stu[i].grade);
    }
    system("pause");
    return 0;
}