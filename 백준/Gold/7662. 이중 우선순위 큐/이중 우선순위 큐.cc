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
    int T; // 입력 데이터 수


public:

    void input()
    {
        // 맵 써야 할까?
        cin >> T;
    }

    void progress()
    {
        int cmdCnt;
        char cmd;
        int num;
        while (T--)
        {
            map<int, int> m;

            cin >> cmdCnt;
            while (cmdCnt--)
            {
                cin >> cmd >> num;

                switch (cmd)
                {
                case 'I':
                    m[num]++;
                    break;

                case 'D':
                    
                    // 적어도 한 개의 데이터라도 들어있는 경우
                    if (!m.empty())
                    {
                        if (num == 1)
                        {
                            if (--m.rbegin()->second == 0)
                                m.erase(m.rbegin()->first);
                        }
                        else
                        {
                            if (--m.begin()->second == 0)
                                m.erase(m.begin()->first);
                        }
                    }
                }
            }

            if (m.empty())
                cout << "EMPTY" << endl;
            else
                cout << m.rbegin()->first << " " << m.begin()->first << endl;

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

