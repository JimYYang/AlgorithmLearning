class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> res;
        vector<int> path;
        int n = candidates.size();
        function<void(int, int)> dfs = [&](int left,  int u) -> void
        {
            if (left == 0)
            {
                res.push_back(path);
                return;
            }
            
            // 这个题也可以用复杂的方法  枚举每个数填几次
            for (int i = u; i < n; i++)
            {
                if (candidates[i] > left) break;
                // 在当前层 不用相同的数字
                if (i > u && candidates[i] == candidates[i - 1]) continue;
                path.push_back(candidates[i]);
                dfs(left - candidates[i], i + 1);
                path.pop_back();
            }
        };
        dfs(target, 0);
        return res;
    }
};