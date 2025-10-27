#include <iostream>

using namespace std;

int main()
{
    int in;
    cin >> in;
    
    int answer = in / 5;
    if (in % 5 != 0)
        answer++;
    
    cout << answer;
    
    return 0;
}