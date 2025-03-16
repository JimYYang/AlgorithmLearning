class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int>&b) {
            return a[0] < b[0];
        });
        vector<vector<int>> res;

        auto it = intervals.begin();
        int left = (*it)[0], right = (*it)[1];

        for (++it; it != intervals.end(); it++)
        {
            if ((*it)[0] <= right)
            {
                right = max(right, (*it)[1]);
            }
            else
            {
                res.push_back({left, right});
                left = (*it)[0];
                right = (*it)[1];
            }
        }
        // 最后一个不要忘了
        res.push_back({left, right});
        return res;
    }
};