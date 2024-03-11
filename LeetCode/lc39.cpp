class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        dfs(candidates, 0, target);
        return ans;
    }

    void dfs(vector<int> &candidates, int u, int target)
    {
        if (!target)
        {
            ans.push_back(path);
            return;
        }

        if (u == candidates.size())
            return;

        for (int i = 0; i * candidates[u] <= target; i++)
        {
            for (int j = 0; j < i; j++) path.push_back(candidates[u]);
            dfs(candidates, u + 1, target - i * candidates[u]);
            for (int j = 0; j < i; j++) path.pop_back();
        }
    }
};
