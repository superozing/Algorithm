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
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

struct line
{
    int s, e;
};

class Boj
{
private:
    int N;

    vector<line> lines;

public:
    void input()
    {
        cin >> N;
        lines.resize(N);
        for (int i = 0; i < lines.size(); ++i)
            cin >> lines[i].s >> lines[i].e;

        sort(lines.begin(), lines.end(), Boj());
    }

    void progress()
    {
        // 선의 총 길이
        // 1. 시작 지점과 끝 지점 저장
        // 2. 다음 선의 시작 지점이 이전 선의 끝 지점보다 앞 쪽인가?
        //  true -> 다음 선의 끝 지점으로 갱신
        //  fasle-> 지금 까지의 시작 지점, 끝 지점의 distance 구하기

        int answer = 0;
        int s = lines[0].s, e = lines[0].e;

        for (int i = 1; i < lines.size(); ++i)
        {
            if (e >= lines[i].s)
                e = max(lines[i].e, e);
            else
            {
                answer += e - s;
                s = lines[i].s;
                e = lines[i].e;
            }
        }

        answer += e - s;

        cout << answer;
    }

    bool operator ()(line& a, line& b)
    {
        return a.s == b.s ? a.e < b.e : a.s < b.s;
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


