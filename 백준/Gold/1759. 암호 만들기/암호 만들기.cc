#include <iostream>
#include <algorithm>
#include <cmath>

#include <vector>

#define endl '\n'

using namespace std;

int L, C;
string in;
string cur;

void BackTracking(int idx)
{
	if (cur.size() == L)
	{
		int vowel = 0;
		int consonants = 0;
		for (char& c : cur)
		{
			if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
				vowel++;
			else
				consonants++;
		}

		if (vowel >= 1 && consonants >= 2)
			cout << cur << endl;
		return;
	}

	for (int i = idx; i < C; ++i)
	{
		cur.push_back(in[i]);
		BackTracking(i + 1);
		cur.pop_back();
	}
}


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> L >> C;

	in.resize(C);
	for (int i = 0; i < C; ++i)
		cin >> in[i];

	sort(begin(in), end(in));

	BackTracking(0);

	return 0;
}
