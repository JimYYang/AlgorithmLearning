class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int num : nums) sum += num;

        if (sum & 1) return false;
        sum /= 2;
        vector<bool> f(sum + 1);
        f[0] = true;
        for (auto num : nums)
        {
            for (int j = sum; j >= num; j--)
                f[j] = f[j] || f[j - num];
        }
        return f[sum];
    }
};
