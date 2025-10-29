#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i)
        nums[i] = i + 1;
    do
    {
        for (auto& i : nums)
            cout << i << ' ';
        cout << endl;
    } while (next_permutation(begin(nums), end(nums)));

    return 0;
}