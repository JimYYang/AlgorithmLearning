class Solution {
public:
    int res{0};
    int n, m;
    int numIslands(vector<vector<char>>& grid) {
        n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == '1')
                {
                    dfs(i, j, grid);
                    res++;
                }
            }
        }
        return res;
    }
    array<int, 4> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};
    void dfs(int x, int y, vector<vector<char>> &grid)
    {
        grid[x][y] = 'X';

        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a >= n || b < 0 || b >= m || grid[a][b] != '1')
                continue;
            dfs(a, b, grid);
        }
    }
};