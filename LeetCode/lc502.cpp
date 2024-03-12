class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        vector<pair<int, int>> proj;
        int n = profits.size();
        for (int i = 0; i < n; i++) proj.push_back({capital[i], profits[i]});
        sort(proj.begin(), proj.end());

        priority_queue<int, vector<int>> heap;
        int i = 0;
        while (k --)
        {
            while (i < n && proj[i].first <= w) heap.push(proj[i].second), i++;
            if (heap.empty()) break;
            auto cur = heap.top();
            heap.pop();
            w += cur;
        }
        return w;
    }
};
