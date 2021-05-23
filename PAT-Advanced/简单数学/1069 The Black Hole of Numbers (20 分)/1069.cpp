#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
void toArray(int n, int num[])
{
    int i = 3;
    while (i >= 0)
    {
        num[i] = n % 10;
        n /= 10;
        i--;
    }
}
int toNum(int num[])
{
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        res = res * 10 + num[i];
    }
    return res;
}
bool cmp(int &a, int &b)
{
    return a > b;
}
int main()
{
    int n;
    int num[4];
    scanf("%d", &n);
    toArray(n, num);
    int nd2 = n, st1 = n;
    int diff = st1 - nd2;
    do
    {
        sort(num, num + 4);
        nd2 = toNum(num);
        sort(num, num + 4, cmp);
        st1 = toNum(num);
        diff = st1 - nd2;
        printf("%04d - %04d = %04d\n", st1, nd2, diff);
        toArray(diff, num);
    } while (nd2 != st1 && diff != 6174);
    system("pause");
    return 0;
}