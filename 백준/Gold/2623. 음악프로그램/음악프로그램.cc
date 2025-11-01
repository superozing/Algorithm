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

    int N, M;
    cin >> N >> M;

    vector<int> priority(N + 1);
    vector<int> answer;
    vector<queue<int>> pdOrder(M);

    for (auto& q : pdOrder)
    {
        int count;
        cin >> count;

        int in;
        cin >> in;
        q.push(in);

        for (int i = 1; i < count; ++i)
        {
            cin >> in;
            q.push(in);
            priority[in]++;
        }
    }


    // 큐 앞에 있으면서 우선순위 0 -> 출력
    // 다음 수 우선순위 -- 해주기

    while (answer.size() != N)
    {
        bool cantPop = true;
        for (int i = 1; i < priority.size(); ++i)
        {
            if (priority[i] == -1)
                continue;

            if (priority[i] != 0)
                continue;

            cantPop = false;

            for (auto& q : pdOrder)
            {
                if (q.empty() || q.front() != i)
                    continue;

                q.pop();

                if (!q.empty())
                    priority[q.front()]--;
            }

            answer.push_back(i);
            priority[i] = -1;
            break;
        }
     
        if (cantPop)
        {
            cout << 0;
            return 0;
        }
    }

    for (int& i : answer)
        cout << i << endl;

    return 0;
}