class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        vector<vector<int>> f(n, vector<int>(m, 1e9));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!i && !j) f[i][j] = grid[i][j];
                else 
                {
                    if (i > 0) f[i][j] = min(f[i][j], f[i - 1][j] + grid[i][j]);
                    if (j > 0) f[i][j] = min(f[i][j], f[i][j - 1] + grid[i][j]);
                }
            }
        }
        return f[n - 1][m - 1];
    }
};
