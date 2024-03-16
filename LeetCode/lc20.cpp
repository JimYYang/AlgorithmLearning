class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
            else
            {
                if (stk.size() && abs(c - stk.top()) <= 2)
                    stk.pop();
                else return false;
            }
        }
        return !stk.size();
    }
};
