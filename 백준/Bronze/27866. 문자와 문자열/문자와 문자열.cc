#include <iostream>
#include <algorithm>
#include <cmath>

#include <string>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string s;
	cin >> s;
	int n;
	cin >> n;

	cout << s[n - 1];

	return 0;
}
 