class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();

        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

        function<bool(int,int,int)> dfs;
        dfs = [&](int u, int i, int j) -> bool {
            if (board[i][j] != word[u]) return false;
            if (u == word.size() - 1) return true;

            // 每次搜索中 单词不能重复用
            char t = board[i][j];  
            board[i][j] = '.';
            for (int k = 0; k < 4; k++)
            {
                int a = i + dx[k], b = j + dy[k];
                if (a < 0 || a >= n || b < 0 || b >= m || board[a][b] == '.')
                    continue;
                if (dfs(u + 1, a, b))
                    return true;
            }
            board[i][j] = t;
            return false;
        };
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dfs(0, i, j))
                    return true;
            }
        }
        return false;
    }
};
