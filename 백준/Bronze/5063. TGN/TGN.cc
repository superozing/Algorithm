#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    while (N--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        
        int p = (b - c);
        
        if (a < p)
            cout << "advertise\n";
        else if (a > p)
            cout << "do not advertise\n";
        else
            cout << "does not matter\n";
        
    }
    
    
    return 0;
}