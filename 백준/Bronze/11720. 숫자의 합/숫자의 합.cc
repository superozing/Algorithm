#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s >> s;
    
    int sum = 0;
    for (char c : s)
        sum += c - '0';
    
    cout << sum;
    
    return 0;
}