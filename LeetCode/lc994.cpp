class Solution {
public:
    using PII = pair<int, int>;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        queue<PII> que;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] == 1) cnt++;
                if (grid[i][j] == 2)
                {
                    cnt++;
                    que.push({i, j});
                }
            }
        }

        array<int, 4> dx{-1, 0, 1, 0}, dy{0, 1, 0, -1};

        int res = 0;
        if (!que.empty()) res--;
        while (!que.empty())
        {
            int sz = que.size();
            res++;
            cnt -= sz;
            while (sz--)
            {
                auto cur = que.front();
                que.pop();
                // 按层序遍历 每次pop在内层循环
                for (int i = 0; i < 4; i++)
                {
                    int a = cur.first + dx[i];
                    int b = cur.second + dy[i];
                    if (a < 0 || a >= n || b < 0 || b >= m || grid[a][b] != 1)
                        continue;
                    grid[a][b] = 2;
                    que.push({a, b});
                }
            }
        }
        if (cnt) res = -1;
        return res;
    }
};
