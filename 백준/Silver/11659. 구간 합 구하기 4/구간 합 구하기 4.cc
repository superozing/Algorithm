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
    int N; // 수의 개수
    int M; // 합을 구해야 하는 구간의 개수

    vector<int> nums;
    
public:

    void input()
    {
        cin >> N >> M;
        nums.resize(N + 1);

        for (int i = 1; i < nums.size(); ++i)
        {
            cin >> nums[i];
            nums[i] += nums[i - 1];
        }

    }

    void progress()
    {
        int a, b;
        while (M--)
        {
            cin >> a >> b;
            cout << nums[b] - nums[a - 1] << endl;
        }
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

