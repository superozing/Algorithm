#include <iostream>

using namespace std;

int main()
{
    int ans;
    cin >> ans;
    
    int N;
    cin >> N;
    
    while (N--)
    {
        int a, b;
        cin >> a >> b;
        
        ans -= a * b;
    }
    
    cout << (ans ? "No" : "Yes");
    
    return 0;
}