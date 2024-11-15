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
    int N;
    
    list<int> q;

public:

    void input()
    {
        cin >> N;

        for (int i = 1; i <= N; ++i)
            q.push_back(i);
    }

    void progress()
    {
        while (q.size() != 1)
        {
            // 1. 맨 위의 카드를 버려요
            q.pop_front();

            // 2. 그 다음 카드를 아래로 집어넣어요.
            q.push_back(q.front());
            q.pop_front();
        }


        cout << q.front();
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

