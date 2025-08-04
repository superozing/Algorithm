#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int answer = 0;
    
    while (N)
        answer += N--;
    
    cout << answer;
    
    return 0;
}