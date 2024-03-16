class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
            return a[0] < b[0];
        });

        vector<vector<int>> ans;

        ans.push_back(intervals[0]);

        for (auto cur = intervals.begin(); cur != intervals.end(); cur++)
        {
            if ((*cur)[0] <= ans.back()[1])
            {
                ans.back()[1] = max(ans.back()[1], (*cur)[1]);
            }
            else
            {
                ans.push_back(*cur);
            }
        }
        return ans;
    }
};
