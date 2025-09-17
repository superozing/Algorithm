#include <iostream>

using namespace std;

int main()
{
    int sum = 0;
    for (int i = 0; i < 5; ++i)
    {
        int in;
        cin >> in;
        sum += in * in;
    }
    
    cout << sum % 10;    
    return 0;
}