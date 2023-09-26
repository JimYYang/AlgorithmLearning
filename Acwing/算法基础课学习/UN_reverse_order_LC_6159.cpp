typedef long long LL;

class Solution {
public:
    vector<int> p;
    vector<LL> s;

    int find(int x){
        if(p[x] != x)p[x] = find(p[x]);
        return p[x];
    }
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();

        for(int i = 0; i < n; i ++){
            p.push_back(i);
            s.push_back(0);
        }
        vector<LL>res;
        LL maxs = 0;
        for(int i = n - 1; i >= 0; i --){
            int x = removeQueries[i];

            s[x] = nums[x];

            for(int j = x - 1; j <= x + 1; j += 2){
                if(j >= 0 && j < n && s[j] > 0){
                    s[x] += s[find(j)];
                    p[find(j)] = x;
                }
            }

            res.push_back(maxs);
            maxs = max(maxs, s[x]);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};
