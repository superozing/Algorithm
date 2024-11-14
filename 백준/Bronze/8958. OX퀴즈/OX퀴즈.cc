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
    int T;
    string s;

public:

    void input()
    {
        cin >> T;
    }

    void progress()
    {
        int answer, acc;

        while (T--)
        {
            answer = 0;
            acc = 1;
            cin >> s;

            for (int i = 0; i < s.size(); ++i)
            {
                if (s[i] == 'O') // O를 만나는 경우
                    answer += acc++;
                else // X를 만나는 경우
                    acc = 1;
            }
            
            printf("%d\n", answer);
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

