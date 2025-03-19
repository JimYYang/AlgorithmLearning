class Solution {
public:
    vector<int> missingTwo(vector<int>& nums) {
        int m = nums.size();
        int n = m + 2;
        int sum = n * (n + 1) / 2;
        for (auto num : nums) sum -= num;
        int two_sum = sum;
        int mid = two_sum / 2;

        int cur = mid * (mid + 1) / 2;
        for (auto num : nums)
        {
            if (num <= mid) cur -= num;
        }
        return {cur, two_sum - cur};

    }
};
