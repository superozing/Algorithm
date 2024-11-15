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

public:

    void input()
    {
        cin >> N;
    }

    void progress()
    {

        // 10, 
        // 2 5

        // 0 - 5*2(의배수) 로 만들어짐.
        // 2가 넘치기에 5의 개수를 세기.


        int answer = 0;

        for (int i = 1; i <= N; ++i)
        {
            int cur = i;

            // 5의 개수 세기
            while (cur % 5 == 0)
            {
                cur /= 5;
                ++answer;
            }
        }

        // 124?
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

