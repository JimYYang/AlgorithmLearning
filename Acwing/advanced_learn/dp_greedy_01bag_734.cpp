nclude <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e4 + 10;

int dp[N];

struct Stone{
    int s, e, l;
    bool operator < (const Stone &w){
        return s * w.l < l * w.s;
    }
}stones[N];


int main(){
    int T;
    cin >> T;
    for(int c = 1; c <= T; c ++){
        int n;
        cin >> n;
        int m = 0;
        for(int i = 0; i < n; i ++){
            int s, e, l;
            cin >> s >> e >> l;
            stones[i] = {s, e, l};
            m += s;
        }
        
        sort(stones, stones + n);
        
        memset(dp, -0x3f, sizeof dp);
        dp[0] = 0;
        
        for(int i = 0; i < n; i ++){
            int s = stones[i].s, e = stones[i].e, l = stones[i].l;
            for(int j = m; j >= s; j --){
                dp[j] = max(dp[j], dp[j - s] + e - (j - s) * l);
            }
        }
        
        int res = 0;
        
        for(int i = 0; i <= m; i ++) res = max(res, dp[i]);
        
        printf("Case #%d: %d\n", c, res);
    }
    
    return 0;
}
