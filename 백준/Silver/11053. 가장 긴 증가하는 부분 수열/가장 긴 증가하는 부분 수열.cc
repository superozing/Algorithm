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
        vector<int> answer;

        answer.push_back(nums[0]);

        for (int i = 1; i < nums.size(); ++i)
        {
            if (answer.back() < nums[i])
                answer.push_back(nums[i]);
            else
                *lower_bound(answer.begin(), answer.end(), nums[i]) = nums[i];
        }


        cout << answer.size();
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

