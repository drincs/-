#include <iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d", &n);
    int i = 1;
    int res = 0;
    while (n / i > 0)
    {
        int left = n / (i * 10);
        int right = n % i;
        int pos = n / i % 10;
        if (pos == 0)
        {
            //最后一组右边不可过界
            res += left * i;
        }
        else if (pos == 1)
        {
            res += left * i + 1 + right;
        }
        else
        {
            res += (left + 1) * i;
        }
        i *= 10;
    }
    printf("%d\n", res);
    system("pause");
    return 0;
}