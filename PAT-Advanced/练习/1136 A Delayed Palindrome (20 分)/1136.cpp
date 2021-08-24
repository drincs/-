#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isPalindromic(vector<int> a)
{
    int len = a.size();
    for (int i = 0; i < a.size() / 2; i++)
    {
        if (a[i] != a[len - 1 - i])
        {
            return false;
        }
    }
    return true;
}
vector<int> origin, b, sum;
void reverseOrigin()
{
    b.clear();
    for (int i = origin.size() - 1; i >= 0; i--)
    {
        b.push_back(origin[i]);
    }
}
void add()
{
    int carry = 0;
    sum.assign(origin.size(), 0);
    for (int i = 0; i < origin.size(); i++)
    {
        sum[i] = (origin[i] + b[i] + carry) % 10;
        carry = (origin[i] + b[i] + carry) / 10;
    }
    if (carry > 0)
    {
        sum.push_back(carry);
    }
}
void print(vector<int> num)
{
    for (int i = num.size() - 1; i >= 0; i--)
    {
        printf("%d", num[i]);
    }
}

int main()
{
    string a;
    cin >> a;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        origin.push_back(a[i] - '0');
    }
    if (isPalindromic(origin))
    {
        print(origin);
        printf(" is a palindromic number.\n");
        return 0;
    }
    for (int i = 0; i < 10; i++)
    {
        reverseOrigin();
        add();
        print(origin);
        printf(" + ");
        print(b);
        printf(" = ");
        print(sum);
        printf("\n");
        if (isPalindromic(sum))
        {

            print(sum);
            printf(" is a palindromic number.\n");
            break;
        }
        else
        {
            if (i == 9)
            {
                printf("Not found in 10 iterations.\n");
                break;
            }
            origin.assign(sum.begin(), sum.end());
        }
    }
    system("pause");
    return 0;
}