class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();

        vector<int> f(n + 1);
        int res = INT_MIN;
        int last = 0;
        for (int i = 0; i < n; i++)
        {
            last = nums[i] + max(last, 0);
            res = max(res, last);
        }
        return res;
    }
};
