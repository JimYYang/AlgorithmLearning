class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -2e9;
        int n = nums.size();
        int cur = 0, last = 0;
        for (int i = 1; i <= n; i++)
        {
            // f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
            cur = max(nums[i - 1], last + nums[i - 1]);
            last = cur;
            res = max(res, cur);
        }

        return res;
    }
};