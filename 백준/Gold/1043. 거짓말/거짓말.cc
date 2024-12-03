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

class Boj
{
private:
    int N, M; // 사람의 수, 파티의 수

    vector<int> root;
    vector<int> truth;

public:

    void input()
    {
        cin >> N >> M;

        root.resize(N + 1);

        for (int i = 1; i < root.size(); ++i)
            root[i] = i;

        int cnt, in;
        cin >> cnt;
        truth.reserve(cnt);
        while (cnt--)
        {
            cin >> in;
            truth.push_back(in);
        }
    }

    void progress()
    {
        int cnt, in;
        vector<vector<int>> parties(M);
        for (int i = 0; i < M; ++i)
        {
            cin >> cnt;
            auto& curParty = parties[i];

            cin >> in;
            curParty.push_back(in);
            while (--cnt)
            {
                cin >> in;
                curParty.push_back(in);
                Union(curParty[0], curParty.back());
            }
        }

        int answer = 0;

        for (auto& party : parties)
        {
            bool canLie = true;

            for (int people : party)
            {
                for (int liePeople : truth)
                {
                    if (isUnion(liePeople, people))
                    {
                        canLie = false;
                        break;
                    }
                }

                if (!canLie)
                    break;
            }

            if (canLie)
                ++answer;
        }

        cout << answer;
    }

private:

    bool Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);

        root[max(a, b)] = min(a, b);

        return a == b;
    }

    bool isUnion(int a, int b)
    {
        return Find(a) == Find(b);
    }

    int Find(int a)
    {
        if (a == root[a])
            return a;

        return root[a] = Find(root[a]);
    }

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

