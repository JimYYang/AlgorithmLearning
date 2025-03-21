class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        string symbols[10]{
            "", "", "abc", "def",
            "ghi", "jkl", "mno",
            "pqrs", "tuv", "wxyz"
        };

        vector<string> ans;
        string path;
        function<void(int)> dfs = [&](int u)
        {
            if (u == digits.size())
            {
                ans.push_back(path);
                return;
            }
            // cout << digits[u] - '0' << endl;
            for (auto c : symbols[(digits[u] - '0')])
            {
                path.push_back(c);
                dfs(u + 1);
                path.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};