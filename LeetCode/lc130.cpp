class Solution {
public:
    // 注意 全局变量不要重新定义 不要重新定义
    int n, m;
    vector<vector<char>> grid;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    void solve(vector<vector<char>>& board) {
        grid = board;
        n = board.size();
        if (!n) return;
        m = board[0].size();

        for (int i = 0; i < n; i++)
        {
            if (grid[i][0] == 'O') dfs(i, 0);
            if (grid[i][m - 1] == 'O') dfs(i, m - 1);
        }

        for (int i = 0; i < m; i++)
        {
            if (grid[0][i] == 'O') dfs(0, i);
            if (grid[n - 1][i] == 'O') dfs(n - 1, i);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                // 不要把判断写成等于
                if (grid[i][j] == '#') grid[i][j] = 'O';
                else grid[i][j] = 'X';
            }
        }
        board = std::move(grid);
    }

    void dfs(int x, int y)
    {
        grid[x][y] = '#';

        for (int i = 0; i < 4; i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m && grid[a][b] == 'O')
                dfs(a, b);
        }
    }
};
