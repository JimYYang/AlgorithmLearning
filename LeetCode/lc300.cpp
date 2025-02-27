class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> que;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int cur = nums[i];
            if (que.empty() || cur > que.back()) que.push_back(cur);
            else
            {
                if (cur <= que[0]) que[0] = cur;
                else
                {
                    int l = 0, r = que.size() - 1;
                    while (l < r)
                    {
                        int mid = l + r + 1 >> 1;
                        if (que[mid] < cur) l = mid;
                        else r = mid - 1;
                    }
                    que[l + 1]  = cur;
                }
            }
        }
        return que.size();
    }
};
