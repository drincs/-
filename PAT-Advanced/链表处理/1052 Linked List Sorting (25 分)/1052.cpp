#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 100000;
int key[MAXN], nt[MAXN], list[MAXN];
bool cmp(int addr1, int addr2)
{
    return key[addr1] < key[addr2];
}
int main()
{
    int n, head;
    scanf("%d%d", &n, &head);
    for (int i = 0; i < n; i++)
    {
        int addr, v, next;
        scanf("%d%d%d", &addr, &v, &next);
        key[addr] = v;
        nt[addr] = next;
    }
    int ptr = head, count = 0;
    while (ptr != -1)
    {
        list[count++] = ptr;
        ptr = nt[ptr];
    }
    sort(list, list + count, cmp);
    if (count == 0)
    {
        printf("0 -1\n");
    }
    else
    {
        printf("%d %05d\n", count, list[0]);
        for (int i = 0; i < count - 1; i++)
        {
            printf("%05d %d %05d\n", list[i], key[list[i]], list[i + 1]);
        }

        printf("%05d %d -1\n", list[count - 1], key[list[count - 1]]);
    }
    system("pause");
    return 0;
}