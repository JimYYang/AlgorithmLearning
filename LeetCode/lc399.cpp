class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_set<string> nodes;
        unordered_map<string, unordered_map<string, double>> dist;
        for (int i = 0; i < equations.size(); i++)
        {
            string a = equations[i][0], b = equations[i][1];
            double val = values[i];
            nodes.insert(a), nodes.insert(b);
            dist[a][b] = val;
            dist[b][a] = 1 / val;
        }

        for (auto k : nodes)
        {
            for (auto i : nodes)
            {
                for (auto j : nodes)
                {
                    if (dist[i][k] && dist[k][j])
                        // 最短距离就是唯一距离
                        dist[i][j] = dist[i][k] * dist[k][j];
                }
            }
        }

        vector<double> ans;
        for (int i = 0; i < queries.size(); i++)
        {
            string a = queries[i][0], b = queries[i][1];
            if (dist[a][b]) ans.push_back(dist[a][b]);
            else ans.push_back(-1.0);
        }
        return ans;
    }
};
