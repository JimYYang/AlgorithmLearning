class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1);

        for (int i = 1; i <= n; i++)
        {
            dp[i] = nums[i - 1];
            if (i >= 2) dp[i] += dp[i - 2];

            dp[i] = max(dp[i], dp[i - 1]);
        }
        return dp[n];
    }
};
