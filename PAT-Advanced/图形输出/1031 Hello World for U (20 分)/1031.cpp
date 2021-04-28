#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n1, n2;
    string str;
    cin >> str;
    int N = str.length();
    n1 = (N + 2) / 3;
    n2 = N + 2 - 2 * n1;
    for (int i = 0; i < n1 - 1; i++)
    {
        printf("%c", str[i]);
        for (int j = 1; j < n2 - 1; j++)
        {
            printf(" ");
        }
        printf("%c\n", str[N - 1 - i]);
    }
    for (int i = 0; i < n2; i++)
    {
        printf("%c", str[n1 - 1 + i]);
    }
    printf("\n");
    system("pause");
    return 0;
}