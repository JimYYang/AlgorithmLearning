class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++)
        {
            int l = i - 1, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) l--, r++;

            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);

            l = i, r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) l--, r++;

            if (res.size() < r - l - 1) res = s.substr(l + 1, r - l - 1);
        }
        return res;
    }
};
