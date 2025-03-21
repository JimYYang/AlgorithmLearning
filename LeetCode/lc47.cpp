class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n);
        vector<int> path;
        path.reserve(n);
        vector<vector<int>> ans;

        function<void(int)> dfs = [&](int u) 
        {
            if (u == n)
            {
                ans.push_back(path);
                return;
            }

            for (int i = 0; i < n; i++)
            {
                if (!used[i])
                {
                    if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
                    used[i] = true;
                    path.push_back(nums[i]);
                    dfs(u + 1);
                    path.pop_back();
                    used[i] = false;
                }
            }
        };
        // 注意 数组不一定是有序的
        sort(nums.begin(), nums.end());
        dfs(0);
        return ans;
    }
};