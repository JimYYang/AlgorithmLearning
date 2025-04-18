class Solution {
public:
    using PII = pair<int, int>;
    int orangesRotting(vector<vector<int>>& grid) {
        queue<PII> que;

        int cnt{0};
        int n = grid.size(), m = grid[0].size();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1) cnt++;
                else if (grid[i][j] == 2)
                {
                    cnt++;
                    que.push({i, j});
                }
            }
        }

        int res{0};
        if (!que.empty()) res--;
        std::array<int, 4> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1}; 

        while (!que.empty())
        {
            int sz = que.size();

            res++;
            cnt -= sz;
            while (sz--)
            {
                auto cur = que.front();
                que.pop();
                int x = cur.first, y = cur.second;
                for (int i = 0; i < 4; i++)
                {
                    int a = x + dx[i];
                    int b = y + dy[i];

                    if (a < 0 || a >=n || b < 0 || b >= m || grid[a][b] != 1)
                        continue;
                    grid[a][b] = 2;
                    que.push({a, b});
                }
            }
        }

        if (cnt) return -1;
        return res;
    }
};