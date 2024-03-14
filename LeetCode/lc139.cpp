class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int n = s.size();
        vector<bool> dp(n + 10, false);

        dp[0] = true;
        s = ' ' + s;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                string tail = s.substr(j, i - j + 1);
                if (dict.find(tail) != dict.end())
                    if (dp[j - 1] == true) {
                        dp[i] = true;
                        break;
                    }
            }
        }
        return dp[n];
    }
};
