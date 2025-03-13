class Solution {
public:
    string reverseWords(string s) {
        int k = 0, n = s.size();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == ' ') continue;
            int j = i, t = k;
            while (j < n && s[j] != ' ') s[t++] = s[j++];
            reverse(s.begin() + k, s.begin() + t);
            s[t++] = ' ';
            k = t;
            i = j;
        }
        if (k) k--;
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.begin() + k);
        return s;
    }
};