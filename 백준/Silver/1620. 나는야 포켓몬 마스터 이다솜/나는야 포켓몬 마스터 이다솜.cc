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
    int N; // 도감 정보 개수
    int M; // 문제 개수

    unordered_map<string, int> nameum;
    unordered_map<int, string> keyum;

public:

    void input()
    {
        cin >> N;
        cin >> M;

        string s;
        for (int i = 1; i <= N; ++i)
        {
            cin >> s;
            nameum[s] = i;
            keyum[i] = s;
        }
    }

    void progress()
    {
        string in;
        while (M--)
        {
            cin >> in;

            if (in[0] <= '9')
            {
                int key = stoi(in);
                cout << keyum[key] << endl;
            }
            else
            {
                cout << nameum[in] << endl;
            }
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

