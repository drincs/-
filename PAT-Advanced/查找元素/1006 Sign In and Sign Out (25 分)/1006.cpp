#include <iostream>
#include <string.h>
using namespace std;
int toInt(char time[])
{
    int s = 0;
    s = (time[0] - '0') * 10 + (time[1] - '0') * 1;
    s = s * 60 + (time[3] - '0') * 10 + (time[4] - '0') * 1;
    s = s * 60 + (time[6] - '0') * 10 + (time[7] - '0') * 1;
    return s;
}
int main()
{
    int M;
    int unlocked = 24 * 60 * 60, locked = 0;
    char unlocked_id[16], locked_id[16];
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        char id[16];
        char in_time[9];
        char out_time[9];
        int in, out;
        scanf("%s %s %s", id, in_time, out_time);
        in = toInt(in_time);
        out = toInt(out_time);
        if (unlocked > in)
        {
            unlocked = in;
            strcpy(unlocked_id, id);
        }
        if (locked < out)
        {
            locked = out;
            strcpy(locked_id, id);
        }
    }
    printf("%s %s\n", unlocked_id, locked_id);
    system("pause");
    return 0;
}