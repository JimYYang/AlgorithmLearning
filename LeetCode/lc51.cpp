class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<bool> col(n);
        vector<bool> dg(2 * n), idg(2 * n);

        vector<vector<string>> ans;
        vector<string> path(n, string(n, '.'));

        function<void(int)> dfs = [&](int u) {
            if (u == n)
            {
                ans.push_back(path);
                return;
            }

            for (int i = 0; i < n; i++)
            {
                if (!col[i] && !dg[u - i + n] && !idg[u + i])
                {
                    col[i] = dg[u - i + n] = idg[u + i] = true;
                    path[u][i] = 'Q';
                    dfs(u + 1);
                    path[u][i] = '.';
                    col[i] = dg[u - i + n] = idg[u + i] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
