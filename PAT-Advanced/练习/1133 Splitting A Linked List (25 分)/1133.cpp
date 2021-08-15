#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
struct node
{
    int addr;
    int data;
    int next;
    node()
    {
    }
    node(int addr, int data, int next)
    {
        this->addr = addr;
        this->data = data;
        this->next = next;
    }
};
unordered_map<int, node> list;
vector<int> a, b, c;

int main()
{
    int head, n, k;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++)
    {
        int addr, data, next;
        scanf("%d%d%d", &addr, &data, &next);
        node n(addr, data, next);
        list.insert(make_pair(addr, n));
    }
    int next = head;
    while (next != -1)
    {
        if (list[next].data < 0)
        {
            a.push_back(list[next].addr);
        }
        else if (list[next].data >= 0 && list[next].data <= k)
        {
            b.push_back(list[next].addr);
        }
        else
        {
            c.push_back(list[next].addr);
        }
        next = list[next].next;
    }
    bool first = false;
    for (int i = 0; i < a.size(); i++)
    {
        first = true;
        printf("%05d %d ", list[a[i]].addr, list[a[i]].data);
        if (i != a.size() - 1)
            printf("%05d\n", list[a[i + 1]].addr);
    }
    for (int i = 0; i < b.size(); i++)
    {
        if (first && i == 0)
            printf("%05d\n", list[b[0]].addr);
        printf("%05d %d ", list[b[i]].addr, list[b[i]].data);
        if (i != b.size() - 1)
            printf("%05d\n", list[b[i + 1]].addr);
    }

    for (int i = 0; i < c.size(); i++)
    {
        if (first && i == 0)
            printf("%05d\n", list[c[0]].addr);
        printf("%05d %d ", list[c[i]].addr, list[c[i]].data);
        if (i != c.size() - 1)
            printf("%05d\n", list[c[i + 1]].addr);
    }
    printf("-1\n");
    system("pause");
    return 0;
}