class Solution {
public:
    string convert(string s, int n) {
        if (n == 1)
            return s;
        int m = s.size();
        string res;
        for (int i = 0; i < n; i++) {
            if (!i || i == n - 1) {
                for (int j = i; j < m; j += 2 * n - 2)
                    res += s[j];
            }
            else {
                for (int j = i, k = 2 * n - 2 - i; j < m || k < m; j += 2 * n - 2, k += 2 * n - 2) {
                    if (j < m)
                        res += s[j];
                    if (k < m)
                        res += s[k];  
                }
            }
        }
        return res;
    }
};
