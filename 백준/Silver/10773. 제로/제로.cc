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
    int K;
    stack<int> s;

public:

    void input()
    {
        cin >> K;
    }

    void progress()
    {
        int input;
        while (K--)
        {
            cin >> input;

            if (input != 0)
                s.push(input);
            else
                s.pop();
        }

        int answer = 0;
        while (!s.empty())
        {
            answer += s.top();
            s.pop();
        }

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

