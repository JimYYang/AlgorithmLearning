class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++)
        {
            int cur_bit = 0;
            for (auto num : nums)
            {
                cur_bit += (num >> i) & 1;
            }

            res |= (cur_bit % 3) << i;
        }
        return res;
    }
};
