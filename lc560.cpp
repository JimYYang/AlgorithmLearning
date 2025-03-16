class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        // 求前面有多少 直接哈希表
        int n = nums.size();
        vector<int> s(n + 1);
        for (int i = 1; i <= n; i++) s[i] = s[i - 1] + nums[i - 1];

        unordered_map<int, int> cnt;
        cnt[0] = 1;
        int res = 0;
        for (int i = 1; i <= n; i++)
        { 
            res += cnt[s[i] - k];
            cnt[s[i]]++;
        }
        return res;
    }
};
