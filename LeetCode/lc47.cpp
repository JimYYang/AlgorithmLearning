class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;
    vector<bool> used;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        path.resize(n);
        used.resize(n);
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int> &nums, int u)
    {
        if (u == nums.size())
        {
            ans.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); i++)
        {
            if (!used[i])
            {
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;
                used[i] = true;
                path[u] = nums[i];
                dfs(nums, u + 1);
                used[i] = false;
            }
        }
    }


};
