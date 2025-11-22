#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

int N, M;
vector<int> nums;

void DFS()
{
    if (nums.size() == M)
    {
        for (auto& num : nums)
            cout << num << ' ';
        
        cout << endl;
        
        return;
    }

    for (int i = 1; i <= N; ++i)
    {
        nums.push_back(i);
        DFS();
        nums.pop_back();
    }
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;

    DFS();

    return 0;
}

