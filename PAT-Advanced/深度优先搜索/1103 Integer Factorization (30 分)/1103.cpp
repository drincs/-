#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> res, factor;
int N, K, P, e, maxfs = -1;
vector<int> fac;
int power(int i)
{
    int res = 1;
    for (int j = 0; j < P; j++)
    {
        res *= i;
    }
    return res;
}
void initFac()
{
    int i = 0, temp = 0;
    while (temp <= N)
    {
        fac.push_back(temp);
        temp = power(++i);
    }
}
void dfs(int now, int count, int sum, int fs)
{
    if (sum == N && count == K)
    {

        if (fs > maxfs)
        {
            maxfs = fs;
            res = factor;
        }
        return;
    }
    if (sum > N || count > K)
    {
        return;
    }
    if (now >= 1)
    {
        //加入
        factor.push_back(now);
        dfs(now, count + 1, sum + fac[now], fs + now);
        //不加入
        //下一个数字
        factor.pop_back();
        if (now > 1)
            dfs(now - 1, count, sum, fs);
    }
}
int main()
{
    scanf("%d%d%d", &N, &K, &P);
    initFac();
    //e = floor(pow(N * 1.0, 1 / (P * 1.0)));
    dfs(fac.size() - 1, 0, 0, 0);
    if (maxfs == -1)
    {
        printf("Impossible\n");
    }
    else
    {
        vector<int>::iterator it = res.begin();
        printf("%d = ", N);
        for (it; it != res.end(); it++)
        {
            if (it != res.begin())
                printf(" + ");
            printf("%d^%d", *it, P);
        }
        printf("\n");
    }
    system("pause");
    return 0;
}