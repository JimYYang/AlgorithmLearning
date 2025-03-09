class Solution {
public:
    std::array<std::array<bool, 9>, 9> rows{};
    std::array<std::array<bool, 9>, 9> cols{};
    std::array<std::array<std::array<bool, 9>, 3>, 3> subbox{};

    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    rows[i][num] = true;
                    cols[j][num] = true;
                    subbox[i / 3][j / 3][num] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }
    // 有返回值，一般不需要额外变量记录答案
    // 没有返回值，一般需要在递归终止的时候找个变量记录答案
    bool dfs(vector<vector<char>> &board, int x, int y)
    {
        if (y == 9) x++, y = 0;
        if (x == 9) return true;

        if (board[x][y] != '.') return dfs(board, x, y + 1);

        for (int i = 0; i < 9; i++)
        {
            if (!rows[x][i] && !cols[y][i] && !subbox[x / 3][y / 3][i])
            {
                rows[x][i] = cols[y][i] = subbox[x / 3][y / 3][i] = true;
                board[x][y] = '1' + i;
                if (dfs(board, x, y + 1)) return true;
                rows[x][i] = cols[y][i] = subbox[x / 3][y / 3][i] = false;
                board[x][y] = '.';
            }
        }
        return false;
    }
};
