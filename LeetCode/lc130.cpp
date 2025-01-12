class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        array<int, 4> dx {-1, 0, 1, 0};
        array<int, 4> dy {0, 1, 0, -1};

        function<void(int, int)> dfs = [&](int x, int y) -> void {
            board[x][y] = '#';

            for (int i = 0; i < 4; i++)
            {
                int a = x + dx[i];
                int b = y + dy[i];

                if (a >= 0 && a < n && b >= 0 && b < m && board[a][b] == 'O')
                {
                    dfs(a, b);
                }
            }
        };


        for (int i = 0; i < n; i++)
        {
            if (board[i][0] == 'O') dfs(i, 0);
            if (board[i][m - 1] == 'O') dfs(i, m - 1);
        }

        for (int i = 0; i < m; i++)
        {
            if (board[0][i] == 'O') dfs(0, i);
            if (board[n - 1][i] == 'O') dfs(n - 1, i);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == '#')
                {
                    board[i][j] = 'O';
                }
                else board[i][j] = 'X';
            }
        }
    }
};