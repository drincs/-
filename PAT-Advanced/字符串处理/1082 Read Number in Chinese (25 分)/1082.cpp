#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{
    char shu[10][10] = {"yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char wei[6][5] = {"Shi", "Bai", "Qian", "Wan", "Yi"};
    int n;
    string num = "";
    cin >> n;
    int high = 0;
    if (n == 0)
    {
        cout << "ling" << endl;
    }
    else
    {
        if (n < 0)
        {
            printf("Fu");
            num += "-";
            n *= -1;
            high++;
        }
        while (n > 0)
        {
            num += n % 10 + '0';
            n /= 10;
        }
        if (num[0] == '-')
            reverse(num.begin() + 1, num.end());
        else
            reverse(num.begin(), num.end());
        int len = num.size();
        int low = len - 1;
        while (high <= low - 4)
        {
            low -= 4;
        }
        while (high <= low)
        {
            bool hasZero = false;
            bool hasPrint = false;
            while (high <= low)
            {
                //同位级处理
                if (num[high] == '0')
                {
                    //当前位为0
                    hasZero = true;
                }
                else
                {
                    //非0
                    if (hasZero)
                    {
                        cout << " ling";
                        hasZero = false;
                    }
                    if (high > 0)
                        cout << " ";
                    cout << shu[num[high] - '0' - 1];
                    hasPrint = true;
                    //输出十百千
                    if (high < low)
                    {
                        cout << " " << wei[low - high - 1];
                    }
                }
                high++;
            }
            if (hasPrint && low != len - 1)
            {
                //输出亿 万
                cout << " " << wei[2 + (len - 1 - low) / 4];
            }
            high = low + 1;
            if (low < len - 1)
            {
                low += 4;
            }
        }
        cout << endl;
    }

    system("pause");
    return 0;
}