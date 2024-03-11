class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        function<void(int, int, string)> dfs = [&](int lsum, int rsum, string path) {
            if (lsum == n && rsum == n)
            {
                ans.push_back(path);
                return;
            }

            if (lsum < n) dfs(lsum + 1, rsum, path + '(');
            if (lsum > rsum && rsum < n) dfs(lsum, rsum + 1, path + ')');
        };
        dfs(0, 0, "");
        return ans;
    }
};
