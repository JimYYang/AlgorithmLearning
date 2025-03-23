class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        text1 = ' ' + text1;
        text2 = ' ' + text2;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
                if (text1[i] == text2[j])
                    f[i][j] = max(f[i][j], f[i - 1][j - 1] + 1);
            }
        }
        return f[n][m];
    }
};
