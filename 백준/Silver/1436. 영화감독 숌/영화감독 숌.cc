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
        // 종말의 수: 어떤 수에 적어도 3개 이상 6이 연속으로 들어간 수
        // ex) 1666, 2666, 3666 등
        // N 번째 영화의 제목에 들어간 수.


        int answer = 0;

        for (int i = 0; i < N;)
        {
            ++answer;
            string s = to_string(answer);
            int sixCnt = 0;

            // 문자열을 돌면서 6이 3개인지 검사
            for (char c : s)
            {
                if (c == '6')
                {
                    ++sixCnt;

                    if (sixCnt == 3)
                    {
                        ++i;
                        break;
                    }
                }
                else
                    sixCnt = 0;


            }

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
