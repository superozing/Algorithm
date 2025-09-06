#include <iostream>

using namespace std;

int main()
{
    int count[201] {};
    
    int N;
    cin >> N;
    
    while (N--)
    {
        int in;
        cin >> in;
        
        count[in + 100]++;
    }
    
    int out;
    cin >> out;
    cout << count[out + 100];
    
    return 0;
}