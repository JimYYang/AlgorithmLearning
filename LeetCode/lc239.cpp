class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        std::deque<int> deq;
        int n = nums.size();
        vector<int> res;
        // res.reserve(n - k - 1);
        for (int i = 0; i < n; i++)
        {
            while (!deq.empty() && i - deq.front() + 1 > k) deq.pop_front();
            while (!deq.empty() && nums[deq.back()] <= nums[i]) deq.pop_back();
            deq.push_back(i);
            if (i >= k - 1)
            {
                res.push_back(nums[deq.front()]);
            }
        }
        return res;
    }
};
