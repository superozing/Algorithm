///////////////////////////////////////////
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Boj
{
private:
    string s;
    int alphabet['z' - 'a' + 1];
public:

    void input()
    {
        cin >> s;

        for (int i = 0; i < 'z' - 'a' + 1; ++i)
            alphabet[i] = 999;
    }

    void progress()
    {
        char c;
        for (int i = 0; i < s.length(); ++i)
        {
            c = s[i] - 'a';
            alphabet[c] = min(alphabet[c], i);
        }

        for (int i = 0; i < 'z' - 'a' + 1; ++i)
            printf("%d ", alphabet[i] == 999 ? -1 : alphabet[i]);
    }

private:

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}

