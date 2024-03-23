class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> left(n), right(n);
        stack<int> stk;

        for (int i = 0; i < n; i++)
        {
            int cur = heights[i];
            while (stk.size() && heights[stk.top()] >= cur) stk.pop();
            if (stk.size()) left[i] = stk.top();
            else left[i] = -1;
            stk.push(i);
        }

        stk = stack<int>();
        for (int i = n - 1; i >= 0; i--)
        {
            int cur = heights[i];
            while (stk.size() && heights[stk.top()] >= cur) stk.pop();
            if (stk.size()) right[i] = stk.top();
            else right[i] = n;
            stk.push(i);
        }

        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res = max(res, (right[i] - left[i] - 1) * heights[i]);
        }
        return res;
    }
};
