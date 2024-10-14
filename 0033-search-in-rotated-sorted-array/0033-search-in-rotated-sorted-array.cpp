/*

정수 배열 nums가 오름차순으로 정렬되어 있으며(모든 값이 서로 다릅니다), 
배열이 함수에 전달되기 전에 알려지지 않은 피벗 인덱스 k에서 회전되었을 수 있습니다(1 <= k < nums.length). 

배열이 회전된 결과는 다음과 같은 형태가 됩니다: 
[nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-인덱스 기준). 

예를 들어, [0,1,2,4,5,6,7] 배열이 피벗 인덱스 3에서 회전되면 [4,5,6,7,0,1,2]가 됩니다.

회전된 배열 nums와 정수 target이 주어졌을 때, nums에서 target의 인덱스를 반환하세요. target이 nums에 없다면 -1을 반환하세요.

이 알고리즘은 O(log n) 시간 복잡도로 동작해야 합니다.

*/


class Solution 
{
    int k = 0;
    int maxsize = 0;
    
public:
    int idx(int _idx) { return (_idx + k) % maxsize; }
    
    int search(vector<int>& nums, int target) 
    {
        // 어...음...
        // 일단 데이터가 오름차순으로 정렬되어 있기 때문에
        // 이분 탐색을 인덱스 접근을 잘 조절하면서 하는 문제인 것 같아요.
        // log n으로 동작하는...
        
        // l은 (0 + k) % k, r은 (nums.size() + k) % k
        // k를 필수적으로 알아야 문제 풀기 편할 것 같아요.
        
        maxsize = nums.size();
        
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i - 1] > nums[i])
            {
                k = i;
                break;
            }
        }
        
        //cout << k << endl;
        
        int l = 0;
        int r = nums.size() - 1;
        
        while (l <= r)
        {
            int m = (l + r) / 2; 
            //cout << "l: " << l << ", r: " << r << ", m: " << m <<endl;
            //cout << "idx: " << idx(m) << endl;
            if (nums[idx(m)] < target)
                l = m + 1;
            else if (nums[idx(m)] > target)
                r = m - 1;
            else
                return idx(m);
        }
        
        return -1;
    }
};