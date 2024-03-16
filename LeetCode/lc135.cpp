class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> f(n, -1);

        function<int(int)> dp = [&](int x) -> int {
            if (f[x] != -1) return f[x];

            f[x] = 1;
            if (x > 0 && ratings[x] > ratings[x - 1])
                f[x] = max(f[x], dp(x - 1) + 1);
            if (x + 1 < n && ratings[x] > ratings[x + 1])
                f[x] = max(f[x], dp(x + 1) + 1);
            return f[x]; 
        };

        int res = 0;
        for (int i = 0; i < n; i++) res += dp(i);

        return res;
    }
};
