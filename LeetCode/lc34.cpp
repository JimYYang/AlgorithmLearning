class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) return {-1, -1};

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;

            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        if (nums[l] != target) return {-1, -1};
        vector<int> ans;
        ans.push_back(l);
        l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (nums[mid] <= target) l = mid;
            else r = mid - 1;
        }
        ans.push_back(l);
        return ans;
    }
};
