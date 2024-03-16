class Solution {
public:
    bool isPalindrome(string s) {

        string tmp;
        for (char &c : s)
        {
            if (c >= 'a' && c <= 'z') tmp += c;
            if (c >= 'A' && c <= 'Z') tmp += c - 'A' + 'a';
            if (c >= '0' && c <= '9') tmp += c;
        }
        s = tmp;
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r]) return false;
            l++, r--;
        }
        return true;
    }
};
