#include <iostream>
#include <math.h>
using namespace std;
const int MAXN = 10001;
int num[MAXN], add[MAXN], start[MAXN];
int main()
{
    int k;
    scanf("%d", &k);
    bool all_negative = true;
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &num[i]);
        if (num[i] >= 0 && all_negative)
        {
            all_negative = false;
        }
    }
    if (all_negative)
    {
        printf("%d %d %d\n", 0, num[0], num[k - 1]);
    }
    else
    {
        add[0] = num[0];
        start[0] = 0;
        int idx = 0, sum = add[0];
        for (int i = 1; i < k; i++)
        {
            //连续结果优于从当前位置开始
            if (add[i - 1] + num[i] >= num[i])
            {
                add[i] = add[i - 1] + num[i];
                start[i] = start[i - 1];
            }
            else
            {
                add[i] = num[i];
                start[i] = i;
            }
            if (add[i] > sum)
            {
                sum = add[i];
                idx = i;
            }
        }
        printf("%d %d %d\n", sum, num[start[idx]], num[idx]);
    }
    system("pause");
    return 0;
}