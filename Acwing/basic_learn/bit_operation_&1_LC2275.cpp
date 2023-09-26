class Solution {
public:
    int largestCombination(vector<int>& c) {
        int ans = 0, cnt = 0;
        int n = c.size();
        for(int i = 0; i < 24; i ++){
            cnt = 0;
            for(int j = 0; j < n; j ++){
                if(c[j] >> i & 1)
                    cnt ++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};
