#include <iostream>
#include <string>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    
    string answer;
    
    if (a == 0)
    {
        cout << 0;
        return 0;
    }
    
    while (a > 0)
    {
        char c;
        if (a % b >= 10)
            c = (char)('A' + a % b - 10);
        else
            c = (char)('0' + a % b);
        
        answer = c + answer;
        
        a /= b;
    }
    
    cout << answer;
    
    return 0;
}