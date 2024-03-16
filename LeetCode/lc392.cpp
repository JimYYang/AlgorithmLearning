class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size(), m = t.size();
        if (n > m) return false;
        if (!m && n) return false;
        int i = 0, j = 0;
        while (i < n)
        {
            while (j < m && s[i] != t[j]) j++;
            if (j == m) return false;
            i++;
            j++;
            if (i == n) return true;
        }
        return true;
    }
};
