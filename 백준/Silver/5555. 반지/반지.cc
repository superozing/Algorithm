#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

#define endl ('\n')

using namespace std;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    
    
    string goal;
    cin >> goal;

    int N;
    cin >> N;
    int answer = 0;

    for (int i = 0; i < N; ++i)
    {
        string cur;
        cin >> cur;

        int hit = 0;
        for (int j = 0; j < 10 + goal.size(); ++j)
        {
            if (cur[j % 10] == goal[hit])
            {
                ++hit;
                if (hit == goal.size())
                {
                    ++answer;
                    break;
                }
            }
        }
    }

    cout << answer;

    return 0;
}
