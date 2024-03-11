class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valid;
        for (auto &s : bank) valid.insert(s);

        unordered_map<string, int> dist;
        queue<string> que;
        que.push(startGene);
        dist[startGene] = 0;

        char chs[4] = {'A', 'C', 'G', 'T'};

        while (que.size())
        {
            auto cur = que.front();
            que.pop();

            for (int i = 0; i < cur.size(); i++)
            {
                string s = cur;
                for (int j = 0; j < 4; j++)
                {
                    s[i] = chs[j];

                    if (valid.count(s) && dist.count(s) == 0)
                    {
                        dist[s] = dist[cur] + 1;
                        if (s == endGene)
                            return dist[s];
                        que.push(s);
                    }
                }
            }
        }
        return -1;
    }
};
