class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        int k = 0;
        
        vector<vector<int>> res;
        while (k < n && intervals[k][1] < newInterval[0]) res.push_back(intervals[k++]);

        if (k < n)
        {
            newInterval[0] = min(newInterval[0], intervals[k][0]);
            while (k < n && intervals[k][0] <= newInterval[1])
            {
                newInterval[1] = max(newInterval[1], intervals[k][1]);
                k++;
            }
        }
        res.push_back(newInterval);
        while (k < n) res.push_back(intervals[k++]);

        return res;
    }
};
