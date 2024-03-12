class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(2 * n + 1);

        for (int i = 1; i <= 2 * n; i++)
        {
            sum[i] = sum[i - 1] + nums[(i - 1) % n];
        }

        deque<int> que;
        que.push_front(0);
        int res = -2e9;
        for (int i = 1; i <= 2 * n; i++)
        {
            // 注意 这里求得是i前面n-1个元素的最小值
            while (que.size() && i - que.front() > n) que.pop_front();
            // 先求值 再加入队列
            res = max(res, sum[i] - sum[que.front()]);
            while (que.size() && sum[que.back()] >= sum[i]) que.pop_back();
            que.push_back(i);
        }
        return res;
    }
};
