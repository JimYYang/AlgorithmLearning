class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res;
        vector<vector<bool>> vi(n, vector<bool>(m));

        for (int i = 0, x = 0, y = 0, d = 0; i < n * m; i++)
        {
            res.push_back(matrix[x][y]);
            vi[x][y] = true;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || vi[a][b])
            {
                d = (d + 1) % 4;
                a = x + dx[d];
                b = y + dy[d]; 
            }
            x = a;
            y = b;
        }
        return res;
    }
};
