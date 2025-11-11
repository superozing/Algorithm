#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    // 강의 시작 시간, 끝 시간.
    // 최소 강의 수

    // 입력 정렬되지 않음

    // 결국에 동시간대에 가장 많이 겹치는 강의의 수를 찾으면 되겠네요.

    int N;
    cin >> N;

    // 일단 정렬
    // 시작시간, 종료시간 기준으로 오름차순 정렬
    // 벡터에 넣고 돌리는 게 가장 좋겠죠.
    
    // 강의 시작시간이 되면 종료 시간을 pq에 넣고 진행 중인 강의의 최대 개수를 구하면 될 것 같아요.
    // 종료시간과 시작시간이 겹치는 것은 상관이 없다. 그렇기 때문에 종료시간이 되었다면 pop을 먼저 해야겠죠.

    // 시간 체크는 
    // 시작하지 않은 강의의 시작시간 목록 중 가장 빠른 것과
    // 시작한 강의의 종료시간 목록 중 가장 빠른 것을 비교해서 더 빨리 진행되는 것을 먼저 하면 되겠네요.

    // 강의 번호는 무슨 역할이지..?

    vector<pair<int, int>> lectures(N);
    for (auto& lecture : lectures)
        cin >> lecture.first >> lecture.first >> lecture.second;

    sort(begin(lectures), end(lectures),
        [](const pair<int, int>& a, const pair<int, int>& b)
        {
            return a.first == b.first ? a.second < b.second : a.first < b.first;
        });

    priority_queue<int, vector<int>, greater<int>> pq;

    int answer = 0;

    int idx = 0;
    while (idx < lectures.size())
    {
        auto& cur = lectures[idx];

        if (pq.empty() || pq.top() > cur.first)
        {
            ++idx;
            pq.push(cur.second);
            answer = max(answer, (int)pq.size());
        }
        else
            pq.pop();
    }

    cout << answer;

    return 0;
}