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

#define endl "\n"

class Boj
{
private:
    int N; // 듣도 못한 분
    int M; // 보도 못한 분

    unordered_set<string> us;
    vector<string> answer;

public:
    void input()
    {
        cin >> N >> M;

        string s;
        while (N--)
        {
            cin >> s;
            us.insert(s);
        }
    }

    void progress()
    {
        string s;
        while (M--)
        {
            cin >> s;

            if (us.find(s) != us.end())
                answer.push_back(s);
        }

        cout << answer.size() << endl;
        
        sort(answer.begin(), answer.end());

        for (string& s : answer)
            cout << s << endl;
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

