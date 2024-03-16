class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        int n = s.size(), left = 0, right = n - 1;
        unordered_map<char, int> cnt;

        for (int right = 0; right < n; right++)
        {
            char c = s[right];
            cnt[c]++;
            while (cnt[c] > 1)
            {
                cnt[s[left]]--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};
