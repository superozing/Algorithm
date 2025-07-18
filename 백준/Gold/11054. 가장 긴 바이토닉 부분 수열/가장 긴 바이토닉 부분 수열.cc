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

	int N;
	cin >> N;

	vector<int> in(N);
	vector<int> asc(N);
	vector<int> des(N);

	vector<int> ascStack;
	vector<int> desStack;

	for (int& i : in)
		cin >> i;

	for (int i = 0; i < N; ++i)
	{
		// 0. 비어있을 경우
		// 1. (ascending 기준) back()보다 클 경우
		// push_back()
		if (ascStack.empty() || ascStack.back() < in[i])
			ascStack.push_back(in[i]);
		
		// 2. back()보다 작을 경우
		else if (ascStack.back() > in[i])
		{
			// - 같은 값이 있다면 continue 해요.
			// - in[i]보다 큰 값이 나온다면 그 곳에 insert 해요.
			for (int j = 0; j < ascStack.size(); ++j)
			{
				if (ascStack[j] >= in[i])
				{
					ascStack[j] = in[i];
					break;
				}
			}
		}

		// 마지막에 ascStack의 길이만큼 인덱스에 세팅
		asc[i] = ascStack.size();


		if (desStack.empty() || desStack.back() < in[N - i - 1])
			desStack.push_back(in[N - i - 1]);

		else if (desStack.back() > in[N - i - 1])
		{
			for (int j = 0; j < desStack.size(); ++j)
			{
				if (desStack[j] >= in[N - i - 1])
				{
					desStack[j] = in[N - i - 1];
					break;
				}
			}
		}

		// 마지막에 ascStack의 길이만큼 인덱스에 세팅
		asc[i] = ascStack.size();
		des[N - i - 1] = desStack.size();
	}


	//cout << "ascStack.size(): " << ascStack.size() << endl;
	//for (int i = 0; i < ascStack.size(); ++i)
	//	cout << ascStack[i] << ' ';
	//
	//cout << endl;
	//cout << "desStack.size(): " << desStack.size() << endl;
	//for (int i = 0; i < desStack.size(); ++i)
	//	cout << desStack[i] << ' ';
	//
	//cout << endl;
	//cout << "asc.size(): " << asc.size() << endl;
	//for (int i = 0; i < asc.size(); ++i)
	//	cout << asc[i] << ' ';	
	//
	//cout << endl;
	//cout << "des.size(): " << des.size() << endl;
	//for (int i = 0; i < des.size(); ++i)
	//	cout << des[i] << ' ';
	//cout << endl;

	int answer = 0;
	for (int i = 0; i < N; ++i)
		answer = max(asc[i] + des[i] - 1, answer);

	cout << answer;

	return 0;
}
 