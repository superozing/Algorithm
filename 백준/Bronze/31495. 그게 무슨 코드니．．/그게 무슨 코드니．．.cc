#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    
    if (s.length() < 3)
    {
        cout << "CE";
        return 0;
    }
    
    cout << (s.front() == '\"' && s.back() == '\"' ? s.substr(1, s.length() - 2) : "CE"); 
    
    return 0;
}