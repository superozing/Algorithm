class Solution {
public:
    int pivot;
    int nSize;

    int Idx(int i)
    {
        return (i + pivot) % nSize;
    }

    bool search(vector<int>& n, int target) 
    {
        // n은 알려지지 않은 피벗 인덱스를 기준으로 회전한 벡터
        // target이 n 안에 있는지 return 해야 해요.

        nSize = n.size();

        // 피벗 인덱스 왼 쪽과 오른 쪽을 기준으로 2번 해야 하는데,
        // 일단 피벗 인덱스를 찾아야 해요.
        for (int i = 1; i < n.size(); ++i)
        {
            if (n[i - 1] > n[i])
            {
                pivot = i;
                break;
            }
        }
        //cout << pivot;

        int l = 0;
        int r = n.size() - 1;

        while (l <= r)
        {
            int m = (l + r) / 2;
            int val = n[Idx(m)];

            if (val == target)
                return true;
            else if (val > target)
                r = m - 1;
            else
                l = m + 1;
        }

        return 0;
    }
};