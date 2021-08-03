#include <iostream>
#include <stack>
#include <math.h>

using namespace std;
const int MAXN = 100001;
const int sqrN = sqrt(MAXN); //块内元素个数
stack<int> st;
int block[sqrN];
int table[MAXN];

void push(int val)
{
    st.push(val);
    table[val]++;
    block[val / sqrN]++;
}
void pop()
{
    if (st.size() == 0)
    {
        printf("Invalid\n");
    }
    else
    {
        int val = st.top();
        st.pop();
        printf("%d\n", val);
        table[val]--;
        block[val / sqrN]--;
    }
}
void peekMedian(int k)
{
    if (st.size() == 0)
    {
        printf("Invalid\n");
    }
    else
    {
        int idx = 0;
        int sum = 0;
        while (sum + block[idx] < k)
        {
            sum += block[idx];
            idx++;
        }
        int num = idx * sqrN;
        while (sum + table[num] < k)
        {
            sum += table[num++];
        }
        printf("%d\n", num);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    fill(block, block + sqrN, 0);
    fill(table, table + MAXN, 0);
    for (int i = 0; i < n; i++)
    {
        char cmd[20];
        scanf("%s", cmd);
        if (cmd[1] == 'u')
        {
            //插入
            int key;
            scanf("%d", &key);
            push(key);
        }
        else if (cmd[1] == 'o')
        {
            //删除
            pop();
        }
        else
        {
            //查询
            int size = st.size();
            peekMedian((size + 1) / 2);
        }
    }
    system("pause");
    return 0;
}