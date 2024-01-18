#include <iostream>
#include <vector>
#include <string>

using namespace std;


class BAEKJOON_2805 // 퇴사
{
public:
	int			m_treeLength;
	int			m_MaxLength = 0;
	vector<int> m_vecTree;

public:
	void init();
	void progress();

	long long cutTree(long long _size);
};



void BAEKJOON_2805::init()
{
	long long n = 0;
	long long buf = 0;

	cin >> n;
	cin >> buf;

	m_treeLength = buf;

	for (long long i = 0; i < n; ++i)
	{
		cin >> buf;

		if (buf > m_MaxLength)
			m_MaxLength = buf;

		m_vecTree.push_back(buf);
	}
}

long long BAEKJOON_2805::cutTree(long long _size)
{
	long long treeLength = 0;
	long long CutSize = 0;

	for (auto& iter : m_vecTree)
	{
		CutSize = iter - _size;

		if (CutSize > 0)
			treeLength += CutSize;
	}

	return treeLength;
}

void BAEKJOON_2805::progress()
{
	// 이거... 투포인터를 사용하면 되겠는걸?

	// 제일 높은 나무의 길이를 인자를 입력 받을 때 체크하고
	// min 길이를 0으로 설정해서
	// 만약 가운데 높이로 절단한 나무의 총 길이가 m_treeLength보다 크면 가운데 높이를 제일 높은 길이로 설정.
	// 아니면 제일 낮은 길이로 설정.
	// 만약 같은 길이가 나오면 더이상 탐색할 필요가 없어진다..!!

	long long low = 0;
	long long high = m_MaxLength;

	long long curHeight = 0;
	long long cutTreeSize = 0;

	while (true)
	{
		curHeight = (low + high) / 2;

		cutTreeSize = cutTree(curHeight);

		if (m_treeLength < cutTreeSize)
			 low = curHeight;
		else if (m_treeLength > cutTreeSize)
			 high = curHeight;
		else
		{
			printf("%d", curHeight);
			return;
		}

		if (high - low < 10)
			break;
	}

	for (; low != high;  --high)
	{
		if (m_treeLength <= cutTree(high))
			break;
	}

	printf("%d", high);
	return;
}


int main()
{
	BAEKJOON_2805 b;

	b.init();
	b.progress();
	return 0;

}

