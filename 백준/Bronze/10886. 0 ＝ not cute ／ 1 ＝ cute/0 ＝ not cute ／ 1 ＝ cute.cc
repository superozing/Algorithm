#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    int ans = 0;
    
    while (N--)
    {
        int in;
        cin >> in;
        ans += in ? 1 : -1;
    }
    
    if (ans > 0)
        cout << "Junhee is cute!";
    else
        cout << "Junhee is not cute!";
    
    return 0;
}