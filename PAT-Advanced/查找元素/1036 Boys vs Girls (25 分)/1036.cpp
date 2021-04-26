#include <iostream>
#include <algorithm>
using namespace std;
struct student
{
    char name[11];
    char id[11];
    int gender = 0;
    int score;
};
//男0 女1 从男到女排，从小到大排
bool cmp(student &a, student &b)
{
    if (a.gender == b.gender)
    {
        return a.score < b.score;
    }
    return a.gender < b.gender;
}
int main()
{
    int N;
    student students[102];
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char gender;
        scanf("%s %c %s %d", students[i].name, &gender, students[i].id, &students[i].score);
        if (gender == 'F')
            students[i].gender = 1;
    }
    sort(students, students + N, cmp);
    bool flag = true;
    if (students[N - 1].gender == 0)
    {
        printf("Absent\n");
        flag = false;
    }
    else
    {
        printf("%s %s\n", students[N - 1].name, students[N - 1].id);
    }

    if (students[0].gender == 1)
    {
        flag = false;
        printf("Absent\n");
    }
    else
    {
        printf("%s %s\n", students[0].name, students[0].id);
    }
    if (flag)
    {
        printf("%d\n", students[N - 1].score - students[0].score);
    }
    else
    {
        printf("NA\n");
    }
    system("pause");
    return 0;
}