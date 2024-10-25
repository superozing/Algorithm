#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cmath>

using namespace std;

class Boj
{
private:
    int N;

public:
    void input()
    {
    }

    void progress()
    {
        set<int> s;
        
        int input = 0;

        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> input;
            s.insert(input);
        }

        int answer = 0;

        cin >> N;
        for (int i = 0; i < N; ++i)
        {
            cin >> input;
            printf("%d\n", (s.find(input) != s.end() ? 1 : 0));
        }
        
        return;
    }

private:
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    Boj boj;

    boj.input();
    boj.progress();

    return 0;
}

