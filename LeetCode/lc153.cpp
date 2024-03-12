class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }
        if (r == n - 1) return nums[0];
        return nums[r + 1];
    }
};
