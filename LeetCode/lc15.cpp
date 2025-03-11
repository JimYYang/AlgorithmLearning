class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for (int i = 0; i < n - 2; i++)
        {
            if (i && nums[i] == nums[i - 1]) continue;
            int cur = nums[i];
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                int sum = cur + nums[left] + nums[right];
                if (sum < 0) left++;
                else if (sum > 0) right--;
                else
                {
                    res.push_back({cur, nums[left], nums[right]});
                    left++, right--;
                    while (left < right && nums[left] == nums[left - 1]) left++;
                    while (left < right && nums[right] == nums[right + 1]) right--;
                }
            }
        }
        return res;
    }
};