#include <iostream>
using namespace std;
int main()
{
    int head1, head2, n;
    char data[100000];
    int next[100000];
    int order1[100000], order2[100000];
    scanf("%d%d%d", &head1, &head2, &n);
    for (int i = 0; i < n; i++)
    {
        int addr, nt;
        char word;
        scanf("%d %c %d", &addr, &word, &nt);
        data[addr] = word;
        next[addr] = nt;
    }
    int ptr1 = head1, ptr2 = head2;
    int c1 = 0, c2 = 0;
    while (ptr1 != -1)
    {
        order1[c1++] = ptr1;
        ptr1 = next[ptr1];
    }
    while (ptr2 != -1)
    {
        order2[c2++] = ptr2;
        ptr2 = next[ptr2];
    }
    int x = c1 - 1, y = c2 - 1;
    bool find = false;
    while (x >= 0 && y >= 0 && order1[x] == order2[y])
    {
        x--;
        y--;
        find = true;
    }
    if (find)
        printf("%05d\n", order1[x + 1]);
    else
        printf("-1\n");
    system("pause");
    return 0;
}