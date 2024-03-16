class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n = s.size();
        unordered_map<char, char> st, ts;

        for (int i = 0; i < n; i++)
        {
            int a = s[i], b = t[i];
            if (st.count(a) && st[a] != b) return false;
            st[a] = b;
            if (ts.count(b) && ts[b] != a) return false;
            ts[b] = a;
        }
        return true;
    }
};
