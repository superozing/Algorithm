#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

struct cmp
{
	bool operator() (const string& a, const string& b) const
	{
		return a.length() == b.length() ? a < b : a.length() < b.length();
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	set<string, cmp> m;

	int N;
	cin >> N;

	while (N--)
	{
		string in;
		cin >> in;
		m.insert(in);
	}

	for (auto& s : m)
		cout << s << endl;

	return 0;
}