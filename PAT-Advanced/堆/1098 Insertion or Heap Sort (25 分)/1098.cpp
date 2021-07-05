#include <iostream>
using namespace std;
const int MAXN = 101;
int origin[MAXN], partial[MAXN], temp[MAXN];
int n, pos;
bool compare(int a[], int b[])
{
    for (int i = 1; i <= n; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
bool isInsertSort()
{
    bool res = true;
    for (int i = 1; i < n; i++)
    {
        if (partial[i] > partial[i + 1])
        {
            pos = i;
            break;
        }
    }
    for (int i = pos + 1; i <= n; i++)
    {
        if (origin[i] != partial[i])
        {
            res = false;
        }
    }
    return res;
}
void insert()
{
    int j = pos + 1;
    int temp = partial[j];
    for (int i = 1; i < j; i++)
    {
        if (partial[j] < partial[i])
        {
            for (int x = j; x > i; x--)
            {
                partial[x] = partial[x - 1];
            }
            partial[i] = temp;
            break;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i != 1)
            printf(" ");
        printf("%d", partial[i]);
    }
    printf("\n");
}
void downAdjust(int low, int high)
{
    int i = low;
    int j = 2 * i;
    while (j <= high)
    {
        if (j + 1 <= high && temp[j + 1] > temp[j])
        {
            j = j + 1;
        }
        if (temp[i] < temp[j])
        {
            swap(temp[i], temp[j]);
            i = j;
            j = i * 2;
        }
        else
        {
            //当前层未交换，说明以下正常
            break;
        }
    }
}
void create()
{
    for (int i = 1; i <= n; i++)
    {
        temp[i] = origin[i];
    }
    for (int i = n / 2; i >= 1; i--)
    {
        downAdjust(i, n);
    }
}
void heapSort()
{
    create();
    bool out = false;
    for (int i = n; i > 1; i--)
    {
        if (compare(partial, temp))
        {
            out = true;
        }
        swap(temp[i], temp[1]);
        downAdjust(1, i - 1);
        if (out)
        {
            for (int p = 1; p <= n; p++)
            {
                if (p != 1)
                    printf(" ");
                printf("%d", temp[p]);
            }
            printf("\n");
            break;
        }
    }
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &origin[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &partial[i]);
    }
    pos = n;
    if (isInsertSort())
    {
        printf("Insertion Sort\n");
        insert();
    }
    else
    {
        printf("Heap Sort\n");
        heapSort();
    }
    system("pause");
    return 0;
}