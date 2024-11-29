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
    int N, M;

    vector<int> nums;
    vector<bool> visited;
    vector<int> P;

public:

    void input()
    {
        cin >> N >> M;
        nums.resize(N + 1);
        visited.resize(N + 1);

        for (int i = 1; i <= N; ++i)
            cin >> nums[i];

        sort(nums.begin(), nums.end());
    }

    void progress()
    {
        for (int i = 1; i <= N; ++i)
        {
            visited[i] = true;
            P.push_back(i);

            dfs();

            visited[i] = false;
            P.pop_back();
        }
    }

private:

    void dfs()
    {
        if (P.size() == M)
        {
            for (int i : P)
                cout << nums[i] << " ";

            cout << endl;
            return;
        }


        for (int i = 1; i <= N; ++i)
        {
            if (!visited[i])
            {
                visited[i] = true;
                P.push_back(i);
                dfs();
                visited[i] = false;
                P.pop_back();
            }
        }

        return;
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

