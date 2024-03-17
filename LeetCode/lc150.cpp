class Solution {
public:
    stack<int> stk;
    void eval(const string &s)
    {
        // 注意元素顺序
        int b = stk.top();
        stk.pop();
        int a = stk.top();
        stk.pop();

        if (s == "+")
            stk.push(a + b);
        else if (s == "-")
            stk.push(a - b);
        else if (s == "*")
            stk.push(a * b);
        else stk.push(a / b);
    }
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> s{"+", "-", "*", "/"};
        for (auto &token : tokens)
        {
            if (s.count(token)) eval(token);
            else stk.push(stoi(token));
        }
        return stk.top();
    }
};
