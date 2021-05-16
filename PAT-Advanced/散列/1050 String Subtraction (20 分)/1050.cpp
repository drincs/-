#include <iostream>
#include <cstring>
#include <string.h>
#include <iomanip>
using namespace std;
int main()
{
    char s1[10001];
    int hide[256] = {0};
    int l1 = 0, l2 = 0;
    while (true)
    {
        s1[l1++] = getchar();
        if (s1[l1 - 1] == '\n')
            break;
    }
    while (true)
    {
        char c = getchar();
        if (c == '\n')
        {
            break;
        }
        else
        {
            hide[c] = 1;
        }
    }
    bool hasPrint = false;
    for (int i = 0; i < l1; i++)
    {
        if (!hide[s1[i]])
        {
            hasPrint = true;
            printf("%c", s1[i]);
        }
    }
    system("pause");
    return 0;
}