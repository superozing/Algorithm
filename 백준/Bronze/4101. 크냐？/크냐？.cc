#include <iostream>

using namespace std;

int main()
{
    while (true)
    {
        int a, b;
        cin >> a >> b;
        
        if (a == b && a == 0)
            return 0;
        
        cout << (a > b ? "Yes\n" : "No\n");
    }

    return 0;
}