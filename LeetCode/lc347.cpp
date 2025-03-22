class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        for (auto num : nums) cnt[num]++;

        vector<int> s(n + 1);
        for (auto [_, c] : cnt) s[c]++;
        int i = n, tot = 0;
        while (tot < k)
        {
            tot += s[i--];
        }
        vector<int> res;
        for (auto [x, c] : cnt)
        {
            if (c > i) res.push_back(x);
        }
        return res;
    }
};
