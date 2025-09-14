#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    char dist = 'a' - 'A';
    
    for (char c : s)
    {
        if ('A' <= c && c <= 'Z')
            cout << char(c + dist);
        else
            cout << char(c - dist);
    }
    
    return 0;
}