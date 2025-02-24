class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();

        function<int(int, int, int)> quickSelect = [&](int l, int r, int k)
        {
            if (l == r) return nums[l];

            int x = nums[(l + r) / 2], i = l - 1, j = r + 1;
            while (i < j)
            {
                while (nums[++i] > x);
                while (nums[--j] < x);
                if (i < j) swap(nums[i], nums[j]);
            }
            int sl = j - l + 1;
            if (k <= sl) return quickSelect(l, j, k);
            return quickSelect(j + 1, r, k - sl);
        };
        return quickSelect(0, n - 1, k);
    }
};