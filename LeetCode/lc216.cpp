class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int, int)> dfs = [&](int left, int cnt, int start)
        {
            if (!left)
            {
                if (!cnt)
                {
                    ans.push_back(path);
                }
            }

            if (cnt <= 0) return;

            for (int i = start; i <= 9; i++)
            {
                if (start > left) continue;
                path.push_back(i);
                dfs(left - i, cnt - 1, i + 1);
                path.pop_back();
            }
        };
        dfs(n, k, 1);
        return ans;
    }
};
