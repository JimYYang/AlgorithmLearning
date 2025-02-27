class Solution {
public:
    int coinChange(vector<int>& coins, int m) {
        // 总体积恰好为m
        vector<int> f(m + 1, 1e8);
        f[0] = 0;
        for (auto coin : coins)
        {
            for (int j = coin; j <= m; j++)
            {
                f[j] = min(f[j], f[j - coin] + 1);
            }
        }
        if (f[m] == 1e8) return -1;
        return f[m];
    }
};