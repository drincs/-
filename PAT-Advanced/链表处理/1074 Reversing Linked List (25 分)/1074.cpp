#include <iostream>
#include <map>
#include <vector>
using namespace std;
struct node
{
    int next;
    int data;
};
map<int, node> nodes;
int main()
{
    int head, ptr, n, k;
    scanf("%d%d%d", &head, &n, &k);
    for (int i = 0; i < n; i++)
    {
        int add;
        node tmp;
        scanf("%d%d%d", &add, &tmp.data, &tmp.next);
        nodes.insert(make_pair(add, tmp));
    }
    ptr = head;
    //每k个处理
    int count = 0;
    vector<int> group;
    //链表遍历
    if (ptr == -1)
    {
        printf("-1\n");
        return 0;
    }
    while (ptr != -1)
    {
        //足k分组
        while (count < k && ptr != -1)
        {
            group.push_back(ptr);
            ptr = nodes[ptr].next;
            count++;
        }
        //足k处理
        if (count == k)
        {
            for (int i = count - 1; i >= 0; i--)
            {
                printf("%05d %d", group[i], nodes[group[i]].data);
                if (i != 0)
                {
                    printf(" %05d\n", group[i - 1]);
                }
                else
                {
                    if (ptr != -1)
                        printf(" %05d\n", ptr);
                    else
                        printf(" %d\n", -1);
                }
            }
        }
        else
        {
            //最后几个正序
            for (int i = 0; i < count; i++)
            {
                printf("%05d %d", group[i], nodes[group[i]].data);
                int next = nodes[group[i]].next;
                if (next != -1)
                    printf(" %05d\n", next);
                else
                    printf(" %d\n", -1);
            }
        }
        count = 0;
        group.clear();
    }
    system("pause");
    return 0;
}