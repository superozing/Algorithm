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

constexpr auto exitFlag = -999;

class Boj
{
private:
    int N;

public:

    void input()
    {
        cin >> N;
    }

    void progress()
    {
        string s;

        while (N--)
        {
            cin >> s;

            int vpsCheck = 0;

            for (char c : s)
            {
                switch (c)
                {
                case '(':
                {
                    ++vpsCheck;
                }
                break;
                case ')':
                {
                    if (vpsCheck == 0)
                        vpsCheck = exitFlag;

                    --vpsCheck;
                }
                break;
                }

                // 문자열 순회 중, vps가 아닐 경우
                if (vpsCheck == exitFlag)
                    break;
            }

            printf(vpsCheck == 0 ? "YES\n" : "NO\n");
        }
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

