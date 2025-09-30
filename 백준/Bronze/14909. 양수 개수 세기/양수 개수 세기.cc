#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int answer = 0;
    
    int in;
    while (cin >> in)
        if (in > 0)
            answer++;
    
    cout << answer;
    
    return 0;
}