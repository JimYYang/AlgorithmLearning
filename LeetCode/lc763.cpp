class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<int, int> pos;

        int n = s.size();
        for (int i = 0; i < n; i++) pos[s[i]] = i;
        int start = 0, end = 0;
        vector<int> res;

        for (int i = 0; i < n; i++)
        {
            end = max(end, pos[s[i]]);
            if (end == i)
            {
                res.push_back(end - start + 1);
                start = end = i + 1;
            }
        }
        return res;
    }
};
