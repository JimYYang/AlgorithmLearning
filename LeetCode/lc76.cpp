class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        unordered_map<char, int> tot;
        for (auto c : t) tot[c]++;

        int left = 0;
        unordered_map<char, int> window;
        int cnt = 0;
        string res;
        for (int right = 0; right < n; right++)
        {
            window[s[right]]++;
            if (window[s[right]] <= tot[s[right]])
            {
                cnt++;
            }
            while (window[s[left]] > tot[s[left]])
            {
                window[s[left++]]--;
            }
            if (cnt == m)
            {
                if (res.empty() || right - left + 1 < res.size())
                {
                    res = s.substr(left, right - left + 1);
                }
            }
        }
        return res;
    }
};
