class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> cnt;
        for (auto c : p) cnt[c]++;
        int m = p.size(), n = s.size();
        int types = cnt.size();
        vector<int> res;
        for (int left = 0, right = 0, satisfy = 0; right < n; right++)
        {
            if (--cnt[s[right]] == 0) satisfy++;
            while (right - left + 1 > m)
            {
                if (cnt[s[left]] == 0) satisfy--;
                cnt[s[left++]]++;
            }

            if (satisfy == types) res.push_back(left);
        }
        return res;
    }
};
