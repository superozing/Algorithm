#include <iostream>

using namespace std;

int main()
{
    int answer = 0;
    for (int i = 0; i < 5; ++i)
    {
        int in;
        cin >> in;
        answer += in;
    }    
    
    cout << answer;
    
    return 0;
}