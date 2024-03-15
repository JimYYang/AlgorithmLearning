class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 1, n = nums.size(), maxPos = 0;
        int res = 0;
        while (end < n)
        {
            for (int i = start; i < end; i++)
            {
                maxPos = max(maxPos, nums[i] + i);
            }
            res++;
            start = end;
            end = maxPos + 1;
        }
        return res;
    }
};
