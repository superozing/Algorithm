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
    vector<string> cantor;

public:
    void input()
    {
        cin >> N;
    }

    void progress()
    {
        cantor.resize(12 + 1);
        cantor[0] = '-';
        for (int i = 1; i <= 12; ++i)
            cantor[i] = cantor[i - 1] + string(cantor[i - 1].size(), ' ') + cantor[i - 1];
        
        do
        {
            cout << cantor[N] << endl;
            cin >> N;
        } while (!cin.eof());
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

