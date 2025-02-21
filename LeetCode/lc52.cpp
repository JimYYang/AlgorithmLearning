class Solution {
public:
    int totalNQueens(int n) {
       vector<bool> col(n);
        vector<bool> dg(2 * n), rdg(2 * n);
        int ans = 0;
        vector<string> path(n, string(n, '.'));

        function<void(int)> dfs = [&](int u) {
            if (u == n)
            {
                ++ans;
                return;
            }

            for (int i = 0; i < n; i++)
            {
                if (!col[i] && !dg[u + i] && !rdg[u - i + n])
                {
                    col[i] = dg[u + i] = rdg[u - i + n] = true;
                    path[u][i] = 'Q';
                    dfs(u + 1);
                    path[u][i] = '.';
                    col[i] = dg[u + i] = rdg[u - i + n] = false;
                }
            }
        };
        dfs(0);
        return ans; 
    }
};