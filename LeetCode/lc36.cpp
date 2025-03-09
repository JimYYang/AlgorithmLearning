class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::array<std::array<bool, 9>, 9> rows{};
        std::array<std::array<bool, 9>, 9> cols{};
        std::array<std::array<std::array<bool, 9>, 3>, 3> subbox{};

        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0;  j < board[0].size(); j++)
            {
                if (board[i][j] != '.')
                {
                    int num = board[i][j] - '1';
                    if (rows[i][num] || cols[j][num] || subbox[i / 3][j / 3][num])
                        return false;
                    rows[i][num] = true;
                    cols[j][num] = true;
                    subbox[i / 3][j / 3][num] = true;
                }
            }
        }
        return true;
    }
};