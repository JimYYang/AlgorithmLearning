// 这里化简成k是因为我们改成第二次紧接着第一次走，而不是第一次走完再走第二次，
// 可以看成两个人走就可以理解了。两个人都走k步，
// 包含了可能走到一个点，也可能没走到同一个点，这两种情况都包含了。

#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 13;
int w[N][N];
int dp[N * 2][N][N];
int n;

int main(){
    cin >> n;
    
    // 这里的行号和列号从1开始
    
    int a, b, c;
    while(cin >> a >> b >> c, a || b || c){
        w[a][b] = c;
    }
    
    // 注意第一个格子的k = 2 有的题走第一个格子也算  有的题从第一个格子开始
    
    for(int k = 2; k <= 2 * n; k ++){
        for(int i1 = 1; i1 <= k; i1 ++){
            for(int i2 = 1; i2 <= k; i2 ++){
                int j1 = k - i1, j2 = k - i2;
                
                if(j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n){
                    int sum = w[i1][j1];
                    if(i1 != i2)sum += w[i2][j2];
                    
                    int &v = dp[k][i1][i2];
                    
                    v = max(v, dp[k - 1][i1 - 1][i2 - 1] + sum);
                    v = max(v, dp[k - 1][i1][i2 - 1] + sum);
                    v = max(v, dp[k - 1][i1 - 1][i2] + sum);
                    v = max(v, dp[k - 1][i1][i2] + sum);
                }
            }
        }
    }
    
    cout << dp[2 * n][n][n] << '\n';
    
    return 0;
}
