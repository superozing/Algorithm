#include <iostream>
#include <algorithm>
#include <cmath>

#include <string>

#define endl '\n'

using namespace std;

int Explosion(string& s, const string& exp)
{
	int expIdx = 0;

	//cout << "cur string: " << s << endl;

	for (int i = 0; i < exp.size(); ++i)
		s.pop_back();

	for (int i = 0; i < exp.size() && i < s.size(); ++i)
	{
		int idx = s.size() > exp.size() ? s.size() - exp.size() + i : i;
		//cout << "idx: " << idx << endl;
		if (s[idx] != exp[expIdx++])
			expIdx = exp[0] == s[idx];
	}

	// 폭발 후 현재 expIdx 반환
	return expIdx;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	string in;
	string explosion;

	cin >> in;
	cin >> explosion;

	string s;
	s.reserve(in.size());

	int expIdx = 0;
	for (char c : in)
	{
		s += c;

		if (explosion[expIdx++] != c)
			expIdx = explosion[0] == c;

		if (expIdx == explosion.size())
			expIdx = Explosion(s, explosion);

		//cout << "str: " << s << endl;
		//cout << "expIdx: " << expIdx << endl << endl;
	}

	cout << (s.empty() ? "FRULA" : s);

	return 0;
}
 