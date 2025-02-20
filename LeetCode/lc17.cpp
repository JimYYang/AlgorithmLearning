class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        string values[10]{
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        function<void(int, string)> dfs = [&](int u, string path)
        {
            if (u == digits.size())
            {
                ans.emplace_back(path);
                return;
            }

            for (auto c : values[(digits[u] - '0')])
            {
                dfs(u + 1, path + c);
            }
        };

        dfs(0, "");
        return ans;
    }
};