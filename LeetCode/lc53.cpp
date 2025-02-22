class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = -1e9;
        int n = nums.size();
        vector<int> f(n + 1);

        for (int i = 1; i <= n; i++)
        {
            f[i] = max(nums[i - 1], f[i - 1] + nums[i - 1]);
            res = max(f[i], res);
        }

        return res;
    }
};