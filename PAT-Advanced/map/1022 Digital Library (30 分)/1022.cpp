#include <iostream>
#include <map>
#include <vector>
#include <set>
using namespace std;
void queryDict(map<string, set<int>> &mp, string key)
{
    map<string, set<int>>::iterator it = mp.find(key);
    if (it != mp.end())
    {
        for (set<int>::iterator st = it->second.begin(); st != it->second.end(); st++)
        {
            printf("%07d\n", *st);
        }
    }
    else
    {
        printf("Not Found\n");
    }
}
int main()
{
    int N;
    scanf("%d", &N);
    map<string, set<int>> titles;
    map<string, set<int>> authors;
    map<string, set<int>> keys;
    map<string, set<int>> publishers;
    map<string, set<int>> years;
    map<string, set<int>>::iterator it;
    for (int i = 0; i < N; i++)
    {
        int id;
        scanf("%d", &id);
        getchar();
        string title;
        getline(cin, title);
        titles[title].insert(id);
        string author;
        getline(cin, author);
        authors[author].insert(id);
        string key;
        while (cin >> key)
        {
            keys[key].insert(id);
            char c = getchar();
            if (c == '\n')
            {
                break;
            }
        }
        string publisher;
        getline(cin, publisher);
        publishers[publisher].insert(id);
        string year;
        getline(cin, year);
        years[year].insert(id);
    }
    int M;
    cin >> M;
    getchar();
    for (int i = 0; i < M; i++)
    {
        int type;
        scanf("%d: ", &type);
        string query;
        getline(cin, query);
        cout << type << ": " << query << endl;
        if (type == 1)
        {
            queryDict(titles, query);
        }
        else if (type == 2)
        {
            queryDict(authors, query);
        }
        else if (type == 3)
        {
            queryDict(keys, query);
        }
        else if (type == 4)
        {
            queryDict(publishers, query);
        }
        else
        {
            queryDict(years, query);
        }
    }
    system("pause");
    return 0;
}