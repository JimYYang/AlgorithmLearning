class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }

    // 依次枚举每个数  看看枚举多少次
    void dfs(vector<int> &nums, int u, int target)
    {
        if (!target)
        {
            ans.push_back(path);
            return;
        }
        int n = nums.size();
        if (u == n)
            return;

        int k = u + 1;
        
        while (k < n && nums[k] == nums[u]) k++;
        int cnt = k - u;
        int cur = nums[u];

        for (int i = 0; i * cur <= target && i <= cnt; i++)
        {
            dfs(nums, k, target - i * cur); // 一次可能枚举多个数 跳过了好几个数
            path.push_back(cur);
        }

        for (int i = 0; i * cur <= target && i <= cnt; i++)
            path.pop_back();
    }
};
