class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = n - 1;
        while (k > 0 && nums[k - 1] >= nums[k]) k--;
        if (k == 0) reverse(nums.begin(), nums.end());
        else
        {
            int t = n - 1;
            while (t >= k && nums[t] <= nums[k - 1]) t--;
            swap(nums[k - 1], nums[t]);
            reverse(nums.begin() + k, nums.end());
        }
    }
};
