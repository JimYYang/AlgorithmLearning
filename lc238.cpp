class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int pre = 1, suf = 1, n = nums.size();
        vector<int> res(n, 1);
        for (int i = 0; i < n; i++)
        {
            res[i] *= pre;
            pre *= nums[i];
            res[n - i - 1] *= suf;
            suf *= nums[n - i - 1];
        }
        return res;
    }
};
