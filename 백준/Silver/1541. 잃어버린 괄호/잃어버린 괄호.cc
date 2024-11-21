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
#include <bitset>
#include <cmath>

using namespace std;

#define endl ("\n")

class Boj
{
private:
    string s;

public:

    void input()
    {
        cin >> s;
    }

    void progress()
    {
        int answer = 0;

        bool subtract = false;

        int l = 0;
        for (int r = 0; r < s.length(); ++r)
        {
            char c = s[r];

            if (c >= '0')
                continue;

            // 이전 문자 까지가 숫자.
            int num = stoi(s.substr(l, r - l));
            l = r + 1;
            answer += subtract ? -num : num;

            if (c == '-')
                subtract = true;
        }

        int num = stoi(s.substr(l, s.length() - l));
        answer += subtract ? -num : num;

        cout << answer;
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

