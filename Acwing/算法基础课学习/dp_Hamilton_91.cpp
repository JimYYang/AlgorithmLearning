// 状态压缩dp 数组的定义往往为  dp[i][j] 从0 - i 的状态是j  
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;

const int N = 20, M = 1 << N;

int w[N][N];
LL dp[M][N];
int n;

int main(){
    cin >> n;
    
    for(int i = 0; i < n; i ++){
        for(int j = 0; j < n; j ++){
            cin >> w[i][j];
        }
    }
    
    memset(dp, 0x3f, sizeof dp);
    dp[1][0] = 0;
    
    for(int i = 0; i < 1 << n; i ++){
        for(int j = 0; j < n; j ++){
            if(i >> j & 1){
                for(int k = 0; k < n; k ++){
                    if((i - (1 << j)) >> k & 1){
                        // 关于遍历状态子集k时，不排除节点j也可以AC的问题：
                        // 如果k == j，会重复计算g_f[i][j] = min(g_f[i][j], g_f[i - {j}][j] + g_w[j][j])，
                        // 不过由于上文已经排除了!(i >> j & 1)的情况，即g_f[i - {j}][j]的值一直保持我们初始化的最大值；
                        // 因此，只要自身->自身不存在负权边，并不影响最优解


                        dp[i][j] = min(dp[i][j], dp[i - (1 << j)][k] + w[k][j]);
                    }
                }
            }
        }
    }
    
    cout << dp[(1 << n) - 1][n - 1] << '\n';
    
    return 0;
}
