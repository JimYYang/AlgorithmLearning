class Solution {
public:
    string reverseWords(string s) {
        stack<string> stk;
        stringstream ssin(s);

        string word;
        while (ssin >> word)
        {
            stk.push(word);
        }

        string res;
        while (stk.size())
        {
            res += stk.top();
            stk.pop();
            res += " ";
        }
        res.erase(res.size() - 1);
        return res;
    }
};
