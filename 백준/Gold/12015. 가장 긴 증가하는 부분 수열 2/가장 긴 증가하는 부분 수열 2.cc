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

    }

    void progress()
    {
        int in;
        while (N--)
        {
            cin >> in;

            auto it = lower_bound(nums.begin(), nums.end(), in);

            if (it == nums.end())
                nums.push_back(in);
            else
                nums[it - nums.begin()] = min(nums[it - nums.begin()], in);
        }

        cout << nums.size();
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

