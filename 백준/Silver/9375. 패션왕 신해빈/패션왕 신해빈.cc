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
    int T;
    unordered_map<string, int> um;

public:

    void input()
    {
        cin >> T;
    }

    void progress()
    {
        string s;
        int clothCnt;
        while (T--)
        {
            um.clear();
            
            cin >> clothCnt;

            while (clothCnt--)
            {
                cin >> s; // 의상 이름 날려버리기
                cin >> s;
                um[s]++;
            }

            int answer = 1;
            for (auto& it : um)
                answer *= (it.second + 1);

            answer--;
            cout << answer << endl;
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

