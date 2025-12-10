#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    while (N--)
    {
        string s;
        cin >> s;
        cout << (s.size() >= 6 && s.size() <= 9 ? "yes\n" : "no\n");
    }

    return 0;
}