#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <stack>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int in;
	cin >> in;
	cout << (!(in % 4) && in % 100 ? 1 : !(in % 400) ? 1 : 0);


	return 0;
}
 