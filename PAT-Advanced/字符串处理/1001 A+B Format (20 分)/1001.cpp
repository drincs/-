#include <iostream>
using namespace std;
int main()
{
    int A, B;
    int res[8];
    scanf("%d%d", &A, &B);
    int C = A + B;
    int sign = C >= 0 ? 1 : -1;
    if (sign < 0)
    {
        C *= -1;
        printf("-");
    }

    int pos = 0;
    if (C == 0)
    {
        printf("0\n");
        return 0;
    }
    while (C > 0)
    {
        res[pos++] = C % 10;
        C /= 10;
    }
    //倒序输出 计算最前面需跳过个数
    int skip = pos % 3 == 0 ? 3 : pos % 3;
    int t = 2;
    for (int i = pos - 1; i >= 0; i--)
    {
        if (skip > 0)
        {
            skip--;
        }
        else
        {
            //间隔三位输出，
            t++;
            if (i >= 2 && t == 3)
            {
                printf(",");
                t = 0;
            }
        }
        printf("%d", res[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}