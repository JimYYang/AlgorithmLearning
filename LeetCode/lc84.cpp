class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        stack<int> stk;
        vector<int> left(n), right(n);

        for (int i = 0; i < n; i++)
        {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty()) left[i] = -1;
            else left[i] = stk.top();
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = n - 1; i >= 0; i--)
        {
            while (!stk.empty() && heights[stk.top()] >= heights[i]) stk.pop();
            if (stk.empty()) right[i] = n;
            else right[i] = stk.top();
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
