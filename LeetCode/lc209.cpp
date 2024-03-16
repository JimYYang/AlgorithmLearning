class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0, sum = 0;
        int res = n + 1;

        for (int right = 0; right < n; right++)
        {
            int cur = nums[right];
            sum += cur;
            while (sum >= target)
            {
                res = min(res, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return res == n + 1 ? 0 : res;
    }
};
