#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char input[81], output[81];
    bool broken[128] = {false};
    scanf("%s %s", input, output);
    int i = 0, j = 0;
    while (input[i] != '\0' && output[j] != '\0')
    {
        input[i] = toupper(input[i]);
        output[j] = toupper(output[j]);
        if (input[i] != output[j])
        {
            if (!broken[input[i]])
            {
                printf("%c", input[i]);
                broken[input[i]] = true;
            }
            i++;
        }
        else
        {
            i++;
            j++;
        }
    }
    while (input[i] != '\0')
    {
        char c = toupper(input[i]);
        if (!broken[c])
        {
            printf("%c", c);
            broken[c] = true;
        }
        i++;
    }
    printf("\n");
    system("pause");
    return 0;
}