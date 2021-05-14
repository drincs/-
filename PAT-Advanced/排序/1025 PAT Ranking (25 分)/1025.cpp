#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
struct testee
{
    char id[14];
    int score;
    int localRank;
    int localNo;
    int finalRank;
    testee(int localNo)
    {
        this->localNo = localNo;
    }
};
bool localcmp(testee &a, testee &b)
{
    if (a.localNo == b.localNo)
    {
        return a.score > b.score;
    }
    return a.localNo < b.localNo;
}
bool finalCmp(testee &a, testee &b)
{
    if (a.score == b.score)
    {
        return strcmp(a.id, b.id) < 0;
    }
    return a.score > b.score;
}
int main()
{
    int n;
    vector<testee> testees;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            testee test(i);
            char id[14];
            int score;
            scanf("%s %d", test.id, &test.score);
            testees.push_back(test);
        }
    }
    sort(testees.begin(), testees.end(), localcmp);
    int pos = 1;
    int local = 1;
    int current = testees[0].score;
    for (int i = 0; i < testees.size();)
    {
        int count = 1;
        while (testees[i].localNo == local)
        {
            if (testees[i].score < current)
            {
                pos = count;
                current = testees[i].score;
            }
            testees[i].localRank = pos;
            count++;
            i++;
        }
        pos = 1;
        local++;
        current = testees[i].score;
    }
    sort(testees.begin(), testees.end(), finalCmp);
    pos = 1;
    current = testees[0].score;
    int count = 1;
    for (int i = 0; i < testees.size(); i++)
    {
        if (testees[i].score < current)
        {
            pos = count;
            current = testees[i].score;
        }
        testees[i].finalRank = pos;
        count++;
    }
    printf("%d\n", testees.size());
    for (int i = 0; i < testees.size(); i++)
    {
        printf("%s %d %d %d\n", testees[i].id, testees[i].finalRank, testees[i].localNo, testees[i].localRank);
    }
    system("pause");
    return 0;
}