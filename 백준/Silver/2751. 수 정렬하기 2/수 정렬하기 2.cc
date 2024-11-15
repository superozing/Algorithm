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
#include <cmath>

using namespace std;

class Boj
{
private:
    int N;
    vector<int> nums;

public:

    void input()
    {
        cin >> N;

        nums.resize(N);

        for (int i = 0; i < nums.size(); ++i)
            cin >> nums[i];
    }

    void progress()
    {
        sort(nums.begin(), nums.end());

        for (int it : nums)
            printf("%d\n", it);
    }

private:

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

