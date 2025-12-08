#include <iostream>

using namespace std;

int main()
{
    int A, B;
    cin >> A >> A >> B;
    cout << (A == B ? "Anything" : (A < B ? "Bus" : "Subway"));
    
    return 0;
}