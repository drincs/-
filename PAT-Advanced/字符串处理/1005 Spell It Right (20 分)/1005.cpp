#include <iostream>
using namespace std;
int main()
{
    //n最多100位
    char str[10][10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    char n[101];
    scanf("%s", n);
    int sum = 0;
    for (int i = 0; n[i] != '\0'; i++)
    {
        sum += n[i] - '0';
    }
    //sum 最多为900
    int first = 0;
    if (sum / 100 > 0)
    {
        first = 1;
        printf("%s", str[sum / 100]);
        sum = sum % 100;
    }
    if (first == 1)
    {
        printf(" %s", str[sum / 10]);
        sum = sum % 10;
    }
    else
    {
        if (sum / 10 > 0)
        {
            first = 1;
            printf("%s", str[sum / 10]);
            sum = sum % 10;
        }
    }
    if (first == 1)
        printf(" ");
    printf("%s\n", str[sum]);
    system("pause");
    return 0;
}