#include <iostream>
using namespace std;
void to13(char a[], int val)
{
    int pos = 0;
    a[0]='0';
    a[1]='0';
    while (val > 0)
    {
        int temp = val % 13;
        a[pos++] = temp > 9 ? temp - 10 + 'A' : temp + '0';
        val /= 13;
    }
    for (int i = 1; i >= 0; i--)
    {
        printf("%c", a[i]);
    }
}
int main()
{
    int r, g, b;
    scanf("%d%d%d", &r, &g, &b);
    char R[2], G[2], B[2];
    printf("#");
    to13(R, r);
    to13(G, g);
    to13(B, b);
    printf("\n");
    system("pause");
    return 0;
}