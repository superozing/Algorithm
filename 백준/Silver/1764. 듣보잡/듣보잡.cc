#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>
#include <string>
#include <unordered_set>

#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, M;
	cin >> N >> M;

	unordered_set<string> us;
	vector<string> answer;

	string in;

	while (N--)
	{
		cin >> in;
		us.insert(in);
	}
	while (M--)
	{
		cin >> in;
		if (us.find(in) != us.end())
			answer.push_back(in);
	}

	sort(begin(answer), end(answer));

	cout << answer.size() << endl;
	for (string& s : answer)
		cout << s << endl;

	return 0;
}
