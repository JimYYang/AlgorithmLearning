#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;
const int N = 14, M = 1 << 13, MOD = 1e8;

int dp[N][M], g[N];
vector<int> state, transfer[M];

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < m; j ++) {
            int t;
            scanf("%d", &t);
            g[i] += !t << j;
        }
    }
    
    
    for (int i = 0; i < 1 << m; i ++) {
        if ((i & (i >> 1)) == 0){
            state.push_back(i);
        }
    }
    
    for (int i = 0; i < state.size(); i ++) {
        for (int j = 0; j < state.size(); j ++) {
            int a = state[i], b = state[j];
            
            if((a & b) == 0)
                transfer[i].push_back(j); // 这里面写a b 也可以 因为下标和 a b是一一对应的
        }
    }
    
    dp[0][0] = 1;
    
    for (int i = 1; i <= n + 1; i ++) {
        for (int a = 0; a <= state.size(); a ++) {
            for (auto b : transfer[a]) {
                if ((g[i] & state[a]) == 0)
                    dp[i][state[a]] = (dp[i][state[a]] + (long long)dp[i - 1][state[b]]) % MOD;
            }
        }
    }
    
    printf("%d\n", dp[n + 1][0]);
    
    return 0;
}
