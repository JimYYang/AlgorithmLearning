class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        array<int, 4> dx {-1, 0, 1, 0};
        array<int, 4> dy {0, 1, 0, -1};

        function<void(int, int)> dfs = [&](int a, int b) -> void {
            grid[a][b] = '0';

            for (int i = 0; i < 4; i++)
            {
                int x = a + dx[i];
                int y = b + dy[i];

                if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == '0')
                {
                    continue;
                }
                dfs(x, y);
            }
        };
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};