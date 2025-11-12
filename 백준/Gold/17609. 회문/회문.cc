#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <queue>

#define endl ('\n')

using namespace std;

int answer = 1e9;

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s;

        bool isEnd = false;

        for (int i = 0; i < s.size() / 2; ++i)
        {
            if (s[i] != s[s.size() - 1 - i])
            {
                int wrongCount = 0;
                for (int j = i; j < s.size() / 2; ++j)
                {
                    if (s[j] != s[s.size() - 2 - j])
                    {
                        wrongCount++;
                        break;
                    }
                }
                for (int j = i; j < s.size() / 2; ++j)
                {
                    if (s[j + 1] != s[s.size() - 1 - j])
                    {
                        wrongCount++;
                        break;
                    }
                }

                if (wrongCount == 2)
                    cout << 2 << endl;
                else
                    cout << 1 << endl;

                isEnd = true;
                break;
            }
        }

        if (!isEnd)
            cout << 0 << endl;
    }

    return 0;
}