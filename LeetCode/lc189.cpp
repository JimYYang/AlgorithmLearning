class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n;
        function<void(int, int)> reverse = [&](int l, int r){
            while (l < r)
            {
                swap(nums[l++], nums[r--]);
            }
        };
        reverse(0, n - 1);
        reverse(0, k - 1);
        reverse(k, n - 1);
    }
};
