class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int res = 0, preMax = 0, sufMax = 0;
        // 注意这里要写等于 最后相遇的时候也可以接水
        while (left <= right)
        {
            preMax = max(preMax, height[left]);
            sufMax = max(sufMax, height[right]);
            if (preMax < sufMax)
            {
                res += preMax - height[left++];
            }
            else
            {
                res += sufMax - height[right--];
            }
        }
        return res;
    }
};