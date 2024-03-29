class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();

        vector<vector<int>> f (n + 1, vector<int>(m + 1));

        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (matrix[i - 1][j - 1] == '1')
                {
                    f[i][j] = min(f[i - 1][j], min(f[i][j - 1], f[i - 1][j - 1])) + 1;
                    res = max(res, f[i][j]);
                }
            }
        }
        return res * res;
    }
};
