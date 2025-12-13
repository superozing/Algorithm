#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int answer = 0;
    while (N--)
    {
        int in;
        cin >> in;
        answer += in;
    }
    
    cout << answer;
    
    return 0;
}