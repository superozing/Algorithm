#include <iostream>

using namespace std;

int arr[6] {1, 1, 2, 2, 2, 8};

int main()
{
    int in;
    for (int i = 0; i < 6; ++i)
    {
        cin >> in;
        cout << arr[i] - in << ' ';
    }
    
    return 0;
}