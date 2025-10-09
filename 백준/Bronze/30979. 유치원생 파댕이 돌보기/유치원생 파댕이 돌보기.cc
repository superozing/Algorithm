#include <iostream>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    
    while (M--)
    {
        int in;
        cin >> in;
        N -= in;
    }
    
    cout << "Padaeng_i ";
    
    if (N <= 0)
        cout << "Happy";
    else
        cout << "Cry";
    
    return 0;
}
