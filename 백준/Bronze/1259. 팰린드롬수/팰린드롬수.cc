#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	string s;
	while (true)
	{
		cin >> s;

		if (s == "0")
			break;

		if (s.back() == '0')
		{
			cout << "no\n";
			continue;
		}

		bool isPalNum = true;
		for (int i = 0; i < s.size() / 2; ++i)
		{
			if (s[i] != s[s.size() - 1 - i])
			{
				isPalNum = false;
				break;
			}
		}

		cout << (isPalNum ? "yes\n" : "no\n");
	}

	return 0;
}