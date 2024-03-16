class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9] = {0};
        int columns[9][9] = {0};
        int matrix[3][3][9] = {0};

        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                char cur = board[i][j];

                if (cur != '.')
                {
                    int index = cur - '0' - 1;
                    rows[i][index]++;
                    columns[j][index]++;
                    matrix[i / 3][j / 3][index]++;

                    if (rows[i][index] > 1 || columns[j][index] > 1 || matrix[i / 3][j / 3][index] > 1)
                        return false;
                }
            }
        }
        return true;
    }
};
