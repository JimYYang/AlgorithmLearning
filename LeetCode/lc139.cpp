class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> hash;
        for (const auto &word : wordDict) hash.insert(word);
        s = ' ' + s; // 注意字符串的dp问题 有时候需要加个空格
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                string cur = s.substr(j, i - j + 1);
                if (hash.count(cur))
                {
                    dp[i] = dp[i] || dp[j - 1];
                }
            }
        }
        return dp[n];
    }
};