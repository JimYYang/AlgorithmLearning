nclude <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010, mod = 1e9 + 7;;
int dp[N], g[N];
int n, m;

int main(){
    cin >> n >> m;
    int v, w;
    memset(dp, -0x3f, sizeof dp);
    dp[0] = 0;
    g[0] = 1;
    // 本题的dp是体积恰好为j  dp求得是价值的最大值 所以需要初始化为-infinite 0初始化为0 
    // dp求得若是方案数  买书那一类题  那么全部初始化为0即可
    
    for(int i = 0; i < n; i ++){
        cin >> v >> w;
        
        for(int j = m; j >= v; j --){
            int maxv = max(dp[j], dp[j - v] + w);
            int cnt = 0;
            if(maxv == dp[j]) cnt += g[j];
            if(maxv == dp[j - v] + w) cnt += g[j - v];
            g[j] = cnt % mod;
            dp[j] = maxv;
        }
    }
    
    int res = 0, cnt = 0;
    
    for(int i = 0; i <= m; i ++) res = max(res, dp[i]);
    for(int i = 0; i <= m; i ++)
        if(res == dp[i])
            cnt = (cnt + g[i]) % mod;
            
    cout << cnt << endl;
    
    return 0;
}
