#include <iostream>
#include <algorithm>
#include <cmath>

#include <string>
#include <unordered_map>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T;
	cin >> T;

	while (T--)
	{
		int N;
		cin >> N;

		unordered_map<string, int> um;

		while (N--)
		{
			string in;
			cin >> in >> in;
			um[in]++;
		}

		int answer = 1;

		for (auto& it : um)
			answer *= it.second + 1;

		cout << answer - 1 << endl;
	}

	return 0;
}
 