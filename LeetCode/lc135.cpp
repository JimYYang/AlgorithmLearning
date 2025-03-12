class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();

        vector<int> memo(n + 1, -1);

        function<int(int)> dp = [&](int x) -> int{
            int &ref = memo[x];
            if (ref != -1) return ref;
            ref = 1;

            if (x > 0 && ratings[x] > ratings[x - 1]) ref = max(ref, dp(x - 1) + 1); 
            if (x + 1 < n && ratings[x] > ratings[x + 1]) ref = max(ref, dp(x + 1) + 1); 

            return ref;
        };

        int res = 0;
        for (int i = 0; i < n; i++) res += dp(i);
        return res;

    }

};