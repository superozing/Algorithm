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

    set<int> nums;
    vector<int> permutation;

public:

    void input()
    {
        cin >> N >> M;

        int in;
        for (int i = 0; i < N; ++i)
        {
            cin >> in;
            if (nums.find(in) == nums.end())
                nums.insert(in);
        }
    }

    void progress()
    {
        for (auto& it : nums)
        {
            permutation.push_back(it);
            dfs();
            permutation.pop_back();
        }
    }

private:

    void dfs()
    {
        if (permutation.size() == M)
        {
            for (int i : permutation)
                cout << i << " ";
            cout << endl;
            return;
        }

        for (auto it = nums.find(permutation.back()); it != nums.end(); ++it)
        {
            permutation.push_back(*it);
            dfs();
            permutation.pop_back();
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

