#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int A, B;
	cin >> A >> B;

	while (!(A == 0 && B == 0))
	{
		cout << A + B << endl;
		cin >> A >> B;
	}

	return 0;
}
