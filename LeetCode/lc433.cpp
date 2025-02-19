class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> valid;
        for (auto &gene : bank)
        {
            valid.insert(gene);
        }

        array<char, 4> genes{'A', 'C', 'G', 'T'};

        queue<string> que;
        que.push(startGene);
        unordered_map<string, int> dist;
        dist[startGene] = 0;

        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                auto cur = que.front();
                que.pop();
                int len = cur.size();
                for (int j = 0; j < len; j++)
                {
                    string s = cur;
                    for (int k = 0; k < 4; k++)
                    {
                        s[j] = genes[k];

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
        }
        return -1;
    }
};