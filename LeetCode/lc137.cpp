class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int curBitCnt = 0;
            for (auto num : nums)
            {
                curBitCnt += num >> i & 1;
            }
            res |= (curBitCnt % 3) << i;
        }
        return res;
    }
};