class Solution 
{
public:
    vector<int> searchRange(vector<int>& n, int target) 
    {
        vector<int> ret(2, -1);

        // 0. 예외 처리
        if (n.size() == 0)
            return ret;

        int lIdx = -1;
        int rIdx = -1;

        // 1. target 찾기
        int tIdx = -1;
        int l = 0;
        int r = n.size() - 1;

        while (l <= r)
        {
            int m = (l + r) / 2;

            // 타겟을 찾았나요?
            if (n[m] == target)
            {
                tIdx = m;
                break;
            }
            else if (n[m] < target)
                l = m + 1;
            else
                r = m - 1;
        }
        // 여기서 없으면 return vector<int>(2, -1);
        if (tIdx == -1)
            return ret;

        //cout << tIdx << endl;

        // 2. 찾은 target index를 left로 두고 오른 쪽 인덱스 찾기
        l = tIdx;
        r = n.size() - 1;
        while (l <= r)
        {
            int m = (l + r) / 2;

            // 타겟을 찾았나요?
            if (n[m] == target)
                l = m + 1;
            else
                r = m - 1;
        }

        rIdx = r;

        // 3. 찾은 target index를 right로 두고 왼 쪽 인덱스 찾기
        l = 0;
        r = tIdx;
        while (l <= r)
        {
            int m = (l + r) / 2;

            // 타겟을 찾았나요?
            if (n[m] == target)
                r = m - 1;
            else
                l = m + 1;
        }
        
        lIdx = l;

        //cout << lIdx << rIdx << endl;

        ret[0] = lIdx;
        ret[1] = rIdx;

        return ret;
    }
};