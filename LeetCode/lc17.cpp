class Solution {
public:
    vector<string> ans;
    string digits[10]{
        "", "", "abc", "def",
        "ghi", "jkl", "mno",
        "pqrs", "tuv", "wxyz"
    };

    vector<string> letterCombinations(string s) {
        if (s.empty()) return ans;
        dfs(s, 0, "");
        return ans;
    }

    void dfs(string &s, int u, string path)
    {
        if (u == s.size())
        {
            ans.emplace_back(path);
            return;
        }
        for (auto c : digits[s[u] - '0'])
        {
            dfs(s, u + 1, path + c);
        }
    }
};
