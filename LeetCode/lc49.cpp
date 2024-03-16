class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> words;
        for (auto &str : strs)
        {
            string t = str;
            sort(t.begin(), t.end());
            words[t].push_back(str);
        }
        
        vector<vector<string>> res;
        for (auto &[_, v] : words)
        {
            res.push_back(v);
        }
        return res;
    }
};
