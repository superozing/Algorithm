#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

int N, M;
vector<int> idx;
vector<int> nums;

void BFS()
{
    if (idx.size() == M)
    {
        for (int& i : idx)
            cout << nums[i] << ' ';

        cout << endl;

        return;
    }

    for (int i = idx.empty() ? 0 : idx.back(); i < N; ++i)
    {
        idx.push_back(i);
        BFS();
        idx.pop_back();
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    nums.resize(N);
    for (auto& i : nums)
        cin >> i;

    sort(nums.begin(), nums.end());

    BFS();

    return 0;
}

