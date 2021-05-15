#include <iostream>
using namespace std;
int main()
{
    char shop[1001];
    char eva[1001];
    int breads[128] = {0};
    bool buy = true;
    int num = 0;
    int miss = 0;
    scanf("%s%s", shop, eva);
    for (int i = 0; shop[i] != '\0'; i++)
    {
        breads[shop[i]]++;
        num++;
    }
    for (int i = 0; eva[i] != '\0'; i++)
    {
        breads[eva[i]]--;
        num--;
        if (breads[eva[i]] < 0)
        {
            buy = false;
            miss++;
        }
    }
    if (buy)
    {
        printf("Yes %d\n", num);
    }
    else
    {
        printf("No %d\n", miss);
    }
    system("pause");
    return 0;
}