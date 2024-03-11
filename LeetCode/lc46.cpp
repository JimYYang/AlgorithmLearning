class Solution {
public:
    vector<int> path;
    vector<vector<int>> ans;
    vector<bool> used;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
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
                used[i] = true;
                path.push_back(nums[i]);
                dfs(nums, u + 1);
                used[i] = false;
                path.pop_back();
            }
        }
    }
};
