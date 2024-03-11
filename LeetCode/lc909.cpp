using PII = pair<int, int>;
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<int>> id(n, vector<int>(n));
        vector<PII> coor(n * n + 1);

        for (int i = n - 1, k = 1, s = 0; i >= 0; i--, s++)
        {
            if (s % 2 == 0)
            {
                for (int j = 0; j < n; j++, k++)
                {
                    id[i][j] = k;
                    coor[k] = {i, j};
                }
            }
            else
            {
                for (int j = n - 1; j >= 0; j--, k++)
                {
                    id[i][j] = k;
                    coor[k] = {i, j};
                }
            }
        }

        queue<PII> que;
        vector<vector<int>> dist(n, vector<int>(n, 1e9));


        que.push({n - 1, 0});
        dist[n - 1][0] = 0;

        while (que.size())
        {
            auto cur = que.front();
            que.pop();
            int x = cur.first, y = cur.second;
            int k = id[x][y];
            if (k == n * n) return dist[x][y];
            for (int i = k + 1; i <= min(k + 6, n * n); i++)
            {
                int a = coor[i].first, b = coor[i].second;
                if (board[a][b] == -1)
                {
                    if (dist[a][b] > dist[x][y] + 1)
                    {
                        dist[a][b] = dist[x][y] + 1;
                        que.push({a, b});
                    }
                }
                else
                {
                    int m = board[a][b];
                    a = coor[m].first, b = coor[m].second;
                    if (dist[a][b] > dist[x][y] + 1)
                    {
                        dist[a][b] = dist[x][y] + 1;
                        que.push({a, b});
                    }
                }
            }
        }
        return -1;
    }
};

