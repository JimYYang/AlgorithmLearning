class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> f(amount + 1, 2e8);
        f[0] = 0;

        for (auto coin : coins)
        {
            for (int j = coin; j <= amount; j++)
            {
                f[j] = min(f[j], f[j - coin] + 1);
            }
        }
        if (f[amount] == 2e8) return -1;

        return f[amount];
    }
};