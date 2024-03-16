class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();

        for (int i = 0; i < n - 2; i++)
        {
            int cur = nums[i];
            if (i && nums[i - 1] == cur) continue;
            int j = i + 1, k = n - 1;
            while (j < k)
            {
                int sum = cur + nums[j] + nums[k];
                if (sum > 0) k--;
                else if (sum < 0) j++;
                else 
                {
                    res.push_back({cur, nums[j], nums[k]});
                    j += 1;
                    while (j < k && nums[j] == nums[j - 1]) j++;
                    k -= 1;
                    while (j < k && nums[k] == nums[k + 1]) k--;
                }
            }
        }
        return res;
    }
};
