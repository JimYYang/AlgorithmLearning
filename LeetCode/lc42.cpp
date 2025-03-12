class Solution {
public:
    // https://www.acwing.com/solution/content/121/ 这个解法
    int trap(vector<int>& height) {
        stack<int> stk;
        int n = height.size();
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            while (!stk.empty() && height[stk.top()] <= height[i])
            {
                int top1 = stk.top();
                stk.pop();
                if (stk.empty()) break;
                // cout << (min(height[stk.top()], height[i]) - height[top1]) * (i - stk.top() - 1) << endl;
                ans += (min(height[stk.top()], height[i]) - height[top1]) * (i - stk.top() - 1);
            }
            stk.push(i);
        }
        return ans;
    }
};