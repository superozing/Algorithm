//////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

struct meet
{
    int start;
    int end;
};

struct cmp
{
    bool operator ()(meet& a, meet& b)
    {
        return a.end != b.end ? a.end > b.end : a.start > b.start;
    }
};

class Boj
{
private:
    int N;
    priority_queue<meet, vector<meet>, cmp> meetings;

public:
    void input()
    {
        cin >> N;
        meet newMeeting;

        for (int i = 0; i < N; ++i)
        {
            cin >> newMeeting.start >> newMeeting.end;
            meetings.push(newMeeting);
        }
    }

    void progress()
    {
        int curTime = 0;
        int answer = 0;
        while (!meetings.empty())
        {
            auto cur = meetings.top();
            meetings.pop();

            // 이미 시작시간이 지난 회의
            if (curTime > cur.start)
                continue;
            //cout << cur.start << ", end:" << cur.end << endl;
            ++answer;
            curTime = cur.end;
        }

        cout << answer;
    }

private:
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}

