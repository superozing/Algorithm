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

struct Meeting
{
    int s, e;
};

struct cmp
{
    bool operator() (Meeting& a, Meeting& b)
    {
        // 끝나는 시간을 기준으로 정렬
        return a.e == b.e ? a.s < b.s : a.e < b.e;
    }
};

class Boj
{
private:
    int N; // 회의의 수

    vector<Meeting> meetings;

public:

    void input()
    {
        cin >> N;

        meetings.resize(N);
        for (int i = 0; i < meetings.size(); ++i)
            cin >> meetings[i].s >> meetings[i].e;

        sort(meetings.begin(), meetings.end(), cmp());
    }

    void progress()
    {
        int endTime = 0;
        int answer = 0;

        for (Meeting& meet : meetings)
        {
            if (meet.s >= endTime)
            {
                ++answer;
                endTime = meet.e;
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

