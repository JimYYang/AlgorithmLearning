#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long LL;

const int N = 12, M = 1 << 11, K = 110;

vector<int> state, transfer[M];
LL cnt[M];
int n, k;

LL dp[N][K][M];

bool check(int s) {
    for (int i = 0; i < n; i ++) {
        if ((s >> i & 1) && (s >> (i + 1) & 1))
            return false;
    }
    return true;
}

int count(int s) {
    int res = 0;
    for (int i = 0; i < n; i ++ ) res += s >> i & 1; 
    return res;
}

int main() {
    scanf("%d%d", &n, &k);
    
    for (int i = 0; i < 1 << n; i ++ ) {
        // 检查是否有两个相邻的1 
        // 1. i & i >> 1即可
        // 2. check(i) 
        if (!(i & (i >> 1))){
            state.push_back(i);
            cnt[i] = count(i);
        }
    }
    
    for (int i = 0; i < state.size(); i ++) {
        for (int j = 0; j < state.size(); j ++) {
            int a = state[i], b = state[j];
            int tmp = a | b;
            if (!(a & b) && !(tmp & (tmp >> 1))){
                transfer[i].push_back(j);
            }
        }
    }
    
    dp[0][0][0] = 1;
    
    for (int i = 1; i <= n + 1; i ++ ) {
        for (int j = 0; j <= k; j ++) {
            for (int a = 0; a < state.size(); a ++) {
                for(auto b : transfer[a]) {
                    int x = state[a], y = state[b]; 
                    
                    int c = count(x);
                    if ( c <= j) {
                        dp[i][j][x] += dp[i - 1][j - c][y]; // 也可以写a b 因为state[a] 和 a是单映射关系
                    }
                }
            }
        }
    }
    
    printf("%lld\n", dp[n + 1][k][0]);
    
    return 0;
}




