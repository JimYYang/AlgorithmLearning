class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0, step = 0, maxPos = 0;
        // 不需要访问最后一个位置，因为如果访问前，最远一定可以到最后一个位置，如果再访问，边界刚好为最后一个位置，会多条一次
        // 比如 1211z这个例子
        for (int i = 0; i < n - 1; i++)
        {
            maxPos = max(maxPos, nums[i] + i);
            if (i == end)
            {
                step++;
                end = maxPos;
            }
        }
        return step;
    }
};