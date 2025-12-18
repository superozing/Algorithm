#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    N++;
    
    while (N--)
        cout << string(N, '*') << '\n';
    
    return 0;
}