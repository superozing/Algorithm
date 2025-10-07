#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;
    
    cin >> a >> b;
    
    swap(a[0], a[2]);
    swap(b[0], b[2]);
    
    cout << max(stoi(a), stoi(b));
    
    return 0;
}
