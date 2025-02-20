class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 包含重复元素 一次

        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();

        function<void(int, int)> dfs = [&](int u, int left) {
            if (left == 0)
            {
                ans.push_back(path);
                return;
            }

            for (int i = u; i < n; i++)
            {
                if (candidates[i] > left) continue;
                if (i > u && candidates[i] == candidates[i - 1]) continue;

                path.push_back(candidates[i]);
                dfs(i + 1, left - candidates[i]);
                path.pop_back();
            }
        };
        sort(candidates.begin(), candidates.end());
        dfs(0, target);
        return ans;
    }
};