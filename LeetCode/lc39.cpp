class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();

        vector<vector<int>> ans;
        vector<int> path;

        function<void(int, int)> dfs = [&](int left, int u)
        {
            if (left == 0)
            {
                ans.push_back(path);
                return;
            }

            for (int i = u; i < n; i++)
            {
                if (candidates[i] > left) continue;
                path.push_back(candidates[i]);
                dfs(left - candidates[i], i);
                path.pop_back();
            }
        };
        dfs(target, 0);
        return ans;
    }
};