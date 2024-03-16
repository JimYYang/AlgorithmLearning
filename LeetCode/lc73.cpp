class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool row0 = 1, col0 = 1;

        for (int i = 0; i < m; i++)
            if (!matrix[0][i]) row0 = 0;
        for (int i = 0; i < n; i++)
            if (!matrix[i][0]) col0 = 0;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (!matrix[i][j])
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // for (int i = 0; i < n; i++) cout << matrix[i][0] << ' ';
        // cout << '\n';
        // for (int i = 0; i < m; i++) cout << matrix[0][i] << ' ';
        // cout << '\n';

        for (int i = 1; i < m; i++)
        {
            if (!matrix[0][i])
            {
                for (int j = 1; j < n; j++)
                    matrix[j][i] = 0;
            }
        }

        for (int i = 1; i < n; i++)
        {
            if (!matrix[i][0])
            {
                for (int j = 1; j < m; j++)
                    matrix[i][j] = 0;
            }
        }

        if (!row0)
        {
            for (int i = 0; i < m; i++)
                matrix[0][i] = 0;
        }

        if (!col0)
        {
            for (int i = 0; i < n; i++)
                matrix[i][0] = 0;
        }
        if (!row0)
        {
            for (int i = 0; i < m; i++)
                matrix[0][i] = 0;
        }
    }
};
