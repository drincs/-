#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct student
{
    char name[11];
    char id[11];
    int grade;
};
bool cmp(student &a, student &b)
{
    return a.grade > b.grade;
}
int main()
{
    int n;
    vector<student> stu;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        student temp;
        scanf("%s %s %d", temp.name, temp.id, &temp.grade);
        stu.push_back(temp);
    }
    sort(stu.begin(), stu.end(), cmp);
    int low, high;
    scanf("%d%d", &low, &high);
    bool has = false;
    for (int i = 0; i < n; i++)
    {
        if (stu[i].grade >= low && stu[i].grade <= high)
        {
            printf("%s %s\n", stu[i].name, stu[i].id);
            has = true;
        }
    }
    if (!has)
        printf("NONE\n");
    system("pause");
    return 0;
}