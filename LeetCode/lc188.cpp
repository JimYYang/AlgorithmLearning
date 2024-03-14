class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> f(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1e9)));
        for (int i = 0; i <= n; i++) f[i][0][0] = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                f[i][j][0] = max(f[i - 1][j][0], f[i - 1][j][1] + prices[i - 1]);
                f[i][j][1] = max(f[i - 1][j][1], f[i - 1][j - 1][0] - prices[i - 1]);
            }
        }

        int res = 0;
        for (int i = 0; i <= k; i++) res = max(res, f[n][i][0]);
        return res;
    }
};
