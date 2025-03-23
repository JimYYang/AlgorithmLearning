class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int f = nums[0], g = nums[0];
        int res = f;
        for (int i = 1; i < n; i++)
        {
            int a = nums[i], fa = f * a, ga = g * a;
            f = max(a, max(fa, ga));
            g = min(a, min(fa, ga));
            res = max(res, f);
        }
        return res;
    }
};
