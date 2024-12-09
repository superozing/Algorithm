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
    int N, M; // N 개의 숫자 중 M 개의 수로 이루어진 행렬

    map<int, int> nums;
    vector<int> permutation;

public:

    void input()
    {
        cin >> N >> M;

        permutation.reserve(M + 1);

        int in;
        for (int i = 0; i < N; ++i)
        {
            cin >> in;
            nums[in]++;
        }
    }

    void progress()
    {
        for (auto& it : nums)
        {
            permutation.push_back(it.first);
            --it.second;

            dfs(1);

            permutation.pop_back();
            ++it.second;
        }
    }

private:

    void dfs(int cnt)
    {
        if (cnt == M)
        {
            for (int i : permutation)
                cout << i << " ";
            
            cout << endl;
            return;
        }

        for (auto& it : nums)
        {
            if (it.second == 0)
                continue;

            permutation.push_back(it.first);
            --it.second;

            dfs(cnt + 1);

            permutation.pop_back();
            ++it.second;
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

