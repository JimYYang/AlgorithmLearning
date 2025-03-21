class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // 考虑顺序 不能用背包求解
        // dp问题注意初始化
        vector<unsigned> dp(target + 1);
        // dp问题的初始化很重要
        dp[0] = 1; // 空集也是一种方案

        for (int i = 1; i <= target; i++)
        {
            for (auto num : nums)
            {
                if (i >= num)
                {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
