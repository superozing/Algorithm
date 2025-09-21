#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    string s;
    for (int i = 0; i < N; ++i)
    {
        cin >> s;
        cout << s.front() << s.back() << '\n';
    }
    
    return 0;
}