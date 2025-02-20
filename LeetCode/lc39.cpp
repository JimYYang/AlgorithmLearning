class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> path;
        int n = candidates.size();

        function<void(int, int)> dfs = [&](int u, int left)
        {
            if (left == 0)
            {
                ans.push_back(path);
                return;
            }

            for (int i = u; i < n; i++)
            {
                if (left < candidates[i]) continue;

                path.push_back(candidates[i]);
                dfs(i, left - candidates[i]);
                path.pop_back();
            }
        };

        dfs(0, target);
        return ans;
    }
};