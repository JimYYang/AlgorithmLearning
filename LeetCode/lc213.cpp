class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        vector<int> f(n + 1), g(n + 1);
        int res = INT_MIN;
        // 不选1
        for (int i = 2; i <= n; i++)
        {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }

        res = max(res, max(f[n], g[n]));

        // 选1 
        f[1] =nums[0];
        g[1] = INT_MIN;

        for (int i = 2; i <= n; i++)
        {
            f[i] = g[i - 1] + nums[i - 1];
            g[i] = max(f[i - 1], g[i - 1]);
        }
        return max(res, g[n]);
    }
};
