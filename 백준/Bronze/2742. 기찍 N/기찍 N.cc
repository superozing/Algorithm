#include <iostream>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    for (int i = N; i > 0; --i)
        cout << i << '\n';

    return 0;
}
