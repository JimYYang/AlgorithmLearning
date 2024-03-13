using VI = vector<int>;
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n = nums1.size(), m = nums2.size();
        function<void()> merge = [&]() {
            priority_queue<VI, vector<VI>, greater<VI>> heap;
            for (int i = 0; i < m; i++) heap.push({nums1[0] + nums2[i], 0, i});

            while (k-- && heap.size())
            {
                auto cur = heap.top();
                heap.pop();
                res.push_back({nums1[cur[1]], nums2[cur[2]]});
                if (cur[1] + 1 < n)
                heap.push({nums1[cur[1] + 1] + nums2[cur[2]], cur[1] + 1, cur[2]});
            }
        };

        merge();
        return res;
    }
};
