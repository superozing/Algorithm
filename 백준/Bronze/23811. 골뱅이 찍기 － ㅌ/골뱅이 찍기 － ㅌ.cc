#include <iostream>

using namespace std;

int main()
{
    int N;
    cin >> N;
    
    
    string s[2];
    s[0] = "@@@@@";
    s[1] = "@";
    
    for (int i = 0; i < 5; ++i)
    {
        for (int n1 = 0; n1 < N; ++n1)
        {
            for (char c : s[i % 2])
                for (int n2 = 0; n2 < N; ++n2)
                    cout << c;
            
            cout << '\n';
        }
        
    }
    
    return 0;
}