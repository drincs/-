#include <iostream>
#include <algorithm>

using namespace std;
int n;
int num[101];
int mid[101];
int tmp[101];
void printArray(int a[])
{
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", a[i]);
    }
    printf("\n");
}
bool isSame(int a[], int b[])
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            return false;
        }
    }
    return true;
}
void mergeSort()
{
    bool get = false;
    for (int x = 2; x / 2 <= n; x *= 2)
    {
        if (x != 2 && isSame(tmp, mid))
        {
            get = true;
        }
        //下一步
        for (int y = 0; y < n; y += x)
        {
            if (y + x <= n)
                sort(tmp + y, tmp + y + x);
            else
                sort(tmp + y, tmp + n);
        }
        if (get)
        {
            printArray(tmp);
            return;
        }
    }
}
bool insertSort()
{
    bool get = false;
    for (int i = 1; i < n; i++)
    {
        if (i != 1 && isSame(tmp, mid))
        {
            get = true;
        }
        int t = tmp[i], j = i;
        while (j > 0 && tmp[j - 1] > t)
        {
            tmp[j] = tmp[j - 1];
            j--;
        }
        tmp[j] = t;
        if (get)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
        tmp[i] = num[i];
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &mid[i]);
    }
    if (insertSort())
    {
        printf("Insertion Sort\n");
        printArray(tmp);
    }
    else
    {
        printf("Merge Sort\n");
        for (int i = 0; i < n; i++)
        {
            tmp[i] = num[i];
        }
        mergeSort();
    }

    system("pause");
    return 0;
}