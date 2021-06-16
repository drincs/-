#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    int head, n, k;
    int data[100000];
    int list[100000];
    int next[100000];
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++)
    {
        int addr, a, b;
        scanf("%d", &addr);
        scanf("%d%d", &a, &b);
        data[addr] = a;
        next[addr] = b;
    }
    int ptr = head;
    int count = 0;
    while (ptr != -1)
    {
        list[count++] = ptr;
        ptr = next[ptr];
    }
    n = count;
    for (int i = 0; i < (n - n % k); i += k)
    {
        reverse(list + i, list + i + k);
    }
    for (int i = 0; i < n - 1; i++)
    {
        printf("%05d %d %05d\n", list[i], data[list[i]], list[i + 1]);
    }
    printf("%05d %d -1\n", list[n - 1], data[list[n - 1]]);

    system("pause");
    return 0;
}