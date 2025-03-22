class Solution {
public:
    string decodeString(string s) {
        int u = 0;
        return dfs(s, u);
    }

    // 因为这题需要用到递归后的u  所以需要传引用
    string dfs(string &s, int &u)
    {
        string res;
        while (u < s.size() && s[u] != ']')
        {
            if ((s[u] >= 'a' && s[u] <= 'z') || s[u] >= 'A' && s[u] <= 'Z') res += s[u++];
            else if (s[u] >= '0' && s[u] <= '9')
            {
                int k = u;
                while (k < s.size() && s[k] >= '0' && s[k] <= '9') k++;
                int num = stoi(s.substr(u, k - u));
                u = k + 1; // 过滤[
                string y = dfs(s, u);
                u++; // 过滤掉]
                while (num--) res += y;
            }
        }
        return res;
    }
};
