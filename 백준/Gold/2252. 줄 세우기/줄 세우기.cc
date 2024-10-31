
///////////////////////////////////
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

struct stud
{
    unordered_set<int> in;
    unordered_set<int> out;
};

class Boj
{
private:
    int N, M; // 학생 수(1~N), 비교 횟수
    vector<stud> students;
    vector<int> start;

public:
    void input()
    {
        cin >> N >> M;
        students.resize(N + 1);
        
        // 어떻게 간선을 관리할 것인가?
        // 간선 수가 10만개인데
        // 벡터 페어 벡터벡터 쓸까요?
        // 벡터 erase를 사용해도 괜찮은가?
        // 해쉬셋을 써볼까?
        int a, b;
        for (int i = 0; i < M; ++i)
        {
            cin >> a >> b;
            students[a].out.insert(b);
            students[b].in.insert(a);
        }

        for (int i = 1; i <= N; ++i)
        {
            if (students[i].in.empty())
                start.push_back(i);
        }

    }

    void progress()
    {
        list<int> q;

        for (auto it : start)
            q.push_back(it);

        while (!q.empty())
        {
            int cur = q.front();
            q.pop_front();
            printf("%d ", cur);

            auto& out = students[cur].out;

            for (int it : out)
            {
                students[it].in.erase(cur);

                if (students[it].in.empty())
                    q.push_back(it);
            }
        }
    }

private:

};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    //cout.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}

