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
    int N; // 명령의 수
    stack<int> s;

public:

    void input()
    {
        cin >> N;
    }

    void progress()
    {
        string str;
        int input;
        while (N--)
        {
            cin >> str;

            if (str == "push")
            {
                cin >> input;
                s.push(input);
            }

            else if (str == "pop")
            {
                if (s.empty())
                    cout << "-1\n";
                else
                {
                    cout << s.top() << "\n";
                    s.pop();
                }
            }

            else if (str == "size")
                cout << s.size() << "\n";

            else if (str == "empty")
                cout << (s.empty() ? "1\n" : "0\n");

            else if (str == "top")
                s.empty() ? cout << "-1\n" : cout << s.top() << "\n";
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

