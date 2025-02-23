class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        int n = nums.size(), l = 0, r = n - 1;

        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if (nums[mid] >= nums[0]) l = mid;
            else r = mid - 1;
        }

        if (target >= nums[0]) l = 0;
        else {l = r + 1, r = n - 1;}
        while (l < r)
        {
            int mid = l + r >> 1;
            if (nums[mid] >= target) r = mid;
            else l = mid + 1;
        }

        // 【1】 0这个例子  l = r + 1的时候可能越界了
        if (nums[r] == target) return l;
        return -1;
    }
};