class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n), dg(2 * n), idg(2 * n);

        function<int(int)> dfs = [&](int u) -> int {
            if (u == n) return 1;

            int res = 0;
            for (int i = 0; i < n; i++)
            {
                if (!col[i] && !dg[u - i + n] && !idg[u + i])
                {
                    col[i] = dg[u - i + n] = idg[u + i] = true;
                    res += dfs(u + 1); 
                    col[i] = dg[u - i + n] = idg[u + i] = false;
                }
            }
            return res;
        };
        return dfs(0);
    }
};
